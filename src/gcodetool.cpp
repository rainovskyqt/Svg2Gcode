#include "gcodetool.h"

GCodeTool::GCodeTool(Tool *tool, QObject *parent)
    : QObject{parent}
{
    m_tool = tool;
    m_currentPosition = QVector3D(0,0,5);           // TDOD Определиться со стртовыми коодинатами, придумать функцию сброса положения головы
    m_headUpped = true;
    m_currentLayer = 1;
    m_layersCount = 1;
}

QString GCodeTool::move(QPointF point)
{
    QString gcode;

    //TODO Тут решить надоли и на какую высоту поднимать, пока смотрим сколько всего слоев и поднимаем на один выше
    gcode.append(headUp((m_layersCount - m_currentLayer + 1) * m_tool->layerHeight()));

    return QString("GO X%1 Y%2\n")
        .arg(point.x())
        .arg(point.y());
}

QString GCodeTool::feed(QPointF point, double extrudeVolume)
{
    return QString("G1 X%1 Y%2 E%5\n")
        .arg(point.x())
        .arg(point.y())
        .arg(extrudeVolume);
}

QString GCodeTool::pauseSec(int seconds)
{
    return QString("G4 S%1\n")
        .arg(seconds);
}

QString GCodeTool::pauseMillsec(int millsec)
{
    return QString("G4 P%1\n")
        .arg(millsec);
}

QString GCodeTool::headMove(int z)
{
    return QString("GO Z%1\n")
        .arg(z);
}

QString GCodeTool::headUp(int mm)
{
    return QString("GO Z%1\n")
        .arg(m_currentPosition.z() + mm);
}

QString GCodeTool::headDown(int mm)
{
    if(m_currentPosition.z() <= 0)
        return "";

    return QString("GO Z%1\n")
        .arg(m_currentPosition.z() - mm);
}

QString GCodeTool::tempSettings()
{
    QString gcode;

    gcode.append(QString("M104 S%1\n").arg(m_tool->extruderTemp())); //Установить температуру экструдера
    gcode.append(QString("M140 S%1\n").arg(m_tool->platformTemp())); //Установить температуру подогрева платформы
    gcode.append(QString("M190 S%1\n").arg(m_tool->platformTemp())); //Дождаться, пока платформа нагреется

    return gcode;
}

QString GCodeTool::haltSettings()
{
    QString gcode;

    gcode.append("G92 E0\n");       //Сбросить экструдер
    gcode.append("M104 S0\n");      //Выключить экструдер
    gcode.append("M140 S0\n");      //Выключить подогрев платформы
    gcode.append("G28\n");          //Вернуться в начальное положение

    return gcode;
}
