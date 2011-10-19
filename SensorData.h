#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <qwt_series_data.h>

class SensorData: public QwtSeriesData<QPointF>
{
private:
  QVector<QPointF> m_samples;
  QRectF           m_bounds;
  int              m_maxSampleCnt;
public:
  SensorData(const int maxSampleCnt = 1000);

  virtual QPointF sample(size_t i) const;
  virtual size_t size() const;
  virtual QRectF boundingRect() const;

  void AddSample(qreal xPos, qreal yPos);
  void Clear();
};

#endif // SENSORDATA_H
