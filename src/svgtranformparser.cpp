#include "svgtranformparser.h"
#include <QDebug>
#include <QString>


Command::Command(const QString &command, const QString &value)
{
    m_command = command.simplified();
    m_value = value.simplified();
}

QString Command::command() const
{
    return m_command;
}

QString Command::value() const
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
    return input.split(")", QString::SkipEmptyParts);
}

Command SvgTranformParser::commandFromString(const QString &input)
{
    QStringList comTmp = input.split("(", QString::SkipEmptyParts);
    return Command(comTmp.at(0), comTmp.at(1));
}

void SvgTranformParser::addComand(Command comm, SvgTranformStack* stack)
{
    Transformation transform();
    // stack->
}


