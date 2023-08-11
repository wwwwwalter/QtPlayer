#include "videomask.h"

#include <QHBoxLayout>

VideoMask::VideoMask(QWidget *parent)
    : QLabel{parent}
{
    //ui
    setText(tr("Video"));
    setFont(QFont("微软雅黑",25,-1,false));
    setAlignment(Qt::AlignCenter);
    setStyleSheet("background-color: rgba(0, 255, 0, 0.5);");
    //setWindowOpacity(0.2);//useable

    QPalette palette;
    setAutoFillBackground(true);
    palette.setColor(QPalette::WindowText,QColor("white"));
    setPalette(palette);
}
