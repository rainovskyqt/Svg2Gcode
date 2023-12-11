#ifndef SVGLINE_H
#define SVGLINE_H

#include "svgelement.h"

class SvgLine : public SvgElement
{
public:
    explicit SvgLine(QObject *parent = nullptr);

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
    QPointF m_start;    ///<Стартовые координаты
    QPointF m_end;      ///<Конечные координаты


};

#endif // SVGLINE_H
