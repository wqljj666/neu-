QT       += core gui
QT       += core sql
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    beifen.cpp \
    domainmanagementsystem.cpp \
    domainnode.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    page_forget.cpp \
    page_register.cpp

HEADERS += \
    beifen.h \
    domainmanagementsystem.h \
    domainnode.h \
    login.h \
    mainwindow.h \
    page_forget.h \
    page_register.h

FORMS += \
    beifen.ui \
    domainmanagementsystem.ui \
    login.ui \
    mainwindow.ui \
    page_forget.ui \
    page_register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    domain_data.txt

RESOURCES += \
    ioc.qrc
