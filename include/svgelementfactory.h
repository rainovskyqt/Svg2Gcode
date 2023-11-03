#ifndef SVGELEMENTFACTORY_H
#define SVGELEMENTFACTORY_H


#include "svgelement.h"

class SvgElementFactory
{
public:
    SvgElementFactory();

    SvgElement* svgElement(QString name);
};

#endif // SVGELEMENTFACTORY_H
