#ifndef FCCODEMAKER_H
#define FCCODEMAKER_H

/*!
 * \todo определиться как передавать настройки, всейчас в функции makeTool генерируется инструмент, поэтому либо туда передавать
 * например экземпляр QSettings, либо переделать инициализацию так, что бы принимался ссылка на #Tool, либо #makeTool сделать с соответствующими параматрами.
 */

#include <QObject>
#include <QXmlStreamReader>

#include "tool.h"

class FCCodeMaker : public QObject
{
    Q_OBJECT
public:
    explicit FCCodeMaker(QObject *parent = nullptr);

    QString convert(QXmlStreamReader* reader);
    QString convert(QByteArray bytes);
    QString convert(const QString &filePath, QString &errorString);

private:
    /*!
     * \brief Создаем экземпляр исполнителя
     * \return Экземпляр исполнителя
     *
     * Функция служит для создания экземпляра исполнителя, тут передаются все настройки принтера, с рабочей программе,
     * нужно будет поддягивать файл настроек
     */
    Tool *makeTool(Tool *tool);
};

#endif // FCCODEMAKER_H
