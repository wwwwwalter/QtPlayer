#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>

class VideoWidget : public QVideoWidget
{
    Q_OBJECT
public:
    explicit VideoWidget(QMediaPlayer *player, QWidget *parent = nullptr);

signals:

private:
    QMediaPlayer *player;



protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // VIDEOWIDGET_H
