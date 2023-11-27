QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/svg2gcode/gcodecomments.cpp \
    src/svg2gcode/gcodeelement.cpp \
    src/svg2gcode/gcodefiledata.cpp \
    src/svg2gcode/gcodegenerator.cpp \
    src/svg2gcode/logger.cpp \
    src/svg2gcode/svgelement.cpp \
    src/svg2gcode/svgfiledata.cpp \
    src/svg2gcode/svggroupelement.cpp \
    src/svg2gcode/svgparser.cpp \
    src/svg2gcode/svgpath.cpp \
    src/svg2gcode/svgstyle.cpp \
    src/svg2gcode/svgtogcodeconverter.cpp \
    src/svg2gcode/tool.cpp

HEADERS += \
    src/mainwindow.h \
    src/svg2gcode/gcodecomments.h \
    src/svg2gcode/gcodeelement.h \
    src/svg2gcode/gcodefiledata.h \
    src/svg2gcode/gcodegenerator.h \
    src/svg2gcode/logger.h \
    src/svg2gcode/svgelement.h \
    src/svg2gcode/svgfiledata.h \
    src/svg2gcode/svggroupelement.h \
    src/svg2gcode/svgparser.h \
    src/svg2gcode/svgpath.h \
    src/svg2gcode/svgstyle.h \
    src/svg2gcode/svgtogcodeconverter.h \
    src/svg2gcode/tool.h

FORMS += \
    src/mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
