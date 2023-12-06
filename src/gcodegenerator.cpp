#include "gcodegenerator.h"

#include <QDebug>

#include "logger.h"

GcodeGenerator::GcodeGenerator(QObject *parent)
    : QObject{parent}
{
}

QString GcodeGenerator::genarate(SvgElement* rootElement)
{
    QString gcode;

    gcode.append(rootElement->gcode());

    rootElement->deleteLater();

    return gcode;
}
