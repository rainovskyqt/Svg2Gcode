#ifndef SVGFILEDATA_H
#define SVGFILEDATA_H

#include "svgelement.h"

class SvgFileData : public SvgElement
{
    Q_OBJECT

public:
    SvgFileData();

    const QString &docname() const;
    void setDocname(const QString &newDocname);

    const QString &inkscape_version() const;
    void setInkscape_version(const QString &newInkscape_version);

    void parsing(QXmlStreamReader* reader, SvgTranformStack) override;
    QStringList gcode() override;

private:
    QString m_docname;
    QString m_inkscape_version;
};

#endif // SVGFILEDATA_H
