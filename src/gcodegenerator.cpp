#include "gcodegenerator.h"

#include <QDebug>

#include "gcodecomments.h"

GcodeGenerator::GcodeGenerator(QObject *parent)
    : QObject{parent}
{

}

QString GcodeGenerator::genarate(SvgElement* rootElement, GCodeTool *gCodeTool)
{
    QString gcode;
    gcode.append(startRow(gCodeTool));

    gcode.append(rootElement->gcode(gCodeTool));

    gcode.append(endRow(gCodeTool));

    rootElement->deleteLater();

    return gcode;
}

QString GcodeGenerator::startRow(GCodeTool *gCodeTool, QString comment)
{
    QString gcode;

    if(!comment.isEmpty())
        gcode.append(GCodeComments().toString(comment));

    gcode.append("G28\n");      //Домашнее положение всех осей
    gcode.append("G21\n");      //Использовать метрическую систему
    gcode.append("G90\n");      //Использовать абсолютные координаты

    gcode.append(gCodeTool->tempSettings());

    return gcode;
}

QString GcodeGenerator::endRow(GCodeTool *gCodeTool)
{
    QString gcode;

    gcode.append(gCodeTool->haltSettings());

    return gcode;
}
