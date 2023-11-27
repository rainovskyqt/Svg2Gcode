#ifndef SVGPATH_H
#define SVGPATH_H

#include "svgelement.h"

#include <QPointF>

class SvgPath : public SvgElement
{
public:
    explicit SvgPath(QObject *parent = nullptr);

    void parsing(QXmlStreamReader* reader);

private:
    QPointF m_start;


};

#endif // SVGPATH_H
