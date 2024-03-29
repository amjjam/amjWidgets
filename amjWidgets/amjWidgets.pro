
isEmpty(prefix){
  prefix=/opt/amj
}
  
QT += core gui widgets

TEMPLATE = lib
DEFINES += AMJWIDGETS_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    amjLED.C

HEADERS += \
    amjWidgets.H \
    amjWidgets_global.H

target.path = $${prefix}/lib
headers.path =$${prefix}/include
headers.files = amjWidgets.H

INSTALLS += target headers
