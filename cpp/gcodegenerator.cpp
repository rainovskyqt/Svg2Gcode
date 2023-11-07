#include "gcodegenerator.h"

#include <QDebug>

#include "gcodeelementfactory.h"
#include "logger.h"

GcodeGenerator::GcodeGenerator(QString desFile, QObject *parent)
    : QObject{parent}
{
    m_gcodeFile = new QFile(desFile);
}

bool GcodeGenerator::genarate(QVector<SvgElement *> svgElementsList)
{
    if(!m_gcodeFile->open(QIODevice::Text|QIODevice::WriteOnly)){
            Logger::instance()->write(QString("Ошибка отрытия файла для записи gcode: %1").arg(m_gcodeFile->errorString()));
            return false;
    }

    for(int i = 0; i < svgElementsList.count(); ++i){
        GcodeElement* gcodeElement = GcodeElementFactory().gcodeElement(svgElementsList.at(i));

        if(gcodeElement == nullptr)
            continue;

        QByteArray array = gcodeElement->generate();
        m_gcodeFile->write(gcodeElement->generate());
    }

    m_gcodeFile->close();

   delete m_gcodeFile;

    return true;
}
