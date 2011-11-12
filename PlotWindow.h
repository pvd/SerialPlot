#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>

#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_zoomer.h>
#include <qwt/qwt_plot_magnifier.h>
#include <qwt/qwt_plot_panner.h>
#include <qwt/qwt_legend.h>

#include "SensorCurve.h"

namespace Ui {
    class PlotWindow;
}

typedef QMap<QString, SensorCurve *> CurveMap;
typedef CurveMap::iterator           CurveMapIter;

class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();

public slots:
    void AddCurve(QString curveName, QString curveColor, int sampleCnt);
    void AddSample(QString curveName, qreal xValue, qreal yValue);

private:
    Ui::PlotWindow *   ui;

    QwtPlot *          m_plot;
    QwtPlotZoomer *    m_zoomer;
    QwtPlotMagnifier * m_magnifier;
    QwtPlotPanner *    m_panner;
    QwtLegend *        m_legend;

    CurveMap           m_curves;

private slots:
    void CurveToggled(QwtPlotItem * plotItem, bool checked);
    void ResetZoom();
};

#endif // PLOTWINDOW_H
