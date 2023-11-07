#include "tool.h"

Tool::Tool(ToolType newToolType, int newFeedRate)
{
    m_toolType = newToolType;
    m_feedRate = newFeedRate;

}

int Tool::feedRate() const
{
    return m_feedRate;
}

void Tool::setFeedRate(int newFeedRate)
{
    m_feedRate = newFeedRate;
}

int Tool::toolType() const
{
    return m_toolType;
}

void Tool::setToolType(ToolType newToolType)
{
    m_toolType = newToolType;
}

QByteArray Tool::move(int x, int y, int z)
{
    return QString("GO X%1 Y%2 Z%3")
            .arg(x)
            .arg(y)
            .arg(z)
            .toLatin1();
}

QByteArray Tool::moveAndExtrude(double x, double y, double z, double extrudeVolume)
{
    return QString("G1 X%1 Y%2 Z%3 E%4")
            .arg(x)
            .arg(y)
            .arg(z)
            .arg(extrudeVolume)
            .toLatin1();
}

QByteArray Tool::pauseSec(int seconds)
{
    return QString("G4 S%1")
            .arg(seconds)
            .toLatin1();
}

QByteArray Tool::paudeMillsec(int millsec)
{
    return QString("G4 P%1")
            .arg(millsec)
            .toLatin1();
}

QByteArray Tool::headUp(int mm)
{
    return move(0, 0, mm);
}

QByteArray Tool::headDown(int mm)
{
    return move(0, 0, -mm);
}
