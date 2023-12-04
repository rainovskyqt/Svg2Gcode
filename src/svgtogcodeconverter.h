#ifndef SVGTOGCODECONVERTER_H
#define SVGTOGCODECONVERTER_H

#include <QStringList>
#include <QXmlStreamReader>

class SvgToGcodeConverter
{
public:
    SvgToGcodeConverter();

    QStringList convert(QXmlStreamReader* reader);
    QStringList convert(QByteArray bytes);
    QStringList convert(const QString &filePath, QString &errorString);

};

#endif // SVGTOGCODECONVERTER_H
