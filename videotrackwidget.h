#ifndef VIDEOTRACKWIDGET_H
#define VIDEOTRACKWIDGET_H

#include <QWidget>
#include <QTabWidget>

class VideoTrackWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit VideoTrackWidget(QWidget *parent = nullptr);

private:
    QWidget *videoTrackTab;

signals:

};

#endif // VIDEOTRACKWIDGET_H
