QT       += core gui multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audiotrackwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    medialistwidget.cpp \
    mediawidget.cpp \
    newprojectdialog.cpp \
    preferencesdialog.cpp \
    propertieswidget.cpp \
    trackswidget.cpp \
    videogridtableview.cpp \
    videomask.cpp \
    videotrackwidget.cpp \
    videowidget.cpp

HEADERS += \
    audiotrackwidget.h \
    mainwindow.h \
    medialistwidget.h \
    mediawidget.h \
    newprojectdialog.h \
    preferencesdialog.h \
    propertieswidget.h \
    trackswidget.h \
    videogridtableview.h \
    videomask.h \
    videotrackwidget.h \
    videowidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

FORMS += \
    newprojectdialog.ui \
    preferencesdialog.ui
