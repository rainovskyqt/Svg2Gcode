#ifndef SVGELEMENT_H
#define SVGELEMENT_H

/*!
    * \brief Элемент svg файла
    *
    * Абстрактный элемент svg файла, содержит общие свойства и методы присущие всем элементам
    */

#include "svgstyle.h"
#include "svgtranformstack.h"

#include <QString>
#include <QObject>
#include <QXmlStreamReader>
#include "gcodetool.h"


class SvgElement : public QObject
{
    Q_OBJECT

public:
    explicit SvgElement(QObject *parent = nullptr);

    /*!
    * \brief Разбор данных элемента
    *
    * Разбор данных элемента, основная функция котрая рзбирает переданные параметры по свойствам класса объекта
    */
    virtual void parsing(QXmlStreamReader* reader, SvgTranformStack stack, SvgStyle style);

    /*!
    * \brief Строка gcode
    * \return Строка gcode сформированная по свойствам элемента
    */
    virtual QString gcode(GCodeTool *gCodeTool) = 0;

    /*!
    * \brief Типы элементов
    *
    * Содержит список элементов svg файла, которые умеет обрабатывать
    */
    enum SvgElementType{
        Empty,                      ///< Пустой элемент, возвращается для элементов не требующих обработки
        Group,                      ///< Общее определение группы, элемент не попадающее в другие категории
        FileData,                   ///< Данные о файле
        Path,                       ///< Элемент path #SvgPath
        Ellipse,                    ///< Элемент path #SvgEllipse
        Line,                       ///< Элемент path #SvgLine
        Circle,                     ///< Элемент path #SvgCircle
        Rect,                       ///< Элемент path #SvgRect
        Polygon                     ///< Элемент path #SvgPolygon
    };

    /*!
    * \brief Конструктор элемента
    * \param name тэг элемента в файле svg файле
    * \return Указатель на элемент
    *
    * Абстрактная файбрика элементов svg, строится в зависимости от наименования (тэга) элемента в svg файле, например <path> вернет #SvgPath
    */
    static SvgElement *element(const QString &name);


    static QString findValue(QXmlStreamAttributes* attribs, QString attributeName);
    static double getDouble(QXmlStreamAttributes* attribs, QString attributeName);
    static int getInt(QXmlStreamAttributes* attribs, QString attributeName);
    static QString getString(QXmlStreamAttributes* attribs, QString attributeName);
    SvgElementType type() const;

    /*!
    * \brief Добавляет элемент в список вложенных
    */
    void addСhild(SvgElement * element);

    QVector<SvgElement *> elements();

    SvgTranformStack transformStack() const;

    SvgStyle style() const;

protected:
    QString m_id;
    SvgElementType m_type;

    /*!
    * \brief Список вложенных элементов
    */
    QVector<SvgElement*> m_elements;

    SvgTranformStack m_transformStack;
    SvgStyle m_style;

    SvgTranformStack parseTranform(const QString &transform, SvgTranformStack stack);
    SvgStyle parseStyle(QXmlStreamReader *reader, SvgStyle parentStyle);

    bool isHidden();
};

#endif // SVGELEMENT_H
