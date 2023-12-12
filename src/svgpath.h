#ifndef SVGPATH_H
#define SVGPATH_H

#include "svgelement.h"

#include <QPointF>


class SvgPath : public SvgElement
{
public:
    explicit SvgPath(QObject *parent = nullptr);

    void parsing(QXmlStreamReader* reader, SvgTranformStack stack, SvgStyle style) override;
    /*!
    * \brief Строка gcode
    * \return Строка gcode сформированная по свойствам элемента
    */
    QString gcode(GCodeTool *gCodeTool) override;

private:
    QPointF m_start;
    void parseCommands(const QString &commads);
};

#endif // SVGPATH_H
