
TEMPLATE = app
TARGET = aletheia
DEPENDPATH += .
INCLUDEPATH += . 'c:/dev/include' 'c:/dev/Qt5.0.2/5.0.2/mingw47_32/include'
QT += widgets printsupport

LIBS += -lsqlite3

win32 {
    QMAKE_CXXFLAGS += -shared
    QMAKE_LFLAGS += -static
    LIBS += -L'c:/dev/lib' -L'c:/dev/Qt5.0.2/5.0.2/mingw47_32/lib'
    RC_FILE += resources.rc
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
