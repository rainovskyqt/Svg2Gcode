#ifndef SVGPOLYGON_H
#define SVGPOLYGON_H

#include "svgelement.h"

class SvgPolygon : public SvgElement
{
public:
    explicit SvgPolygon(QObject *parent = nullptr);

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
};

#endif // SVGPOLYGON_H
