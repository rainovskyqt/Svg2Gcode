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
