#ifndef TOOL_H
#define TOOL_H


class Tool
{
public:
    enum ToolType{
        Pen,
        Laser
    };

    Tool(ToolType newToolType, int newFeedRate);


    int feedRate() const;
    void setFeedRate(int newFeedRate);

    int toolType() const;
    void setToolType(ToolType newToolType);

protected:
    int m_feedRate;
    int m_toolType;
};

#endif // TOOL_H
