#include "logger.h"

#include <QDebug>
#include <QDateTime>

Logger::Logger(bool consolePrint, QString filePath)
{
    m_consolePrint = consolePrint;
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
    m_logFile = new QFile(filePath);
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
}
