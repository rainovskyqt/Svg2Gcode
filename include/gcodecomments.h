#ifndef GCODECOMMENTS_H
#define GCODECOMMENTS_H

#include <QString>



class GCodeComments
{
public:
    GCodeComments(QString comment);
    QString toString();

private:
    QString m_comment;
};

#endif // GCODECOMMENTS_H
