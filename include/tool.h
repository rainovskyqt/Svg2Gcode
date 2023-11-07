#ifndef TOOL_H
#define TOOL_H

#include <QString>

class Tool
{
public:

    enum ToolType{
        Extruder
    };

    Tool(ToolType newToolType, int newFeedRate);


    int feedRate() const;
    void setFeedRate(int newFeedRate);

    int toolType() const;
    void setToolType(ToolType newToolType);

    QByteArray move(int x, int y, int z);
    QByteArray moveAndExtrude(double x, double y, double z, double extrudeVolume);
    QByteArray pauseSec(int seconds);
    QByteArray paudeMillsec(int millsec);

    QByteArray headUp(int mm);
    QByteArray headDown(int mm);
protected:
    int m_feedRate;
    int m_toolType;

};

#endif // TOOL_H
