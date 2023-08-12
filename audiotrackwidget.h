#ifndef AUDIOTRACKWIDGET_H
#define AUDIOTRACKWIDGET_H

#include <QWidget>
#include <QTabWidget>

class AudioTrackWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit AudioTrackWidget(QWidget *parent = nullptr);

private:
    QWidget *audioTrackTab;

signals:

};

#endif // AUDIOTRACKWIDGET_H
