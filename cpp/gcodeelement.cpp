#include "gcodeelement.h"

GcodeElement::GcodeElement(SvgElement *svgElement, QObject* parent)
    : QObject(parent)
{
    Q_UNUSED(svgElement)
}
