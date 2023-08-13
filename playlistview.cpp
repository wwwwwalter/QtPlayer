#include "playlistview.h"

PlayListView::PlayListView(QWidget *parent)
    : QTreeView{parent}
{
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    model = new QStandardItemModel;
    model->setHorizontalHeaderLabels(QStringList()<<tr("Name")<<tr("Path")<<tr("Type"));
    setModel(model);
}

void PlayListView::addFile(QFileInfo fileInfo)
{
    QList<QStandardItem*> row;
    row.append(new QStandardItem(fileInfo.fileName()));
    row.append(new QStandardItem(fileInfo.path()));
    row.append(new QStandardItem(fileInfo.suffix()));
    model->appendRow(row);
}

void PlayListView::addFile(QList<QFileInfo> fileInfoList)
{
    foreach (QFileInfo fileInfo, fileInfoList) {
        addFile(fileInfo);
    }
}

//void PlayListWidget::addFile(SpaceFile file)
//{
//    QList<QStandardItem*> fileInfo;
//    fileInfo.append(new QStandardItem(file.getName()));
//    fileInfo.append(new QStandardItem(file.getPath()));
//    fileInfo.append(new QStandardItem(file.getType()));
//    model->appendRow(fileInfo);
//}

//void PlayListWidget::addFiles(QList<SpaceFile> fileList)
//{
//    foreach (SpaceFile file, fileList) {
//        addFile(file);
//    }
//}


