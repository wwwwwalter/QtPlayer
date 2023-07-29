#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QSlider>
#include <QAudioOutput>

class VideoWidget : public QVideoWidget
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = nullptr);

signals:

private:
    QWidget *parent;





//protected:
//    virtual void mousePressEvent(QMouseEvent *event);
//    virtual void mouseDoubleClickEvent(QMouseEvent *event);
//    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // VIDEOWIDGET_H
