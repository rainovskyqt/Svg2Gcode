#ifndef GCODEELEMENT_H
#define GCODEELEMENT_H

#include <QObject>

#include "svgelement.h"

class GcodeElement : public QObject
{
    Q_OBJECT
public:
    explicit GcodeElement(SvgElement* svgElement, QObject* parent = nullptr);

    enum GcodeElemenType{               // Должно совпадать с типами svg элементов, это связи
        Group,
        FileData
    };

    virtual QByteArray generate() = 0;

signals:

};

#endif // GCODEELEMENT_H
