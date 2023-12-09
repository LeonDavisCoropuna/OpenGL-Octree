# Default rules for deployment (simplified).
# Comment out or remove these lines.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

QT       += core gui widgets opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Octree
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h \
    point.h \
    octree.h

LIBS += -lGLU
x|
