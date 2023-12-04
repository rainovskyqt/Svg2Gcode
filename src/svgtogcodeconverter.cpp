#include "svgtogcodeconverter.h"

#include <QFile>

#include "gcodegenerator.h"
#include "logger.h"
#include "svgparser.h"

SvgToGcodeConverter::SvgToGcodeConverter()
{

}

QStringList SvgToGcodeConverter::convert(QXmlStreamReader *reader)
{
    SvgParser parcer;
    QVector<SvgElement *> elements = parcer.parsing(reader);

    GcodeGenerator generator;
    QStringList gcode = generator.genarate(elements);

    return gcode;
}

QStringList SvgToGcodeConverter::convert(QByteArray bytes)
{
    QXmlStreamReader reader(bytes);
    return convert(&reader);
}

QStringList SvgToGcodeConverter::convert(const QString &filePath, QString &errorString)
{
    QFile svgFile(filePath);
    if(!svgFile.open(QIODevice::ReadOnly)){
        errorString = QString("Ошибка открытия файла: %1").arg(svgFile.errorString());
        Logger::instance()->write(errorString);
        return QStringList();
    }

    QByteArray svgData = svgFile.readAll();
    return convert(svgData);
}
