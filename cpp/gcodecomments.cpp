#include "gcodecomments.h"

Q_GLOBAL_STATIC(GCodeComments, comments)

GCodeComments::GCodeComments()
{

}

GCodeComments *GCodeComments::instance()
{
    return comments;
}

QString GCodeComments::toString(const QString &comment)
{
    return QString("(%1)").arg(comment).toLatin1();
}
