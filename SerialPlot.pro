#-------------------------------------------------
#
# Project created by QtCreator 2011-09-04T21:04:31
#
# install_name_tool -change libqextserialport.1.dylib @executable_path/../Frameworks/libqextserialport.1.dylib SerialPlot
#-------------------------------------------------

QT       += core gui

TARGET = SerialPlot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SensorCurve.cpp \
    SensorData.cpp \
    DynamicParam.cpp \
    serialSelectDialog.cpp \
    PlotWindow.cpp \
    ParamWindow.cpp \
    LogWindow.cpp

HEADERS  += mainwindow.h \
    SensorCurve.h \
    SensorData.h \
    DynamicParam.h \
    serialSelectDialog.h \
    PlotWindow.h \
    ParamWindow.h \
    LogWindow.h

FORMS    += mainwindow.ui \
    serialSelectDialog.ui \
    PlotWindow.ui \
    ParamWindow.ui \
    LogWindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qwt-6.0.1/lib/release/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qwt-6.0.1/lib/debug/ -lqwt
else:mac: LIBS += -F$$PWD/../qwt-6.0.1/lib/ -framework qwt
else:unix: LIBS += -L$$PWD/../qwt-6.0.1/lib/ -lqwt

INCLUDEPATH += $$PWD/../qwt-6.0.1/src
DEPENDPATH += $$PWD/../qwt-6.0.1/src

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qextserialport/src/build/ -lqextserialport
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qextserialport/src/build/ -lqextserialportd
else:unix:!symbian: LIBS += -L$$PWD/../qextserialport/src/build/ -lqextserialport

INCLUDEPATH += $$PWD/../qextserialport/src
DEPENDPATH += $$PWD/../qextserialport/src


































