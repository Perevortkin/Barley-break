TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    board.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =




# Default rules for deployment.
include(deployment.pri)
CONFIG += c++11
HEADERS += \
    board.h
