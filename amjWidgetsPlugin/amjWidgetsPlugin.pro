CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(amjledplugin)
TEMPLATE    = lib

HEADERS     = amjLEDPlugin.H
SOURCES     = amjLEDPlugin.C
RESOURCES   = icons.qrc
LIBS        += -L/opt/amj/lib -lamjWidgets
INCLUDEPATH += /opt/amj/include

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target


