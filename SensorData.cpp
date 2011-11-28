#include "SensorData.h"

SensorData::SensorData(const int maxSampleCnt):
  QwtSeriesData<QPointF>(),
  m_bounds(0,0,0,0),
  m_maxSampleCnt(maxSampleCnt)
{

}

QPointF SensorData::sample(size_t i) const
{
  return m_samples.at(i);
}

size_t SensorData::size() const
{
  return m_samples.size();
}

QRectF SensorData::boundingRect() const
{
  return m_bounds;
}

void SensorData::AddSample(qreal xpos, qreal ypos)
{
  // Add sample to the list of existing samples
  m_samples.push_back(QPointF(xpos, ypos));

  // check for max sample count; if limit is reached, remove the first sample
  if ( m_samples.size() > m_maxSampleCnt )
  {
    m_samples.remove(0);
  }

  m_bounds.setLeft(m_samples.first().x());
  m_bounds.setWidth(m_samples.last().x() - m_samples.first().x());

  // find the top and bottom value
  qreal bottom = 0;
  qreal top    = 0;
  for ( QVector<QPointF>::Iterator i = m_samples.begin(); i != m_samples.end(); i++ )
  {
    bottom = qMax(bottom, i->y());
    top    = qMin(top, i->y());
  }

  m_bounds.setBottom(bottom);
  m_bounds.setTop(top);
}

void SensorData::Clear()
{
  m_samples.clear();
  m_bounds.setCoords(0,0,0,0);
}
