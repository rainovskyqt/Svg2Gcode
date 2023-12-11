#ifndef SVGCIRCLE_H
#define SVGCIRCLE_H

#include "svgelement.h"

class SvgCircle : public SvgElement
{
public:
    explicit SvgCircle(QObject *parent = nullptr);

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
    double m_radius;
};

#endif // SVGCIRCLE_H
