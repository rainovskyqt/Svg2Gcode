#ifndef SVGRECT_H
#define SVGRECT_H

#include "svgelement.h"

class SvgRect : public SvgElement
{
public:
    explicit SvgRect(QObject *parent = nullptr);

    /*!
    * \brief Разбор данных элемента
    *
    * Разбор данных элемента, основная функция котрая рзбирает переданные параметры по свойствам класса объекта
    */
    void parsing(QXmlStreamReader* reader, SvgTranformStack stack, SvgStyle style) override;

    /*!
    * \brief Строка gcode
    * \return Строка gcode сформированная по свойствам элемента
    */
    QString gcode(GCodeTool *gCodeTool) override;

private:
    QPointF m_start;
    double m_width;
    double m_height;
    double m_radiusX;
    double m_radiusY;
};

#endif // SVGRECT_H
