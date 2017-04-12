
TEMPLATE = app
QT += gui widgets printsupport
TARGET = aletheia
DEPENDPATH += .
INCLUDEPATH += . 'c:/dev/include' 'c:/dev/Qt/4.8.5/include'

win32 {
    CONFIG += static
    LIBS += -L'c:/dev/lib' -L'c:/dev/Qt/4.8.5/lib'
    RC_FILE += resources.rc
    HEADERS += sqlite3.h
    SOURCES += sqlite3.c
}

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

OTHER_FILES += \
    resources.rc

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += sqlite3
