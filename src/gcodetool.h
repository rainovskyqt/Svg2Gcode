#ifndef GCODETOOL_H
#define GCODETOOL_H

#include "tool.h"

#include <QObject>
#include <QPointF>
#include <QVector3D>

class GCodeTool : public QObject
{
    Q_OBJECT
public:
    explicit GCodeTool(Tool *tool, QObject *parent = nullptr);

    QString move(QPointF point);
    QString feed(QPointF point, double extrudeVolume = -1);
    QString pauseSec(int seconds);
    QString pauseMillsec(int millsec);
    QString headMove(int z);
    QString headUp(int mm);
    QString headDown(int mm);

    /*!
     * \brief Насройки температуры
     * \return Gcode строку с настройками температуры
     */
    QString tempSettings();

    /*!
     * \brief Насройки выключения принтера
     * \return Gcode строку командами завершения работы
     */
    QString haltSettings();

private:
    Tool *m_tool;
    QVector3D m_currentPosition;
    bool m_headUpped;
    int m_currentLayer;
    int m_layersCount;
};

#endif // GCODETOOL_H
