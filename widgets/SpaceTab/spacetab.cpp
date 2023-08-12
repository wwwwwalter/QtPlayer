#include "spacetab.h"
#include <QGridLayout>
#include <QSplitter>


SpaceTab::SpaceTab(QWidget *parent)
    : QWidget{parent}
{

}

SpaceTab::~SpaceTab()
{
    qDebug()<<"~SpaceTab";
}

QList<MediaWidget *> SpaceTab::getMediaWidgetList() const
{
    return mediaWidgetList;
}



void SpaceTab::editSelfToGridLayout(int rols, int cols)
{
    childrenList = children();
    if(!childrenList.isEmpty()){
        qDeleteAll(children());
        mediaWidgetList.clear();
    }

    centralLayout = new QGridLayout;
    centralLayout->setSpacing(1);
    centralLayout->setContentsMargins(0,0,0,0);
    setLayout(centralLayout);




    for (int i = 0; i < rols; ++i) {
        centralLayout->setRowMinimumHeight(i,150);
        for (int j = 0; j < cols; ++j) {
            centralLayout->setColumnMinimumWidth(j,200);
            MediaWidget *mediaWidget = new MediaWidget;
            mediaWidgetList.append(mediaWidget);
            centralLayout->addWidget(mediaWidget,i,j);
        }
    }
}

void SpaceTab::editSelfToSplitterLayout(int rols, int cols)
{
    childrenList = children();
    if(!childrenList.isEmpty()){
        qDeleteAll(children());
    }

    vBoxLayout = new QVBoxLayout;
    vBoxLayout->setContentsMargins(0,0,0,0);
    setLayout(vBoxLayout);



    centralWidget = new QSplitter(Qt::Vertical);
    QSplitter *splitterTop = new QSplitter(Qt::Horizontal);
    QSplitter *splitterBottom = new QSplitter(Qt::Horizontal);

    centralWidget->setHandleWidth(1);
    splitterTop->setHandleWidth(1);
    splitterBottom->setHandleWidth(1);

    MediaWidget *topLeft = new MediaWidget;
    MediaWidget *topRight = new MediaWidget;
    MediaWidget *bottomLeft = new MediaWidget;
    MediaWidget *bottomRight = new MediaWidget;
    splitterTop->addWidget(topLeft);
    splitterTop->addWidget(topRight);
    splitterBottom->addWidget(bottomLeft);
    splitterBottom->addWidget(bottomRight);
    centralWidget->addWidget(splitterTop);
    centralWidget->addWidget(splitterBottom);

    splitterTop->setStretchFactor(0, 5);
    splitterTop->setStretchFactor(1, 3);
    vBoxLayout->addWidget(centralWidget);

    mediaWidgetList.append(topLeft);
    mediaWidgetList.append(topRight);
    mediaWidgetList.append(bottomLeft);
    mediaWidgetList.append(bottomRight);



}

void SpaceTab::editSelf(int rols, int cols, CommomEnum::SpaceType spaceType)
{
    switch (spaceType) {
    case CommomEnum::Grid:
        editSelfToGridLayout(rols,cols);
        break;
    case CommomEnum::Splitter:
        editSelfToSplitterLayout(rols,cols);
        break;
    default:
        break;
    }
}



