#include "spacetabwidget.h"
#include <QTabWidget>
#include <QTabBar>
#include <QTabBar>
#include <QTabBar>
#include <widgets/SpaceTab/spacetab.h>

SpaceTabWidget::SpaceTabWidget(QWidget *parent)
    : QTabWidget{parent}
{

    setTabPosition(QTabWidget::North);
    setTabShape(QTabWidget::Rounded);
    setTabsClosable(true);
    setMovable(true);
    setTabBarAutoHide(false);
    setUsesScrollButtons(true);

    setStyleSheet("QTabBar::tab{width:200}");

    tabBar()->setElideMode(Qt::ElideMiddle);

    connect(this,&SpaceTabWidget::tabCloseRequested,this,[=](int index){
        QWidget *willDeleteTab = widget(index);
        removeTab(index);
        willDeleteTab->deleteLater();
        if(count()==0){
            emit noTab();
        }

    });
}

SpaceTabWidget::~SpaceTabWidget()
{
    qDebug()<<"~SpaceTabWidgt";
}

void SpaceTabWidget::addSpaceTab(QString tabName)
{
    SpaceTab *tab = new SpaceTab;
    addTab(tab,tabName);
    setCurrentWidget(tab);
}

