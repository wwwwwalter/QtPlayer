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
#include "videowidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    //main widget
    QStackedWidget *stackedWidget;
    //QVideoWidget *videoWidget;
    QLabel *labelMask;
    QPalette *palette;


    //menu
    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *toolMenu;
    QMenu *helpMenu;
    QMenu *changeStyleMenu;

    //action
    QAction *aboutAction;
    QAction *aboutQtAction;





    //dock widget
    QDockWidget *leftDockWidget;
    QDockWidget *bottomDockWidget;
    QDockWidget *rightDockWidget;


    //media
    QMediaPlayer *player;

    //intput


    //output
    QVideoWidget *videoWidget;
    QAudioOutput *audioOutput;

    //action slots
public slots:
    void UpdateStyleWindowsVista();
    void UpdateStyleWindows();
    void UpdateStyleFusion();


protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
