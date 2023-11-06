#include "gcodefiledata.h"
#include "gcodecomments.h"

#include <QDateTime>

GcodeFileData::GcodeFileData(SvgElement *svgElement, QObject *parent)
    : GcodeElement{svgElement, parent}
{
    m_fileData = qobject_cast<SvgFileData *>(svgElement);
}

QByteArray GcodeFileData::generate()
{
    QString generateDateTime = GCodeComments::instance()->toString(QString("Generated %1").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm::ss")));
    QString file = GCodeComments::instance()->toString(QString("from file %1").arg(m_fileData->docname()));
    return QString("%1\n%2").arg(generateDateTime, file).toUtf8();
}
