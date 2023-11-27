#include "gcodeelement.h"
#include "logger.h"

GcodeElement::GcodeElement(SvgElement *svgElement, QObject* parent)
    : QObject(parent)
{
    Q_UNUSED(svgElement)
}

GcodeElement *GcodeElement::element(const QString &name)
{
    if(QString::compare(name, "g") == 0){
        Logger::instance()->write("Создана группа");
//        return new DxfLine();
    } else if(QString::compare(name, "CIRCLE") == 0){
         Logger::instance()->write("Создали круг");
    }

    return nullptr;
}
