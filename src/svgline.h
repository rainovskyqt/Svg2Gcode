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
    void parsing(QXmlStreamReader* reader, SvgTranformStack stack) override;

    /*!
    * \brief Строка gcode
    * \return Строка gcode сформированная по свойствам элемента
    */
    QString gcode() override;

    /*!
    * \brief Начальная точка
    * \return Начальная точка линии
    *
    * Соответствует параметру x1 и y1
    */
    QPointF start() const;


    /*!
    * \brief Конечная точка
    * \return Конечная точка линии
    *
    * Соответствует параметру x2 и y2
    */
    QPointF end() const;

private:
    QPointF m_start;
    QPointF m_end;
};

#endif // SVGLINE_H
