#include "../include/svgelementfactory.h"

#include "qdebug.h"
#include "svgfiledata.h"

SvgElementFactory::SvgElementFactory()
{

}

SvgElement *SvgElementFactory::svgElement(QString name)
{
    if(QString::compare(name, "svg") == 0){
        return new SvgFileData();
    }

    return nullptr;
}
