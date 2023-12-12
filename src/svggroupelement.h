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

    void parsing(QXmlStreamReader* reader, SvgTranformStack stack, SvgStyle style);

    /*!
    * \brief Строка gcode
    * \return Строка gcode сформированная по свойствам элемента
    */
    QString gcode(GCodeTool *gCodeTool) override;

private:
    GroupType m_groupType;
    QString m_label;
    QString m_class;

    GroupType getGroupType(const QString &id);
};

#endif // SVGGROUPELEMENT_H
