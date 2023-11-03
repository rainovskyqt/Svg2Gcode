#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QString>



class Logger
{
public:
    Logger(bool consolePrint = true, QString filePath = QString());

    void write(QString text);

private:
    bool m_consolePrint;
    QFile *m_logFile = nullptr;

    void setLogFile(QString filePath);
    void writeToConsole(QString text);
    void writeToFile(QString text);
};

#endif // LOGGER_H
