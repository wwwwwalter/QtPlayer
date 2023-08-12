#include "propertieswidget.h"

PropertiesWidget::PropertiesWidget(QWidget *parent)
    : QTabWidget{parent}
{
    setTabPosition(QTabWidget::South);

    videoPropertyTab = new QWidget;
    audioPropertyTab = new QWidget;

    addTab(videoPropertyTab,tr("video property"));
    addTab(audioPropertyTab,tr("audio property"));


}
