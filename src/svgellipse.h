#ifndef SVGELLIPSE_H
#define SVGELLIPSE_H

#include "svgelement.h"

class SvgEllipse : public SvgElement
{
public:
    explicit SvgEllipse(QObject *parent = nullptr);

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
    QPointF m_center;
    double m_radiusX     = 0;
    double m_radiusY     = 0;
};

#endif // SVGELLIPSE_H
