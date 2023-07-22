#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QVideoWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QAudioOutput>
#include <QMediaPlayer>
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



    // QWidget interface
protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
