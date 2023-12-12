#include "svgpath.h"
#include "gcodecomments.h"

#include <QDebug>

SvgPath::SvgPath(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Path;
}

void SvgPath::parsing(QXmlStreamReader *reader, SvgTranformStack stack, SvgStyle style)
{
    QXmlStreamAttributes attribs = reader->attributes();
    QString pathData = SvgElement::getString(&attribs, "d").simplified();

    parseCommands(pathData);

    SvgElement::parsing(reader, stack, style);
}

QString SvgPath::gcode(GCodeTool *gCodeTool)
{
    QString gcode;

    gcode.append(GCodeComments().toString(QString("Start path %1").arg(m_id)));

    foreach (SvgElement* element, m_elements) {
        gcode.append(element->gcode(gCodeTool));
        element->deleteLater();
    }
    gcode.append(GCodeComments().toString(QString("End path %1").arg(m_id)));

    return gcode;
}

void SvgPath::parseCommands(const QString &commads)
{
    QRegExp separator("[ ,]");
    QStringList allCommads = commads.split(separator);

    QString currenCommand = allCommads.at(0);                       //Первый элемент path всегда "m", нас интерисует только регистр
    int elementNumber = 2;

    QPointF start(allCommads.at(1).toDouble(), allCommads.at(1).toDouble());        //Второй и третий элементы path всегда координаты откуда он начинается
    QPointF end = start;                    //Конечная точка пути

    QPointF lastPoint = start;                  // Точка где сейчас "находится" голова

    while (elementNumber < allCommads.count() - 1) {
        if(QString::compare(allCommads.at(++elementNumber), "m", Qt::CaseInsensitive) == 0){

        } else if(QString::compare(allCommads.at(++elementNumber), "z", Qt::CaseInsensitive) == 0){     //Если есть элемент "z" замыкаем путь
            end = start;
        }

    }
}
