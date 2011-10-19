#ifndef SENSORCURVE_H
#define SENSORCURVE_H

#include <qwt_plot_curve.h>
#include <SensorData.h>

class SensorCurve: public QwtPlotCurve
{
private:
  SensorData * m_sampleData;
public:
  SensorCurve(const QwtText & title, const QString & color, const size_t sampleCnt = 1000);

  bool operator==(const SensorCurve &rhs) const;
  void AddSample(qreal xpos, qreal ypos);
  void Reset();
};

#endif // SENSORCURVE_H
