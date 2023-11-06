#ifndef GCODEELEMENTFACTORY_H
#define GCODEELEMENTFACTORY_H

#include <QObject>

#include "gcodeelement.h"
#include "svgelement.h"


class GcodeElementFactory : public QObject
{
    Q_OBJECT
public:
    explicit GcodeElementFactory(QObject *parent = nullptr);

    GcodeElement *gcodeElement(SvgElement *svgElement);

};

#endif // GCODEELEMENTFACTORY_H
