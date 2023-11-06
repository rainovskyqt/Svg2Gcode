QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cpp/gcodecomments.cpp \
    cpp/gcodeelement.cpp \
    cpp/gcodeelementfactory.cpp \
    cpp/gcodefiledata.cpp \
    cpp/gcodegenerator.cpp \
    cpp/logger.cpp \
    cpp/main.cpp \
    cpp/mainwindow.cpp \
    cpp/svgelement.cpp \
    cpp/svgelementfactory.cpp \
    cpp/svgfiledata.cpp \
    cpp/svggroupelement.cpp \
    cpp/svgparser.cpp \
    cpp/svgstyle.cpp
    cpp/tool.cpp \

HEADERS += \
    include/gcodecomments.h \
    include/gcodeelement.h \
    include/gcodeelementfactory.h \
    include/gcodefiledata.h \
    include/gcodegenerator.h \
    include/logger.h \
    include/mainwindow.h \
    include/svgelement.h \
    include/svgelementfactory.h \
    include/svgfiledata.h \
    include/svggroupelement.h \
    include/svgparser.h \
    include/svgstyle.h \
    include/tool.h \
    include/transformlist.h

FORMS += \
    ui/mainwindow.ui

INCLUDEPATH += \
    include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
