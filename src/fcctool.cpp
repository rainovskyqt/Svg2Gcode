#include "fcctool.h"

FCCTool::FCCTool()
{

}

int FCCTool::feedRate() const
{
    return m_feedRate;
}

void FCCTool::setFeedRate(int newFeedRate)
{
    m_feedRate = newFeedRate;
}

int FCCTool::extruderTemp() const
{
    return m_extruderTemp;
}

void FCCTool::setExtruderTemp(int newExtruderTemp)
{
    m_extruderTemp = newExtruderTemp;
}

int FCCTool::platformTemp() const
{
    return m_platformTemp;
}

void FCCTool::setPlatformTemp(int newPlatformTemp)
{
    m_platformTemp = newPlatformTemp;
}

double FCCTool::nozzleDiameter() const
{
    return m_nozzleDiameter;
}

void FCCTool::setNozzleDiameter(double newNozzleDiameter)
{
    m_nozzleDiameter = newNozzleDiameter;
}

double FCCTool::layerHeight() const
{
    return m_layerHeight;
}

void FCCTool::setLayerHeight(double newLayerHeight)
{
    m_layerHeight = newLayerHeight;
}

double FCCTool::extrudeVolume() const
{
    return m_extrudeVolume;
}

void FCCTool::setExtrudeVolume(double newExtrudeVolume)
{
    m_extrudeVolume = newExtrudeVolume;
}
