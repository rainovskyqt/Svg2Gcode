#ifndef FCCODEMAKER_H
#define FCCODEMAKER_H

#include <QObject>
#include <QXmlStreamReader>

class FCCodeMaker : public QObject
{
    Q_OBJECT
public:
    explicit FCCodeMaker(QObject *parent = nullptr);

    QString convert(QXmlStreamReader* reader);
    QString convert(QByteArray bytes);
    QString convert(const QString &filePath, QString &errorString);

signals:
};

#endif // FCCODEMAKER_H
