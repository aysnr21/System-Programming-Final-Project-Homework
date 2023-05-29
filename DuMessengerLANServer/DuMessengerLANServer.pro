QT = core network

QT -= gui



TARGET = DuMessengerServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
CONFIG += c++17 cmdline


SOURCES += \
        DuMessengerServer.cpp \
        DuMessengerSocket.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    DuMessengerServer.h \
    DuMessengerSocket.h

QMAKE_CXXFLAGS += -std=gnu++11












