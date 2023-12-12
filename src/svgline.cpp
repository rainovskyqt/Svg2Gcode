#include "svgline.h"
#include <QDebug>
#include <QLineF>
#include <QtMath>

SvgLine::SvgLine(bool relatively, QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Line;
    m_relatively = relatively;
}

SvgLine::SvgLine(QPointF start, QPointF end, bool relatively, QObject *parent)
{
    m_start = start;
    m_end = end;
    SvgLine(relatively, parent);
}

void SvgLine::parsing(QXmlStreamReader *reader, SvgTranformStack stack, SvgStyle style)
{
    QXmlStreamAttributes attribs = reader->attributes();

    m_start.setX(SvgElement::getDouble(&attribs,"x1"));
    m_start.setY(SvgElement::getDouble(&attribs,"y1"));
    m_end.setX(SvgElement::getDouble(&attribs,"x2"));
    m_end.setY(SvgElement::getDouble(&attribs,"y2"));

    SvgElement::parsing(reader, stack, style);
}

QString SvgLine::gcode(GCodeTool *gCodeTool)
{
    if(isHidden())
        return "";


    QString gcode;

    QPointF trnStart = m_transformStack.process(m_start);       // Стартовая точка линии после применения трансформаций
    QPointF end = getEndPoint(trnStart, m_end, m_relatively);     // Конечная точка линии после преобразования, если координаты относительные
    QPointF trnEnd = m_transformStack.process(end);       // Конечная точка линии после применения трансформаций
    QVector<QPointF> points = getPassedPoints(trnStart, trnEnd, gCodeTool->physicalTool()->nozzleDiameter());

    int currentPoint = -1;          //Ставим -1, что бы проще цикл быи и на первой иттерации получился 0-й элемент
    while(currentPoint < points.count() - 1) {
        gcode.append(gCodeTool->move(points.at(++currentPoint)));
        gcode.append(gCodeTool->feed(points.at(++currentPoint)));
    }

    return gcode;
}

int SvgLine::getPassedCount(double nozzleDiameter)
{
    int count = m_style.strokeWidth() / nozzleDiameter;

    count =  count > 0 ? count : 1;   // Если количество проходов меньше 1 (если толщина линии меньше диаметра сопла), ставим в еденицу

    return count;
}

QVector<QPointF> SvgLine::getPassedPoints(QPointF start, QPointF end, double nozzleDiameter)
{
    double passedCount = getPassedCount(nozzleDiameter);               // Количество проходов для отрисовки линии нужной ширины
    double offset = (passedCount - 1) / 2;                        // Смещение в половину толщины
    double angle = QLineF(start, end).angle();                      //Угол линии к оси x

    double xOffset = nozzleDiameter * qCos(qDegreesToRadians(angle));
    double yOffset = nozzleDiameter * qSin(qDegreesToRadians(angle));

    QPointF firstPassedStart = QPointF(start.x() - (offset * xOffset), start.y() - (offset * yOffset));      // Первый проход смещен на половину толщины
    QPointF firstPassedEnd = QPointF(end.x() - (offset * xOffset), end.y() - (offset * yOffset));

    QVector<QPointF> points;
    points.append(firstPassedStart);
    points.append(firstPassedEnd);

    int currentPass = 1;        //Текущий проход, ставим 1, т.к. уже есть один проход добавленный в массив
    while (currentPass < passedCount) {
        if(currentPass % 2 == 1){
            // если нечетный проход, то добавляем сначала точку окончания линии
            points.append(QPointF(firstPassedEnd.x() + (currentPass * xOffset), firstPassedEnd.y() + (currentPass * yOffset)));
            points.append(QPointF(firstPassedStart.x() + (currentPass * xOffset), firstPassedStart.y() + (currentPass * yOffset)));
        } else {
            // если четный проход, то добавляем сначала точку начала линии
            points.append(QPointF(firstPassedStart.x() + (currentPass * xOffset), firstPassedStart.y() + (currentPass * yOffset)));
            points.append(QPointF(firstPassedEnd.x() + (currentPass * xOffset), firstPassedEnd.y() + (currentPass * yOffset)));
        }
        // Таки образом головка при отрисовки линии будет ходить в обе стороны
        ++currentPass;
    }


    return points;
}

QPointF SvgLine::getEndPoint(QPointF start, QPointF end, bool relatively)
{
    if(relatively){
        return start + end;
    } else {
        return end;
    }
}

