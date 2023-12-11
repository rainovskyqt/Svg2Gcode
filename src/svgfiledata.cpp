#include "svgfiledata.h"
#include <QDebug>
#include <QDateTime>
#include "logger.h"
#include "gcodecomments.h"

SvgFileData::SvgFileData()
{
    m_type = SvgElementType::FileData;
}

const QString &SvgFileData::docname() const
{
    return m_docname;
}

void SvgFileData::setDocname(const QString &newDocname)
{
    m_docname = newDocname;
}

const QString &SvgFileData::inkscapeVersion() const
{
    return m_inkscape_version;
}

void SvgFileData::setInkscape_version(const QString &newInkscapeVersion)
{
    m_inkscape_version = newInkscapeVersion;
}

void SvgFileData::parsing(QXmlStreamReader *reader, SvgTranformStack stack, SvgStyle style)
{
    Logger::instance()->write(QString("Найден стартовый элемент %1, начинаем его обработку!").arg(reader->name().toString()));
    QXmlStreamAttributes attribs = reader->attributes();

    m_docname = SvgElement::getString(&attribs, "docname");
    m_inkscape_version = SvgElement::getString(&attribs, "version");

    SvgElement::parsing(reader, stack, style);
}

QString SvgFileData::gcode(GCodeTool *gCodeTool)
{
    QString gcode;

    foreach (SvgElement* element, m_elements) {
        gcode.append(element->gcode(gCodeTool));
        element->deleteLater();
    }

    return gcode;
}
