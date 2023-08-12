#include "medialistwidget.h"

#include <QList>
#include <QModelIndex>
#include <QModelIndex>
#include <QHeaderView>

MediaListWidget::MediaListWidget(QWidget *parent)
    : QTableView{parent}
{
    qDebug()<<"MediaListWidget";


    model = new QStandardItemModel;
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,tr("name"));
    model->setHeaderData(1,Qt::Horizontal,tr("path"));
    setModel(model);


    setGridStyle(Qt::NoPen);
    setWordWrap(false);
    horizontalHeader()->setDefaultSectionSize(300);
    horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
//    verticalHeader()->setDefaultSectionSize(50);



    setEditTriggers(QAbstractItemView::NoEditTriggers);

    //context menu
    setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *play = new QAction(tr("Play"));

    addAction(play);















}

MediaListWidget::~MediaListWidget()
{
    qDebug()<<"~MediaListWidget";
}

void MediaListWidget::AddMedia(QString name, QString path)
{
    QList<QStandardItem*> list;
    list.append(new QStandardItem(name));
    list.append(new QStandardItem(path));
    model->appendRow(list);
}
