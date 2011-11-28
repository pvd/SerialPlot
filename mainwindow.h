#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qextserialport.h>
#include "PlotWindow.h"
#include "ParamWindow.h"
#include "LogWindow.h"

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
    LogWindow *        m_logWindow;

private slots:
    void OpenPort();
    void ClosePort();
    void DataAvailable();
    void ParamChangedValue(QString name, QString value);
};

#endif // MAINWINDOW_H
