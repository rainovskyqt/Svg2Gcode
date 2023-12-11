#ifndef SVGEMPTYELEMENT_H
#define SVGEMPTYELEMENT_H

/*!
 * \brief Пустой класс, используется как заглушка для необрабатываемых элементов
 */

#include "svgelement.h"

class SvgEmptyElement : public SvgElement
{
public:
    explicit SvgEmptyElement(QObject *parent = nullptr);

    /*!
    * \brief Разбор данных элемента
    *
    * Разбор данных элемента, основная функция котрая рзбирает переданные параметры по свойствам класса объекта
    */
    void parsing(QXmlStreamReader* reader, SvgTranformStack stack, SvgStyle style);

    /*!
    * \brief Строка gcode
    * \return Строка gcode сформированная по свойствам элемента
    */
    QString gcode(GCodeTool *gCodeTool) override;
};

#endif // SVGEMPTYELEMENT_H
