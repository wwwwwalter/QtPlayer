#include "videowidget.h"

#include <QKeyEvent>
#include <QMouseEvent>

VideoWidget::VideoWidget(QMediaPlayer *player,QWidget *parent)
    : QVideoWidget(parent),player(player)
{
}


void VideoWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(player->playbackState()==QMediaPlayer::PausedState){
            player->play();
        }
        else{
            player->pause();
        }
        event->accept();
    }
    else{
        event->ignore();
    }
}

void VideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    setFullScreen(true);
    event->accept();
}

void VideoWidget::keyPressEvent(QKeyEvent *event)
{
    if((event->key()==Qt::Key_Escape||event->key()==Qt::Key_Back)&&isFullScreen()){
        setFullScreen(false);
        event->accept();
    }
    else if((event->key()==Qt::Key_Space)){
        if(player->playbackState()==QMediaPlayer::PausedState){
            player->play();
        }
        else{
            player->pause();
        }
        event->accept();
    }
    else{
        event->ignore();
    }
}
