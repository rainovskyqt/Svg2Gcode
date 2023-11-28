#ifndef SVGGROUPELEMENT_H
#define SVGGROUPELEMENT_H

#include "svgelement.h"

class SvgGroupElement : public SvgElement
{
    Q_OBJECT

public:

    enum GroupType{
        Layer,
        Group
    };

    SvgGroupElement(QObject *parent = nullptr);   ///Элемен отвечающий, что началась группа элементов

    void parsing(QXmlStreamReader *reader, SvgTranformStack stack) override;
    QStringList gcode() override;

private:
    GroupType m_groupType;
    QString m_label;

    GroupType getGroupType(const QString &id);
};

#endif // SVGGROUPELEMENT_H
