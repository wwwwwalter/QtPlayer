QT       += core gui multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audiotrackwidget.cpp \
    common/commomenum.cpp \
    main.cpp \
    mainwindow.cpp \
    medialistwidget.cpp \
    mediawidget.cpp \
    newspacelayoutdialog.cpp \
    preferencesdialog.cpp \
    propertieswidget.cpp \
    spacetabwidget.cpp \
    trackswidget.cpp \
    videogridtableview.cpp \
    videomask.cpp \
    videotrackwidget.cpp \
    videowidget.cpp \
    welcomepage.cpp \
    widgets/SpaceTab/spacetab.cpp

HEADERS += \
    audiotrackwidget.h \
    common/commomenum.h \
    mainwindow.h \
    medialistwidget.h \
    mediawidget.h \
    newspacelayoutdialog.h \
    preferencesdialog.h \
    propertieswidget.h \
    spacetabwidget.h \
    trackswidget.h \
    videogridtableview.h \
    videomask.h \
    videotrackwidget.h \
    videowidget.h \
    welcomepage.h \
    widgets/SpaceTab/spacetab.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

FORMS += \
    newspacelayoutdialog.ui \
    preferencesdialog.ui
