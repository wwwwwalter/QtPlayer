#include "videowidget.h"

#include <QKeyEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QVBoxLayout>

VideoWidget::VideoWidget(QWidget *parent)
    : QVideoWidget(parent)
{




}

VideoWidget::~VideoWidget()
{
    qDebug()<<"~VideoWidget()";
}


//void VideoWidget::mousePressEvent(QMouseEvent *event)
//{
//    qDebug()<<"press";
//    if(event->button()==Qt::LeftButton){
//        if(player->playbackState()!=QMediaPlayer::PlayingState){
//            player->play();
//        }
//        else{
//            player->pause();
//        }
//        event->accept();
//    }
//    else{
//        event->ignore();
//    }
//}

//void VideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
//{
//    //setFullScreen(true);
//    this->lower();
//}

//void VideoWidget::keyPressEvent(QKeyEvent *event)
//{
//    qDebug()<<event->key();
//    if((event->key()==Qt::Key_Escape||event->key()==Qt::Key_Back)&&isFullScreen()){
//        setFullScreen(false);
//        event->accept();
//    }
//    else if((event->key()==Qt::Key_Space)){
//        if(player->playbackState()==QMediaPlayer::PausedState){
//            player->play();
//        }
//        else{
//            player->pause();
//        }
//        event->accept();
//    }
//    else{
//        event->ignore();
//    }
//}
