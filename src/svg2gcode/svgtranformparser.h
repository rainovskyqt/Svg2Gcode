#ifndef SVGTRANFORMPARSER_H
#define SVGTRANFORMPARSER_H

#include "svgtranformstack.h"

struct Command
{
public:
    explicit Command(const QString &command, const QString &value);

    QString value() const;
    QString command() const;

private:
    QString m_command;
    QString m_value;
};

class SvgTranformParser
{
public:
    SvgTranformParser();

    SvgTranformStack parse(const QString &input, const SvgTranformStack trans);

private:


    QStringList allCommandsFromString(const QString &input);
    Command commandFromString(const QString &input);
    void addComand(Command comm);
};

#endif // SVGTRANFORMPARSER_H
