#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qextserialport.h>
#include "PlotWindow.h"
#include "ParamWindow.h"

namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *   ui;
    QextSerialPort *   m_serialPort;
    PlotWindow *       m_plotWindow;
    ParamWindow *      m_paramWindow;

private slots:
    void OpenPort();
    void ClosePort();
    void DataAvailable();
    void ParamChangedValue(DynamicParam * param);
};

#endif // MAINWINDOW_H
