#include "tablistview.h"
#include "tabstandarditem.h"

TabListView::TabListView(QWidget *parent)
    : QTreeView{parent}
{
    //setHeaderHidden(true);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    model = new QStandardItemModel;
    model->setHorizontalHeaderLabels(QStringList()<<tr("Name")<<tr("Type"));
    setModel(model);


}

void TabListView::addTab(QString tabName)
{
    QStandardItem *item = new QStandardItem(tabName);
    item->setIcon(QIcon(":/images/green/folder_close.svg"));
    model->appendRow(item);
}

void TabListView::addMedia(int tabIndex, QString mediaName)
{
    QStandardItem *tabItem = model->item(tabIndex);
    QStandardItem *item = new QStandardItem(mediaName);
    tabItem->appendRow(item);
}

void TabListView::addMedias(int tabIndex, QList<QString> mediaNameList)
{
    QStandardItem *tabItem = model->item(tabIndex);
    qDebug()<<tabItem;
    foreach (QString mediaName, mediaNameList) {
        TabStandardItem *item = new TabStandardItem(mediaName);
        item->setIcon(QIcon(":/images/green/media.svg"));

        tabItem->appendRow(item);
    }
    setExpanded(tabItem->index(),true);


}

void TabListView::updateMediaName(int tabIndex, int mediaIndex, QString mediaName)
{
    QStandardItem *tabItem = model->item(tabIndex);
    TabStandardItem *item = new TabStandardItem(mediaName);
    tabItem->setChild(mediaIndex,item);
}

void TabListView::deleteMedia(int tabIndex, int mediaIndex)
{
    QStandardItem *tabItem = model->item(tabIndex);
    tabItem->removeRow(mediaIndex);
}

void TabListView::clearMedias(int tabIndex)
{
    QStandardItem *tabItem = model->item(tabIndex);
    tabItem->removeColumn(0);
}
