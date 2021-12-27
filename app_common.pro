QT -= gui
QT += widgets

TEMPLATE = lib
DESTDIR = ../bin

CONFIG += \
    staticlib \
    c++17

SOURCES += \
    src/application.cpp \
    src/uimode_interface.cpp

HEADERS += \
    inc/application.h \
    inc/styled_widgets.h \
    inc/uimode_interface.h

INCLUDEPATH += inc

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
