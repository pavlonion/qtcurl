QT       += core network
QT       -= gui

TARGET    = qtcurl
TEMPLATE  = lib

PRJDIR    = ..
include($$PRJDIR/qmake/configs.pri)



HEADERS  += \
    QtCUrl.h \

SOURCES  += \
    QtCUrl.cpp \

LIBS += -lcurl \

include($$PRJDIR/qmake/install.pri)
