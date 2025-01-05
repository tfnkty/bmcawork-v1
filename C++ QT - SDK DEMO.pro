QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "C++ QT - SDK DEMO"
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        dialog.cpp \
        graphplot.cpp \
        devices.cpp \
        settings.cpp \
        advanced.cpp

HEADERS += \
        dialog.h \
        graphplot.h \
        devices.h \
        mlfunc.h \
        settings.h \
        advanced.h \
        DIMHW.h \
        mlfunc.h \
        mlfuncv2.h \
        mcasettings.h

FORMS += \
        dialog.ui \
        devices.ui \
        settings.ui \
        advanced.ui

LIBS += -L"$$PWD/" -lDIMHW

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../release/ -lDIMHW
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../debug/ -lDIMHW
else:unix: LIBS += -L$$PWD/../ -lDIMHW

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/lib -larmadillo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/debug/lib -larmadillo
else:unix: LIBS += -L$$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/lib -larmadillo

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/lib -llapack
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/debug/lib -llapack
else:unix: LIBS += -L$$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/lib -llapack

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/lib -lopenblas
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/debug/lib -lopenblas
else:unix: LIBS += -L$$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/lib -lopenblas

INCLUDEPATH += $$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/include
DEPENDPATH += $$PWD/../../../../Documents/CPPlibraries/vcpkg-master/installed/x64-windows/include
