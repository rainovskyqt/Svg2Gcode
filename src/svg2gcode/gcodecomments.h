#ifndef GCODECOMMENTS_H
#define GCODECOMMENTS_H

#include <QString>


class GCodeComments
{
public:
    GCodeComments();
    static GCodeComments *instance();

    QString toString(const QString &comment);

private:

};

#endif // GCODECOMMENTS_H
