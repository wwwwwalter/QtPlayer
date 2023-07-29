#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include <QVideoWidget>
#include <QSlider>
#include <QLabel>
#include <QTextEdit>
#include <QStackedWidget>
#include "videowidget.h"
#include "videomask.h"
#include <QMediaPlayer>

class MediaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MediaWidget(QWidget *parent = nullptr);


private:
    //ui
    QStackedWidget *stackedWidget;
    VideoMask *videoMask;
    QWidget *playWidget;
    VideoWidget *videoWidget;
    QWidget *soundWidget;
    QSlider *leftSoundSlider;
    QSlider *rightSoundSlider;


    //context menu
    QAction *loadFileAction;
    QAction *loadUrlAction;
    QAction *closeFileAction;

    //media
    QMediaPlayer *mediaPlayer;
    QAudioOutput *audioOutput;
    QString *localFilePath;
    QString *UrlFilePath;


public slots:
    //action slots
    void LoadLocalFile();
    void LoadUrlFile();
    void CloseFile();
    void UpdateVolume(float volume);



signals:


    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif
