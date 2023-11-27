#include "gcodegenerator.h"

#include <QDebug>

#include "logger.h"

GcodeGenerator::GcodeGenerator(QObject *parent)
    : QObject{parent}
{
}

QStringList GcodeGenerator::genarate(QVector<SvgElement *> svgElementsList)
{
//    if(!m_gcodeFile->open(QIODevice::Text|QIODevice::WriteOnly)){
//            Logger::instance()->write(QString("Ошибка отрытия файла для записи gcode: %1").arg(m_gcodeFile->errorString()));
//            return false;
//    }

//    for(int i = 0; i < svgElementsList.count(); ++i){
//        GcodeElement* gcodeElement = GcodeElementFactory().gcodeElement(svgElementsList.at(i));

//        if(gcodeElement == nullptr)
//            continue;

//        QByteArray array = gcodeElement->generate();
//        m_gcodeFile->write(gcodeElement->generate());
//    }

//    m_gcodeFile->close();

//   delete m_gcodeFile;

//    return true;
}
