#include "LogWindow.h"
#include "ui_LogWindow.h"

LogWindow::LogWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogWindow)
{
  ui->setupUi(this);

  connect(ui->actionClear, SIGNAL(triggered()), this, SLOT(Clear()));
}

LogWindow::~LogWindow()
{
  delete ui;
}

void LogWindow::AddMessage(const QString & msg)
{
  if ( ui->listWidget->count() > 1000 )
  {
    delete ui->listWidget->item(0);
  }

  ui->listWidget->addItem(msg);
  ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
}

void LogWindow::Clear()
{
  ui->listWidget->clear();
}

