#include "logger.h"

#include <QDebug>
#include <QDateTime>

Q_GLOBAL_STATIC(Logger, global_inst)

Logger::Logger()
{
    m_consolePrint = true;
    m_logFile = nullptr;
}

Logger *Logger::instance()
{
    return global_inst();
}

void Logger::write(QString text)
{
    QString logMessage = QString("%1: %2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.ms"), text);

    if(m_consolePrint)
        writeToConsole(logMessage);

    if(m_logFile != nullptr)
        writeToFile(logMessage);
}

void Logger::setLogFile(QString filePath)
{
    if(!filePath.isEmpty())
        m_logFile = new QFile(filePath);
    else
        m_logFile = nullptr;
}

void Logger::setConsoleLog(bool print)
{
    m_consolePrint = print;
}

void Logger::writeToConsole(QString text)
{
    qDebug() << text;
}

void Logger::writeToFile(QString text)
{
    if(!m_logFile->open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
        qDebug() << m_logFile->errorString();

    m_logFile->write(text.toUtf8());
    m_logFile->write("\n");
    m_logFile->close();
}
