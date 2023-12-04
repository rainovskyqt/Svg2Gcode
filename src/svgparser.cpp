#include "svgparser.h"

#include <QDebug>
#include "svgfiledata.h"

#include "tool.h"

SvgParser::SvgParser(QObject *parent)
    : QObject(parent)
{

}

SvgParser::~SvgParser()
{

}

QVector<SvgElement *> SvgParser::parsing(QXmlStreamReader *reader)
{
    SvgTranformStack transformStack;
    Logger::instance()->write(QString("Старт обработки элементов"));
    while (!reader->atEnd()) {

        QXmlStreamReader::TokenType type = reader->readNext();
        if(reader->error()){
            Logger::instance()->write(QString("Ошибка чтения элементов: %1").arg(reader->errorString()));
            return QVector<SvgElement*>();
        }

        if(type == QXmlStreamReader::StartElement)
        {
            m_elements.append(parsingElement(reader, transformStack));
        }

    }
    return m_elements;
}

SvgElement* SvgParser::parsingElement(QXmlStreamReader *reader, SvgTranformStack stack)
{
    while (!reader->atEnd())
    {
        if(reader->error()){
            Logger::instance()->write(QString("Ошибка парсинга файла").arg(reader->error()));
            return nullptr;
        }

        SvgElement *element = SvgElement::element(reader->name().toString());
        if(element != nullptr){
            element->parsing(reader, stack);
            // m_elements.push_back(element);
        }


        QXmlStreamReader::TokenType type = reader->readNext();
        if(type == QXmlStreamReader::StartElement)
        {
            element->addСhild(parsingElement(reader, stack));
        }
        else if(type == QXmlStreamReader::EndElement)
        {
            Logger::instance()->write(QString("обработка элемента %1 завершена").arg(reader->name().toString()));
            return element;
        }
    }
}
