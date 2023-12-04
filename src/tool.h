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

    QString move(int x, int y, int z);
    QString moveAndExtrude(double x, double y, double z, double extrudeVolume);
    QString pauseSec(int seconds);
    QString pauseMillsec(int millsec);

    QString headUp(int mm);
    QString headDown(int mm);

protected:
    int m_feedRate;
    int m_toolType;

};

#endif // TOOL_H
