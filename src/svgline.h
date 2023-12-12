#ifndef SVGLINE_H
#define SVGLINE_H

#include "svgelement.h"

class SvgLine : public SvgElement
{
public:
    explicit SvgLine(bool relatively = false, QObject *parent = nullptr);
    explicit SvgLine(QPointF start, QPointF end, bool relatively = false, QObject *parent = nullptr);

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
    bool m_relatively;      ///< Флаг что конечные координаты линии являются относительными

    /*!
    * \brief Количество проходов
    * \return Количество проходов по линии
    *
    * Количество проходов по линии определяется толщиной линии в svg файле и диаметром сопла
    */
    int getPassedCount(double nozzleDiameter);


    /*!
    * \brief Конечные точки проходов печати
    * \return Конечные точки проходов печати
    *
    * Конечные точки проходов печати определяются смещением от центральной точки указанной в svg файле, и количеством проходов
    * смещение по оси х определяется как offset_x=distance⋅cos(angle), где distance⋅- диаметр сопла
    * смещение по оси y определяется как offset_x=distance⋅sin(angle)
    */
    QVector<QPointF> getPassedPoints(QPointF start, QPointF end, double nozzleDiameter);

    QPointF getEndPoint(QPointF start, QPointF end, bool relatively);
};

#endif // SVGLINE_H
