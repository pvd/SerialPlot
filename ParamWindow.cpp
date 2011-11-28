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
  DynamicFloatParam * param = new DynamicFloatParam(paramName, minValue, maxValue, value);
  connect(param, SIGNAL(valueChanged(QString, QString)),
          this, SIGNAL(ParamChangedValue(QString, QString)));

  ui->horizontalLayout->addWidget(param);
}

