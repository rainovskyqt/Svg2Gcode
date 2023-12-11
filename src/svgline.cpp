#include "svgline.h"
#include <QDebug>

SvgLine::SvgLine(QObject *parent)
    : SvgElement{parent}
{
    m_type = SvgElementType::Line;
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

    int extruedeVol = 30;           // Потом изменим в зависимости от стиля, возможно будет нужно несколько проходов

    QPointF trnStart = m_transformStack.process(m_start);       // Стартовая точка линии после применения трансформаций
    QPointF trnEnd = m_transformStack.process(m_end);       // Стартовая точка линии после применения трансформаций

    gcode.append(gCodeTool->move(trnStart));
    gcode.append(gCodeTool->feed(trnEnd,extruedeVol));

    return gcode;
}
