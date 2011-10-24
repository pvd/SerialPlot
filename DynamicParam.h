#ifndef DYNAMICPARAM_H
#define DYNAMICPARAM_H

#include <QFrame>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>

class DynamicParam : public QFrame
{
    Q_OBJECT
protected:
    QString          m_name;
    QLabel *         m_lblCaption;
    QDoubleSpinBox * m_edtValue;
    QPushButton *    m_btnApply;

public:
    DynamicParam(const QString & name, QWidget *parent = 0);

    QString name() { return m_name; }
signals:
    void valueChanged(DynamicParam * param);

public slots:
    void apply();
};

#endif // DYNPARAM_H
