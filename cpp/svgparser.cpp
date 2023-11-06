#include "svgparser.h"

#include <QDebug>
#include "svgfiledata.h"

#include "tool.h"
#include "svgelementfactory.h"

SvgParser::SvgParser(QObject *parent)
    : QObject(parent)
{

}

QVector<SvgElement *> SvgParser::parsing(QXmlStreamReader *reader)
{
    Logger::instance()->write(QString("Старт обработки файла"));
    while (!reader->atEnd()) {

        QXmlStreamReader::TokenType type = reader->readNext();
        if(reader->error()){
            Logger::instance()->write(QString("Ошибка открытия файла: %1").arg(reader->errorString()));
            return QVector<SvgElement*>();
        }

        if(type == QXmlStreamReader::StartElement)
        {
            parsingElement(reader);
        }

    }
    return m_elements;
}

QVector<SvgElement *> SvgParser::parsing(QByteArray bytes)
{
    QXmlStreamReader *reader = new QXmlStreamReader(bytes);
    return parsing(reader);
}

QVector<SvgElement *> SvgParser::parsing(QString filePath)
{
    QFile svgFile(filePath);
    if(!svgFile.open(QIODevice::ReadOnly)){
        Logger::instance()->write(QString("Ошибка открытия файла: %1").arg(svgFile.errorString()));
        return QVector<SvgElement*>();
    }

    QByteArray svgData = svgFile.readAll();
    return parsing(svgData);
}

void SvgParser::setLog(QString logFilePath, bool consoleLog)
{
    Logger::instance()->setLogFile(logFilePath);
    Logger::instance()->setConsoleLog(consoleLog);
}

void SvgParser::parsingElement(QXmlStreamReader *reader)
{
    while (!reader->atEnd())
    {
        if(reader->error()){
            Logger::instance()->write(QString("Ошибка парсинга файла").arg(reader->error()));
            return;
        }

        SvgElement *element = SvgElementFactory().svgElement(reader->name().toString());
        if(element != nullptr){
            element->parsing(reader);
            m_elements.push_back(element);
        }


        QXmlStreamReader::TokenType type = reader->readNext();
        if(type == QXmlStreamReader::StartElement)
        {
            parsingElement(reader);
        }
        else if(type == QXmlStreamReader::EndElement)
        {
            Logger::instance()->write(QString("обработка элемента %1 завершена").arg(reader->name().toString()));
            return;
        }
    }
}
