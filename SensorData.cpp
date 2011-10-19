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
  m_samples.push_back(QPointF(xpos, ypos));

  if ( m_samples.size() > m_maxSampleCnt )
  {
    m_samples.remove(0);
    m_bounds.setLeft(m_samples[0].x());
  }
  else
  {
    if ( m_bounds.left() > xpos )
      m_bounds.setLeft(xpos);
  }

  m_bounds.setWidth(m_maxSampleCnt);

  if ( m_bounds.top() > ypos )
    m_bounds.setTop(ypos);

  if ( m_bounds.height() < ypos )
     m_bounds.setHeight(ypos);
}

void SensorData::Clear()
{
  m_samples.clear();
  m_bounds.setCoords(0,0,0,0);
}
