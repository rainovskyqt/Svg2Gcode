#ifndef GCODECOMMENTS_H
#define GCODECOMMENTS_H

/*!
 *  \brief Комментарий в gcode
 */

#include <QString>


class GCodeComments
{
public:

    GCodeComments();

    /*!
    *  \brief Комментарай
    *  \param comment Текст комментария
    *  \return Текст комментария, отформатированный в соответствии с требованиями gcode
    */
    QString toString(const QString &comment);

private:

};

#endif // GCODECOMMENTS_H
