#ifndef SVGELEMENTFACTORY_H
#define SVGELEMENTFACTORY_H


#include <QObject>

#include "svgelement.h"


class SvgElementFactory: public QObject
{

    Q_OBJECT

public:
    SvgElementFactory(QObject *parent = nullptr);

    SvgElement* svgElement(QString name);
};

#endif // SVGELEMENTFACTORY_H
