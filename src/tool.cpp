#include "tool.h"

Tool::Tool()
{

}

int Tool::feedRate() const
{
    return m_feedRate;
}

void Tool::setFeedRate(int newFeedRate)
{
    m_feedRate = newFeedRate;
}

int Tool::extruderTemp() const
{
    return m_extruderTemp;
}

void Tool::setExtruderTemp(int newExtruderTemp)
{
    m_extruderTemp = newExtruderTemp;
}

int Tool::platformTemp() const
{
    return m_platformTemp;
}

void Tool::setPlatformTemp(int newPlatformTemp)
{
    m_platformTemp = newPlatformTemp;
}

double Tool::nozzleDiameter() const
{
    return m_nozzleDiameter;
}

void Tool::setNozzleDiameter(double newNozzleDiameter)
{
    m_nozzleDiameter = newNozzleDiameter;
}

double Tool::layerHeight() const
{
    return m_layerHeight;
}

void Tool::setLayerHeight(double newLayerHeight)
{
    m_layerHeight = newLayerHeight;
}
