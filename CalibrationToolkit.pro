#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T19:55:02
#
#-------------------------------------------------

QT       += widgets opengl xml

TARGET = CalibrationToolkit
TEMPLATE = lib

DEFINES += CALIBRATIONTOOLKIT_LIBRARY

SOURCES += \
    CameraHub.cpp

HEADERS += \
    CameraHub.h


INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib \
    -lopencv_core -lopencv_highgui \
    -lopencv_features2d -lopencv_objdetect \
    -lopencv_contrib -lopencv_imgproc


include($$(HOME)/SDK/RobotSDK_4.0/Kernel/RobotSDK.pri)
