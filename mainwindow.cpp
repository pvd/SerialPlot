#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QMdiArea>
#include <qextserialenumerator.h>

#include "serialSelectDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  m_plotWindow = new PlotWindow(this);
  ui->mdiArea->addSubWindow(m_plotWindow);
  m_plotWindow->setGeometry(0, 0, 400, 300);

  m_paramWindow = new ParamWindow(this);
  ui->mdiArea->addSubWindow(m_paramWindow);
  connect(m_paramWindow, SIGNAL(ParamChangedValue(QString, QString)),
          this, SLOT(ParamChangedValue(QString, QString)));

  m_logWindow = new LogWindow(this);
  ui->mdiArea->addSubWindow(m_logWindow);

  connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(OpenPort()));
  connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(ClosePort()));

  // Add the serial port, incomming data is handled by DataAvailable
  m_serialPort = new QextSerialPort(QextSerialPort::EventDriven);
  connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(DataAvailable()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::OpenPort()
{
  // Show the serial port selection dialog
  SerialSelectDialog * serialSelectDialog = new SerialSelectDialog(this);
  if ( serialSelectDialog->exec() == QDialog::Accepted )
  {
    m_serialPort->close();

    m_serialPort->setPortName(serialSelectDialog->SelectedPort());
    m_serialPort->setBaudRate(BAUD115200);
    m_serialPort->setDataBits(DATA_8);
    m_serialPort->setStopBits(STOP_1);
    m_serialPort->setParity(PAR_NONE);
    m_serialPort->setFlowControl(FLOW_OFF);

    if ( m_serialPort->open(QIODevice::ReadWrite) == false )
    {
      QMessageBox msgBox;
      msgBox.setText("Failed to open serial port");
      msgBox.exec();
    }
  }

  delete serialSelectDialog;
}

void MainWindow::ClosePort()
{
  m_serialPort->close();
}

void MainWindow::DataAvailable()
{
  // command: arg1, arg2, arg3, ....
  QString line = m_serialPort->readLine();
  line.remove('\n');
  line.remove('\r');
  QStringList lineItems = line.split(":", QString::SkipEmptyParts);

  if ( lineItems.count() != 2 )
  {
    m_logWindow->AddMessage(line);
    return;
  }

  QString cmd = lineItems[0];
  QStringList args = lineItems[1].split(",", QString::SkipEmptyParts);

  if ( cmd == "curve" )
  {
    // curve: name, color, sampleCnt
    if ( args.size() != 3 )
    {
      qDebug("Invalid number of arguments for curve command");
      return;
    }

    m_plotWindow->AddCurve(args.at(0), args.at(1), args.at(2).toInt());
  }
  else if ( cmd == "sample" )
  {
    // sample: curvename, x, y
    if ( args.size() != 3 )
    {
      qDebug("Invalid number of arguments for sample command");
      return;
    }

    m_plotWindow->AddSample(args.at(0), args.at(1).toDouble(), args.at(2).toDouble());
  }
  else if ( cmd == "param" )
  {
    // param: paramName, minValue, maxValue, value
    if ( args.size() != 4 )
    {
      qDebug("Invalid number of arguments for param command");
      return;
    }

    m_paramWindow->AddParam(args.at(0), args.at(1).toDouble(), args.at(2).toDouble(), args.at(3).toDouble());

  }
  else
  {
    m_logWindow->AddMessage(line);
  }
}

void MainWindow::ParamChangedValue(QString name, QString value)
{
  QString paramStr = QString("param:%1,%2\n").arg(name).arg(value);

  m_serialPort->write(paramStr.toAscii().constData());
}

