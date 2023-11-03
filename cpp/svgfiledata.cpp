#include "svgfiledata.h"
#include <QDebug>

SvgFileData::SvgFileData()
{

}

const QString &SvgFileData::docname() const
{
    return m_docname;
}

void SvgFileData::setDocname(const QString &newDocname)
{
    m_docname = newDocname;
}

const QString &SvgFileData::inkscape_version() const
{
    return m_inkscape_version;
}

void SvgFileData::setInkscape_version(const QString &newInkscape_version)
{
    m_inkscape_version = newInkscape_version;
}

void SvgFileData::parsing(QXmlStreamReader *reader)
{
    QXmlStreamAttributes attribs = reader->attributes();
    m_id = SvgElement::getString(&attribs, "id");
    m_docname = SvgElement::getString(&attribs, "docname");
    m_inkscape_version = SvgElement::getString(&attribs, "version");
}
