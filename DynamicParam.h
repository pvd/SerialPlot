#ifndef DYNAMICPARAM_H
#define DYNAMICPARAM_H

#include <QFrame>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>

class DynamicParam: public QFrame
{
  Q_OBJECT
protected:
  QString m_name;
public:
  DynamicParam(const QString & name, QWidget *parent = 0): QFrame(parent), m_name(name) {}

  QString name() { return m_name; }
signals:
  virtual void valueChanged(QString name, QString value) = 0;
};


// DynamicFloatParameter
class DynamicFloatParam : public DynamicParam
{
    Q_OBJECT
protected:
    QLabel *         m_lblCaption;
    QDoubleSpinBox * m_edtValue;
    QPushButton *    m_btnApply;

public:
    DynamicFloatParam(const QString & name, const double minValue,
                      const double maxValue, const double value, QWidget *parent = 0);

    double value() { return m_edtValue->value(); }
signals:
    void valueChanged(QString name, QString value);

public slots:
    void apply();
};

// DynamicIntParameter
class DynamicIntParam: public DynamicParam
{
  Q_OBJECT
protected:
  QLabel *       m_lblCaption;
  QSpinBox *     m_edtValue;
  QPushButton *  m_btnApply;

public:
  DynamicIntParam(const QString & name, const int minValue,
                  const int maxValue, const int value, QWidget *parent = 0);

  int value() { return m_edtValue->value(); }
signals:
  void valueChanged(QString name, QString value);

public slots:
  void apply();
};


#endif // DYNPARAM_H
