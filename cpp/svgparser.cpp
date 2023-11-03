#include "svgparser.h"

#include <QDebug>

#include "tool.h"
#include "svgelementfactory.h"

SvgParser::SvgParser()
{
    m_logger = new Logger(false);
}

bool SvgParser::parsing(QXmlStreamReader *reader)
{
    m_logger->write(QString("Старт обработки файла"));
    while (!reader->atEnd()) {

        QXmlStreamReader::TokenType type = reader->readNext();
        if(reader->error()){
            m_logger->write(reader->errorString());
            return false;
        }

        if(type == QXmlStreamReader::StartElement)
        {
            parsingElement(reader);
        }

    }
    return true;
}

bool SvgParser::parsing(QByteArray bytes)
{
    QXmlStreamReader *reader = new QXmlStreamReader(bytes);
    return parsing(reader);
}

bool SvgParser::parsing(QString filePath)
{
    QFile svgFile(filePath);
    if(!svgFile.open(QIODevice::ReadOnly)){
        m_logger->write(QString("Ошибка открытия файла: %1").arg(svgFile.errorString()));
        return false;
    }

    QByteArray svgData = svgFile.readAll();
    return parsing(svgData);
}

void SvgParser::parsingElement(QXmlStreamReader *reader)
{
    while (!reader->atEnd())
    {
        if(reader->error()){
            qCritical() << reader->error();
            return;
        }

        m_logger->write(QString("Найден XML Element %1").arg(reader->name().toString())) ;

        SvgElement *element = SvgElementFactory().svgElement(reader->name().toString());
        if(element != nullptr){
            element->parsing(reader);
            m_elements.push_back(element);
        }


        QXmlStreamReader::TokenType type = reader->readNext();
        if(type == QXmlStreamReader::StartElement)
        {
            m_logger->write(QString("Найден стартовый элемент, начинаем его обработку!"));
            parsingElement(reader);
        }
        else if(type == QXmlStreamReader::EndElement)
        {
            m_logger->write(QString("Завершено"));
            return;
        }
    }


}
