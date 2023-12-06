#ifndef SVGPARSER_H
#define SVGPARSER_H
/*!
 * \brief Класс разбирающий svg файл на составные элементы
 */
#include <QObject>
#include <QString>
#include <QVector>
#include <QFile>
#include <QXmlStreamReader>
#include <QMap>

#include "logger.h"
#include "svgelement.h"


class SvgParser: public QObject
{
    Q_OBJECT

public:
    /*!
    * \brief Класс разбирающий svg файл на составные элементы
    */
    SvgParser(QObject *parent = nullptr);

    ~SvgParser();

    /*!
    * \brief Основная функция разбора файла
    * \param reader Данные из файла
    * \return Список обрануженных и разобранных элементов
    *
    * Определяет стартовый признак элемента и передает в #parsingElement для разбора свойст элемента
    */
    SvgElement *parsing(QXmlStreamReader *reader);

private:
    /*!
    * \brief Список обрануженных и разобранных элементов верхнего уровня
    */
    // QVector<SvgElement*> m_elements;
    SvgElement* m_rootElement;

    /*!
    * \brief Функция разбора элемента
    * \param reader Данные из файла
    * \return разобранный элемент
    *
    * Добавляет элемент в список, при обнаружение признака начала элемента рекурсивно себя вызывает, определяет конец элемента.
    */
    void parsingElement(QXmlStreamReader* reader, SvgTranformStack stack, SvgElement *rootElement);
};

#endif // SVGPARSER_H
