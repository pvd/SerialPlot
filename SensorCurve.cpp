#include "SensorCurve.h"

SensorCurve::SensorCurve(const QwtText & title, const QString & color, const size_t sampleCnt):
  QwtPlotCurve(title)
{
  m_sampleData = new SensorData(sampleCnt);

  setPen(QPen(color));
  setData(m_sampleData);
}

bool SensorCurve::operator==(const SensorCurve &rhs) const
{
  return this->title() == rhs.title();
}

void SensorCurve::AddSample(qreal xpos, qreal ypos)
{
  m_sampleData->AddSample(xpos, ypos);
}

void SensorCurve::Reset()
{
  m_sampleData->Clear();
}
