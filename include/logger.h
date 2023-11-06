#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QString>



class Logger: public QObject
{

    Q_OBJECT

public:
    Logger();
    static Logger *instance();


    void write(QString text);
    void setLogFile(QString filePath);
    void setConsoleLog(bool print);

private:

    bool m_consolePrint;
    QFile *m_logFile;

    void writeToConsole(QString text);
    void writeToFile(QString text);
};

#endif // LOGGER_H
