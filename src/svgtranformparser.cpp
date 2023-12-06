#include "svgtranformparser.h"
#include <QDebug>
#include <QString>


Command::Command(const QString &command, const QStringList &value)
{
    m_command = command.simplified();
    foreach (QString val, value) {
        m_value.append(val.toDouble());
    }
}

QString Command::command() const
{
    return m_command;
}

QVector<double> Command::value() const
{
    return m_value;
}

SvgTranformParser::SvgTranformParser()
{

}

SvgTranformStack SvgTranformParser::parse(const QString &input, const SvgTranformStack stack)
{
    if(input.isEmpty())
        return stack;

    SvgTranformStack newStack = stack;

    QStringList allCommands = allCommandsFromString(input);

    QString commandRow;
    foreach (commandRow, allCommands) {
        Command cCommand = commandFromString(commandRow);
        addComand(cCommand, &newStack);
    }

    return newStack;
}

QStringList SvgTranformParser::allCommandsFromString(const QString &input)
{
    return input.simplified().split(")", QString::SkipEmptyParts);
}

Command SvgTranformParser::commandFromString(const QString &input)
{
    QStringList comTmp = input.split("(", QString::SkipEmptyParts);
    QRegExp separator(",|\\s");

    return Command(comTmp.at(0), comTmp.at(1).split(separator, QString::SkipEmptyParts));
}

void SvgTranformParser::addComand(Command comm, SvgTranformStack* stack)
{
    if(QString::compare(comm.command(), "rotate", Qt::CaseInsensitive) == 0){
        switch(comm.value().length())
        {
        case 1:
            stack->pushRotate(comm.value().at(0));
            break;
        case 2:
            stack->pushRotate(comm.value().at(0), comm.value().at(1), comm.value().at(1));
            break;
        case 3:
            stack->pushRotate(comm.value().at(0), comm.value().at(1), comm.value().at(2));
            break;
        }
    }
}


