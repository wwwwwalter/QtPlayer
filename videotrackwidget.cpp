#include "videotrackwidget.h"

VideoTrackWidget::VideoTrackWidget(QWidget *parent)
    : QTabWidget{parent}
{
    setTabPosition(QTabWidget::North);
    videoTrackTab = new QWidget;
    addTab(videoTrackTab,tr("Default Tab"));
}
