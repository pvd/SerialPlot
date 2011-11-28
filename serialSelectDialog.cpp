#include "serialSelectDialog.h"
#include "ui_serialSelectDialog.h"
#include "qextserialenumerator.h"
#include <QDebug>

SerialSelectDialog::SerialSelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialSelectDialog)
{
    ui->setupUi(this);

    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    for (int i = 0; i < ports.size(); i++)
    {
      ui->listWidget->addItem(ports.at(i).portName);
    }

    connect(ui->listWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doubleClicked(QModelIndex)));
}

SerialSelectDialog::~SerialSelectDialog()
{
    delete ui;
}

QString SerialSelectDialog::SelectedPort()
{
  return ui->listWidget->currentItem()->text();
}

void SerialSelectDialog::doubleClicked(QModelIndex index)
{
  accept();
}


