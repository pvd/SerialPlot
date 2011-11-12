#include "PlotWindow.h"
#include "ui_PlotWindow.h"

PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotWindow)
{
    ui->setupUi(this);
    m_plot       = new QwtPlot(this);
  //  m_zoomer     = new QwtPlotZoomer(m_plot->canvas());
  //  m_magnifier  = new QwtPlotMagnifier(m_plot->canvas());
  //  m_panner     = new QwtPlotPanner(m_plot->canvas());

    m_legend     = new QwtLegend();
    m_legend->setItemMode(QwtLegend::CheckableItem);
    m_plot->insertLegend(m_legend, QwtPlot::RightLegend);

    this->setCentralWidget(m_plot);

    connect(m_plot, SIGNAL(legendChecked(QwtPlotItem*,bool)), this, SLOT(CurveToggled(QwtPlotItem*,bool)));
    connect(ui->actionResetZoom, SIGNAL(triggered()), this, SLOT(ResetZoom()));
}

PlotWindow::~PlotWindow()
{
    delete m_plot;
    delete ui;
}

void PlotWindow::CurveToggled(QwtPlotItem * plotItem, bool checked)
{
  plotItem->setVisible(checked);
  m_plot->replot();
}

void PlotWindow::ResetZoom()
{
  m_plot->setAxisAutoScale(0);
  m_plot->setAxisAutoScale(1);
  m_plot->setAxisAutoScale(2);
  m_plot->setAxisAutoScale(3);
  m_plot->replot();
}

void PlotWindow::AddCurve(QString curveName, QString curveColor, int sampleCnt)
{
  if ( m_curves.contains(curveName) )
  {
    qDebug("Curve with name already exists");
    CurveMapIter iter = m_curves.find(curveName);
    iter.value()->Reset();

    m_plot->replot();

    return;
  }

  SensorCurve * newCurve = new SensorCurve(curveName, curveColor, sampleCnt);
  m_curves.insert(curveName, newCurve);
  newCurve->attach(m_plot);
}

void PlotWindow::AddSample(QString curveName, qreal xValue, qreal yValue)
{
  CurveMapIter iter = m_curves.find(curveName);
  if ( iter == m_curves.end() )
  {
    qDebug("Unknown curve name");
    return;
  }

  iter.value()->AddSample(xValue, yValue);
  m_plot->replot();
}
