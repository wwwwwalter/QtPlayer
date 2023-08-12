#include "audiotrackwidget.h"

AudioTrackWidget::AudioTrackWidget(QWidget *parent)
    : QTabWidget{parent}
{
    setTabPosition(QTabWidget::North);
    audioTrackTab = new QWidget;
    addTab(audioTrackTab,tr("Default Tab"));
}
