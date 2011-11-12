#include "ParamWindow.h"
#include "ui_ParamWindow.h"

ParamWindow::ParamWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParamWindow)
{
    ui->setupUi(this);
}

ParamWindow::~ParamWindow()
{
    delete ui;
}

void ParamWindow::AddParam(QString paramName, double minValue, double maxValue, double value )
{
  // Create a new dynamic parameter widget and add this to the window
  // the ValueChanged signal is forwarded to the ParamChangedValue signal of this window
  DynamicParam * param = new DynamicParam(paramName, minValue, maxValue, value);
  connect(param, SIGNAL(valueChanged(DynamicParam*)), this, SIGNAL(ParamChangedValue(DynamicParam*)));

  ui->horizontalLayout->addWidget(param);
}


