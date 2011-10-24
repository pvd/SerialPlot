#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_zoomer.h>
#include <qwt/qwt_plot_magnifier.h>
#include <qwt/qwt_plot_panner.h>
#include <qwt/qwt_legend.h>
#include <qextserialport.h>
#include "SensorCurve.h"
#include <DynamicParam.h>

namespace Ui {
    class MainWindow;
}

typedef QMap<QString, SensorCurve *> CurveMap;
typedef CurveMap::iterator           CurveMapIter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *   ui;
    QwtPlot *          m_plot;
    QwtPlotZoomer *    m_zoomer;
    QwtPlotMagnifier * m_magnifier;
    QwtPlotPanner *    m_panner;
    QwtLegend *        m_legend;
    QextSerialPort *   m_serialPort;

    CurveMap           m_curves;

    void AddCurve(QString curveName, QString curveColor, int sampleCnt);
    void AddSample(QString curveName, qreal xValue, qreal yValue);

public slots:
    void OpenPort();
    void ClosePort();
    void DataAvailable();
    void CurveToggled(QwtPlotItem * plotItem, bool checked);

    void ResetZoom();
    void TestCreatePlot();
    void TestAddSamples();
    void TestAddKnob();

    void ParamChangedValue(DynamicParam * param);

};

#endif // MAINWINDOW_H
