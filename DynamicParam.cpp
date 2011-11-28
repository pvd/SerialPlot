#include "DynamicParam.h"
#include <QVBoxLayout>

//*****************************************************************************
// DynamicFloatParam
DynamicFloatParam::DynamicFloatParam(const QString & name, const double minValue,
                                     const double maxValue, const double value, QWidget *parent):
                   DynamicParam(name, parent)
{
  QVBoxLayout *vbox = new QVBoxLayout(this);

  m_lblCaption = new QLabel(this);
  m_edtValue   = new QDoubleSpinBox(this);
  m_btnApply   = new QPushButton(this);

  m_edtValue->setDecimals(6);
  m_edtValue->setMinimum(minValue);
  m_edtValue->setMaximum(maxValue);
  m_edtValue->setValue(value);

  m_lblCaption->setText(name);
  m_btnApply->setText("Apply");

  connect(m_btnApply, SIGNAL(clicked()), this, SLOT(apply()));

  vbox->addWidget(m_lblCaption);
  vbox->addWidget(m_edtValue);
  vbox->addWidget(m_btnApply);

  setLayout(vbox);
}

void DynamicFloatParam::apply()
{
  emit valueChanged(m_name, QString::number(m_edtValue->value()));
}

//*****************************************************************************
// DynamicIntParam
DynamicIntParam::DynamicIntParam(const QString & name, const int minValue,
                                 const int maxValue, const int value, QWidget *parent):
                 DynamicParam(name, parent)
{
  QVBoxLayout *vbox = new QVBoxLayout(this);

  m_lblCaption = new QLabel(this);
  m_edtValue   = new QSpinBox(this);
  m_btnApply   = new QPushButton(this);

  m_edtValue->setMinimum(minValue);
  m_edtValue->setMaximum(maxValue);
  m_edtValue->setValue(value);

  m_lblCaption->setText(name);
  m_btnApply->setText("Apply");

  connect(m_btnApply, SIGNAL(clicked()), this, SLOT(apply()));

  vbox->addWidget(m_lblCaption);
  vbox->addWidget(m_edtValue);
  vbox->addWidget(m_btnApply);

  setLayout(vbox);
}

void DynamicIntParam::apply()
{
  emit valueChanged(m_name, QString::number(m_edtValue->value()));
}
