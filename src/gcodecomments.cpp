#include "gcodecomments.h"

GCodeComments::GCodeComments()
{

}

QString GCodeComments::toString(const QString &comment)
{
    return QString("(%1)\n").arg(comment).toLatin1();
}
