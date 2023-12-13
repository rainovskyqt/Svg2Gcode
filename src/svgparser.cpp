#include "svgparser.h"

#include <QDebug>
#include "svgfiledata.h"

#include "fcctool.h"

SvgParser::SvgParser(QObject *parent)
    : QObject(parent)
{
    
}

SvgParser::~SvgParser()
{
    
}

SvgElement* SvgParser::parsing(QXmlStreamReader *reader)
{
    SvgTranformStack transformStack;
    Logger::instance()->write(QString("Старт обработки элементов"));
    
    while (!reader->atEnd()) {

        qDebug() << reader->name().toString();
        QXmlStreamReader::TokenType type = reader->readNext();
        if(reader->name().toString() == "svg" && type == QXmlStreamReader::StartElement){

        m_rootElement = SvgElement::element("svg");
            m_rootElement->parsing(reader, transformStack, SvgStyle());
        parsingElement(reader, transformStack, m_rootElement);
    }
    }
    return m_rootElement;
}

void SvgParser::parsingElement(QXmlStreamReader *reader, SvgTranformStack stack, SvgElement *rootElement)
{
    while (!reader->atEnd()) {
        if(reader->error()){
            Logger::instance()->write(QString("Ошибка парсинга файла").arg(reader->error()));
        }

        QXmlStreamReader::TokenType type = reader->readNext();

        qDebug() << reader->name().toString();
        if(reader->name().toString() == ""){
            continue;
        }

        if(type == QXmlStreamReader::StartElement) {

            SvgElement *currentElement = SvgElement::element(reader->name().toString());
            currentElement->parsing(reader, stack, rootElement->style());
            parsingElement(reader, currentElement->transformStack(), currentElement);
            rootElement->addСhild(currentElement);

        } else if(type == QXmlStreamReader::EndElement){
            Logger::instance()->write(QString("обработка элемента %1 завершена").arg(reader->name().toString()));
            return;
        }
    }
}
