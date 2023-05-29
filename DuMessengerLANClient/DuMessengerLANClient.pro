QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuMessengerLANClient
TEMPLATE = app

CONFIG += c++17


SOURCES += \
    dumessengerconnectiondialog.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    dumessengerconnectiondialog.h \
    widget.h

FORMS += \
    dumessengerconnectiondialog.ui \
    widget.ui

QMAKE_CXXFLAGS += -std=gnu++11
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



