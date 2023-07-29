#ifndef VIDEOMASK_H
#define VIDEOMASK_H

#include <QWidget>
#include <QLabel>
#include <QSlider>

class VideoMask : public QLabel
{
    Q_OBJECT
public:
    explicit VideoMask(QWidget *parent = nullptr);

private:
    //ui
    QSlider *duration_slider;


signals:

};

#endif // VIDEOMASK_H
