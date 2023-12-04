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
    void parsing(QXmlStreamReader* reader, SvgTranformStack stack) override;

    /*!
    * \brief Строки gcode
    * \return Строки gcode сформированне по свойствам элемента
    */
    QStringList gcode() override;
};

#endif // SVGEMPTYELEMENT_H
