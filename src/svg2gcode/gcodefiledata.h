#ifndef GCODEFILEDATA_H
#define GCODEFILEDATA_H

#include "gcodeelement.h"
#include "svgfiledata.h"

#include <QObject>

class GcodeFileData : public GcodeElement
{
    Q_OBJECT
public:
    explicit GcodeFileData(SvgElement* svgElement, QObject* parent = nullptr);

    QByteArray generate() override;

private:
    SvgFileData *m_fileData;
};

#endif // GCODEFILEDATA_H
