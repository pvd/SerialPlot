#include "DynamicParam.h"
#include <QVBoxLayout>

DynamicParam::DynamicParam(const QString & name, const double value, QWidget *parent) :
  QFrame(parent), m_name(name)
{
  QVBoxLayout *vbox = new QVBoxLayout(this);

  m_lblCaption = new QLabel(this);
  m_edtValue   = new QDoubleSpinBox(this);
  m_btnApply   = new QPushButton(this);

  m_edtValue->setValue(value);
  m_lblCaption->setText(name);
  m_btnApply->setText("Apply");

  connect(m_btnApply, SIGNAL(clicked()), this, SLOT(apply()));

  vbox->addWidget(m_lblCaption);
  vbox->addWidget(m_edtValue);
  vbox->addWidget(m_btnApply);

  setLayout(vbox);
}

void DynamicParam::apply()
{
  emit valueChanged(this);
}


