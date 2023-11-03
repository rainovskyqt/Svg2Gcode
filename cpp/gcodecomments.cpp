#include "../include/gcodecomments.h"

GCodeComments::GCodeComments(QString comment)
{
    m_comment = comment;
}

QString GCodeComments::toString()
{
    return QString("(%1)").arg(m_comment);
}
