#include "medialistwidget.h"

#include <QList>
#include <QModelIndex>
#include <QModelIndex>
#include <QHeaderView>

MediaListWidget::MediaListWidget(QWidget *parent)
    : QTableView{parent}
{
    qDebug()<<"MediaListWidget";


    model = new QStandardItemModel(1,2);
    model->setHeaderData(0,Qt::Horizontal,"name");
    model->setHeaderData(1,Qt::Horizontal,"path");
    setModel(model);

    QFont font;
    font.setPointSize(13);
    setFont(font);

    //setShowGrid(false);
    setGridStyle(Qt::NoPen);
    setWordWrap(false);
    horizontalHeader()->setDefaultSectionSize(400);
    verticalHeader()->setDefaultSectionSize(15);













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
