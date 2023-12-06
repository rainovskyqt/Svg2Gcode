#include "fccodemaker.h"
#include "gcodegenerator.h"
#include "svgparser.h"

FCCodeMaker::FCCodeMaker(QObject *parent)
    : QObject{parent}
{}


QString FCCodeMaker::convert(QXmlStreamReader *reader)
{
    SvgParser parcer;
    SvgElement *rootElement = parcer.parsing(reader);

    GcodeGenerator generator;
    QString gcode = generator.genarate(rootElement);

    return gcode;
}

QString FCCodeMaker::convert(QByteArray bytes)
{
    QXmlStreamReader reader(bytes);
    return convert(&reader);
}

QString FCCodeMaker::convert(const QString &filePath, QString &errorString)
{
    QFile svgFile(filePath);
    if(!svgFile.open(QIODevice::ReadOnly)){
        errorString = QString("Ошибка открытия файла: %1").arg(svgFile.errorString());
        Logger::instance()->write(errorString);
        return "";
    }

    QByteArray svgData = svgFile.readAll();
    return convert(svgData);
}
