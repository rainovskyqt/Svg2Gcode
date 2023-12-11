#include "fccodemaker.h"
#include "gcodegenerator.h"
#include "svgparser.h"
#include "gcodetool.h"

FCCodeMaker::FCCodeMaker(QObject *parent)
    : QObject{parent}
{

}

QString FCCodeMaker::convert(QXmlStreamReader *reader)
{
    SvgParser parcer;
    SvgElement *rootElement = parcer.parsing(reader);

    Tool *tool = new Tool();
    makeTool(tool);

    GCodeTool *gCodeTool = new GCodeTool(tool);

    GcodeGenerator generator;
    QString gcode = generator.genarate(rootElement, gCodeTool);

    delete tool;

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

Tool *FCCodeMaker::makeTool(Tool *tool)
{
    tool->setFeedRate(140);
    tool->setPlatformTemp(60);
    tool->setExtruderTemp(200);
    tool->setNozzleDiameter(0.5);
    tool->setExtrudeVolume(30.0);

    return tool;
}
