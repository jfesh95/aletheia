######################################################################
# Automatically generated by qmake (2.01a) Mon Dec 17 13:54:19 2012
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += . 'c:/dev/include'
win32: QMAKE_LFLAGS += -static-libgcc

# Input
HEADERS += mainwindow.h \
    aboutdialog.h \
    preferencesdialog.h \
    biblewindow.h \
    biblemanager.h \
    helpbrowser.h \
    colorbutton.h \
    worksmanager.h \
    settings.h
FORMS += mainwindow.ui \
    aboutdialog.ui \
    preferencesdialog.ui \
    biblewindow.ui \
    helpbrowser.ui
SOURCES += main.cpp mainwindow.cpp \
    aboutdialog.cpp \
    preferencesdialog.cpp \
    biblewindow.cpp \
    biblemanager.cpp \
    helpbrowser.cpp \
    colorbutton.cpp \
    worksmanager.cpp

RESOURCES += \
    resources.qrc

unix|win32: LIBS += -L'c:/dev/lib' -lsqlite3
