#include "gcodeelementfactory.h"

#include "gcodefiledata.h"
#include "qdebug.h"

GcodeElementFactory::GcodeElementFactory(QObject *parent)
    : QObject{parent}
{

}

GcodeElement *GcodeElementFactory::gcodeElement(SvgElement *svgElement)
{
    qDebug() << int(svgElement->type());
    qDebug() << int(GcodeElement::GcodeElemenType::FileData);

    if(int(svgElement->type()) == int(GcodeElement::GcodeElemenType::FileData)){
        return new GcodeFileData(svgElement);
//    } if (QString::compare(name, "g") == 0){
//        return new SvgFileData();
    }

    return nullptr;
}
