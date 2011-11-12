#ifndef PARAMWINDOW_H
#define PARAMWINDOW_H

#include <QMainWindow>
#include "DynamicParam.h"

namespace Ui {
    class ParamWindow;
}

class ParamWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ParamWindow(QWidget *parent = 0);
    ~ParamWindow();

public slots:
    void AddParam(QString paramName, double minValue, double maxValue, double value);

signals:
      void ParamChangedValue(DynamicParam * param);

private:
    Ui::ParamWindow *ui;
};

#endif // PARAMWINDOW_H
