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
#include "mediawidget.h"

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




    //action slots
public slots:
    void UpdateStyleWindowsVista();
    void UpdateStyleWindows();
    void UpdateStyleFusion();



};
#endif // MAINWINDOW_H
