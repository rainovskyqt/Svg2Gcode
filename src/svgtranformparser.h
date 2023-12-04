#ifndef SVGTRANFORMPARSER_H
#define SVGTRANFORMPARSER_H

/*!
 * \brief Парсес транформаций
 *
 */

#include "svgtranformstack.h"

struct Command
{
public:

    explicit Command(const QString &command, const QString &value);

    /*!
     * \brief Параметры команды транформации
     * \return Параметры команды транформации
     */
    QString value() const;

    /*!
     * \brief Команда транформации
     * \return Команда транформации
     */
    QString command() const;

private:
    /*!
     * \brief Команда транформации
     */
    QString m_command;

    /*!
     * \brief Параметры команды транформации
     */
    QString m_value;
};

class SvgTranformParser
{
public:
    /*!
     * \brief Парсес транформаций
     * \param command Команда транформации
     * \param value Параметры команды транформации
     */
    SvgTranformParser();

    /*!
     * \brief основная функция разбора транформации
     * \param input Строка содержащия команду и параметры
     * \param trans Существующий стак
     *
     * Разбирает транформацию на команду и параметры, добавляет в существующий стак транформаций
     */
    SvgTranformStack parse(const QString &input, const SvgTranformStack trans);

private:
    /*!
     * \brief Все команды в строке
     * \param input Строка содержащия все команды
     *
     * Разбирает строку в массив строк, каждая из которых представляет из себя команду со значением
     */
    QStringList allCommandsFromString(const QString &input);

    /*!
     * \brief Команда в строке
     * \param input Строка содержащия команду и параметры
     *
     * Разбирает строку в объект класса #Command
     */
    Command commandFromString(const QString &input);

    /*!
     * \brief Добавление коанды
     * \param comm input Команда и параметры
     * \param stack копия существующего стака
     *
     * Добавляет команду к стаку существующих команд
     */
    void addComand(Command comm, SvgTranformStack* stack);
};

#endif // SVGTRANFORMPARSER_H
