#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QVideoWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include "mediawidget.h"
#include "medialistwidget.h"
#include "propertieswidget.h"
#include "audiotrackwidget.h"
#include "videotrackwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    //main widget
    QWidget *centralWidget;
    QList<MediaWidget*> *listMediaWidget;

    QLabel *labelMask;
    QPalette *palette;





    //dock widget
    QDockWidget *topDockWidget;
    QDockWidget *leftDockWidget;
    QDockWidget *bottomDockWidget;
    QDockWidget *rightDockWidget;

    //dock widget children
    MediaListWidget *mediaListWidget;
    PropertiesWidget *protertiesWidget;
    AudioTrackWidget *audioTrackWidget;
    VideoTrackWidget *videoTrackWidget;



public:
    //menus
    QMenu *file;
    QMenu *edit;
    QMenu *view;
    QMenu *build;
    QMenu *tools;
    QMenu *help;

    //actions
    //file actions
    QAction *newproject;
    QAction *open;
    QAction *preferencs;

    //edit actions
    QAction *undo;
    QAction *redo;

    //view actions
    QAction *showLeftDock;
    QAction *showRightDock;
    QAction *showBottomDock;
    QAction *showTopDock;

    //build actions
    QAction *buildproject;
    QAction *cleanproject;

    //tools actions;
    QAction *opencv;
    QAction *ffmpeg;

    //help actions;
    QAction *about;
    QAction *aboutQt;
    QAction *document;

    //toolbars
    //file tool bar
    QToolBar *fileToolBar;

    //edit tool bar

    //view tool bar

    //build tool bar

    //tools tool bar

    //help tool bar
    QToolBar *helpToolBar;




public:
    void CreateActions();
    void CreateMenus();
    void CreateToolBars();
    void CreateStatusBars();







    //action slots
public slots:




};
#endif // MAINWINDOW_H
