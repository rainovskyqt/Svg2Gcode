
#ifndef SVGFILEDATA_H
#define SVGFILEDATA_H

/*!
 * \brief Класс для сохранения данных о файле
 */
#include "svgelement.h"

class SvgFileData : public SvgElement
{
    Q_OBJECT

public:
    SvgFileData();

    /*!
    * \brief Имя файла
    * \return Имя файла парсинг которого производится
    */
    const QString &docname() const;

    /*!
    * \brief Установить имя файла
    * \param newDocname Устанавливаем имя файла парсинг которого производится
    */
    void setDocname(const QString &newDocname);

    /*!
    * \brief Версия Inkscape
    * \return Версия Inkscape
    *
    * Версия редактора Inkscape, если он применялся для создания файла
    */
    const QString &inkscapeVersion() const;

    /*!
    * \brief Версия Inkscape
    * \param Версия Inkscape
    *
    * Версия редактора Inkscape, если он применялся для создания файла
    */
    void setInkscape_version(const QString &newInkscapeVersion);

    /*!
    * \brief Разбор данных элемента
    *
    * Разбор данных элемента, основная функция котрая рзбирает переданные параметры по свойствам класса объекта
    */
    void parsing(QXmlStreamReader* reader, SvgTranformStack) override;

    /*!
    * \brief Сформированный gcode
    * \return Набор Gcode строк сформированных по значениям свойств объекта
    *
    * В настоящий момент не используется
    */
    QStringList gcode() override;

private:
    QString m_docname; ///< Имя файла
    QString m_inkscape_version; ///< Версия Inkscape
};

#endif // SVGFILEDATA_H