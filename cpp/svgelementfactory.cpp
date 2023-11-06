#include "svgelementfactory.h"

#include <QDebug>
#include "svgfiledata.h"
#include "svggroupelement.h"

SvgElementFactory::SvgElementFactory(QObject *parent)
    :QObject(parent)
{

}

SvgElement *SvgElementFactory::svgElement(QString name)
{
    qDebug() << name;
    if(QString::compare(name, "svg") == 0){
        return new SvgFileData();
    } if (QString::compare(name, "g") == 0){
        return new SvgGroupElement();
    }

    return nullptr;
}
