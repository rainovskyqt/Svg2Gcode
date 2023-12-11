#ifndef GCODEGENERATOR_H
#define GCODEGENERATOR_H

#include "svgelement.h"
#include "gcodetool.h"

#include <QFile>
#include <QObject>

class GcodeGenerator : public QObject
{
    Q_OBJECT

public:
    explicit GcodeGenerator(QObject *parent = nullptr);

    QString genarate(SvgElement *rootElement, GCodeTool *gCodeTool);

private:
    /*!
     * \brief Стартовая строка
     * \param comment Коментарий перед началом программы
     * \return Сгенерированная строка инициализации
     *
     * Стартовая строка программы, в основном содержит в себе параметры инициализации принтера
     */
    QString startRow(GCodeTool *gCodeTool, QString comment = QString());

    /*!
     * \brief Конечная строка
     * \return Сгенерированная строка завершения
     *
     * Конечная строка программы, в основном содержит в себе команды завешения печати
     */
    QString endRow(GCodeTool *gCodeTool);
};

#endif // GCODEGENERATOR_H
