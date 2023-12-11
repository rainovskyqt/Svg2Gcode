QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    giu/main.cpp \
    giu/mainwindow.cpp \
    src/fccodemaker.cpp \
    src/gcodecomments.cpp \
    src/gcodegenerator.cpp \
    src/gcodetool.cpp \
    src/logger.cpp \
    src/svgcircle.cpp \
    src/svgelement.cpp \
    src/svgellipse.cpp \
    src/svgemptyelement.cpp \
    src/svgfiledata.cpp \
    src/svggroupelement.cpp \
    src/svgline.cpp \
    src/svgparser.cpp \
    src/svgpath.cpp \
    src/svgpolygon.cpp \
    src/svgrect.cpp \
    src/svgstyle.cpp \
    src/svgtranformparser.cpp \
    src/svgtranformstack.cpp \
    src/tool.cpp

HEADERS += \
    giu/mainwindow.h \
    src/fccodemaker.h \
    src/gcodecomments.h \
    src/gcodegenerator.h \
    src/gcodetool.h \
    src/logger.h \
    src/svgcircle.h \
    src/svgelement.h \
    src/svgellipse.h \
    src/svgemptyelement.h \
    src/svgfiledata.h \
    src/svggroupelement.h \
    src/svgline.h \
    src/svgparser.h \
    src/svgpath.h \
    src/svgpolygon.h \
    src/svgrect.h \
    src/svgstyle.h \
    src/svgtranformparser.h \
    src/svgtranformstack.h \
    src/tool.h

FORMS += \
    giu/mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
