#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qextserialenumerator.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  m_plot       = new QwtPlot(this);
  m_zoomer     = new QwtPlotZoomer(m_plot->canvas());
//  m_magnifier  = new QwtPlotMagnifier(m_plot->canvas());
//  m_panner     = new QwtPlotPanner(m_plot->canvas());
  m_legend     = new QwtLegend();
  m_serialPort = new QextSerialPort(QextSerialPort::EventDriven);

  m_legend->setItemMode(QwtLegend::CheckableItem);
  m_plot->insertLegend(m_legend, QwtPlot::RightLegend);
  ui->layoutPlot->addWidget(m_plot);

  QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
  for (int i = 0; i < ports.size(); i++)
  {
    ui->cmbPorts->addItem(ports.at(i).portName);
  }

  connect(ui->btnOpenPort, SIGNAL(clicked()), this, SLOT(OpenPort()));
  connect(ui->btnClosePort, SIGNAL(clicked()), this, SLOT(ClosePort()));
  connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(DataAvailable()));
  connect(ui->btnResetZoom, SIGNAL(clicked()), this, SLOT(ResetZoom()));
  connect(m_plot, SIGNAL(legendChecked(QwtPlotItem*,bool)), this, SLOT(CurveToggled(QwtPlotItem*,bool)));

  connect(ui->btnCreatePlot, SIGNAL(clicked()), this, SLOT(TestCreatePlot()));
  connect(ui->btnTest, SIGNAL(clicked()), this, SLOT(TestAddSamples()));
}

MainWindow::~MainWindow()
{
//  delete m_panner;
//  delete m_magnifier;
  delete m_zoomer;
  delete m_legend;
  delete m_plot;
  delete ui;
}

void MainWindow::OpenPort()
{
  m_serialPort->close();

  m_serialPort->setPortName(ui->cmbPorts->itemText(ui->cmbPorts->currentIndex()));
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
    qDebug("Received line with invalid nr of items: %d", lineItems.count());
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

    AddCurve(args.at(0), args.at(1), args.at(2).toInt());
    m_plot->replot();
  }
  else if ( cmd == "sample" )
  {
    // sample: curvename, x, y
    if ( args.size() != 3 )
    {
      qDebug("Invalid number of arguments for sample command");
      return;
    }

    AddSample(args.at(0), args.at(1).toDouble(), args.at(2).toDouble());
    m_plot->replot();
  }
  else if ( cmd == "param" )
  {
    // param: paramName, minValue, maxValue, value
    if ( args.size() != 4 )
    {
      qDebug("Invalid number of arguments for param command");
      return;
    }

    AddParam(args.at(0), args.at(1).toDouble(), args.at(2).toDouble(), args.at(3).toDouble());
  }
  else
  {
    qDebug("Invalid command");
  }
}

void MainWindow::AddCurve(QString curveName, QString curveColor, int sampleCnt)
{
  if ( m_curves.contains(curveName) )
  {
    qDebug("Curve with name already exists");
    CurveMapIter iter = m_curves.find(curveName);
    iter.value()->Reset();

    m_plot->replot();

    return;
  }

  SensorCurve * newCurve = new SensorCurve(curveName, curveColor, sampleCnt);
  m_curves.insert(curveName, newCurve);
  newCurve->attach(m_plot);
}

void MainWindow::AddSample(QString curveName, qreal xValue, qreal yValue)
{
  CurveMapIter iter = m_curves.find(curveName);
  if ( iter == m_curves.end() )
  {
    qDebug("Unknown curve name");
    return;
  }

  iter.value()->AddSample(xValue, yValue);
  m_plot->replot();
}

void MainWindow::AddParam(QString paramName, double minValue, double maxValue, double value )
{
  DynamicParam * param = new DynamicParam(paramName, minValue, maxValue, value);
  connect(param, SIGNAL(valueChanged(DynamicParam*)), this, SLOT(ParamChangedValue(DynamicParam*)));

  ui->layoutParams->addWidget(param);
}

void MainWindow::CurveToggled(QwtPlotItem * plotItem, bool checked)
{
  plotItem->setVisible(checked);
  m_plot->replot();
}

void MainWindow::ResetZoom()
{
  m_plot->setAxisAutoScale(0);
  m_plot->setAxisAutoScale(1);
  m_plot->setAxisAutoScale(2);
  m_plot->setAxisAutoScale(3);
  m_plot->replot();
}

void MainWindow::ParamChangedValue(DynamicParam * param)
{
  QString paramStr = QString("param:%1,%2\n").arg(param->name()).arg(param->value());

  m_serialPort->write(paramStr.toAscii().constData());
}

//*************** DEBUG ********************
void MainWindow::TestCreatePlot()
{
  AddCurve("test", "blue", 100);
  AddCurve("test2", "red", 100);
}

void MainWindow::TestAddSamples()
{
  static int sample = 0;
  static int offset = 1;

  for ( int i = 0; i < 10; i++ )
  {
    AddSample("test", sample, sin(i) + offset);
    AddSample("test2", sample, cos(i) + offset);
    m_plot->replot();

    sample += 100;
  }

//  offset = offset + 1;
}

void MainWindow::TestAddKnob()
{
  static int i = 1;

  DynamicParam * param = new DynamicParam("test", 0, 10, i);
  connect(param, SIGNAL(valueChanged(DynamicParam*)), this, SLOT(ParamChangedValue(DynamicParam*)));

  ui->layoutParams->addWidget(param);
  i++;
}

