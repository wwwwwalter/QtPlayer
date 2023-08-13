#ifndef PLAYLISTVIEW_H
#define PLAYLISTVIEW_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTreeView>
#include <QFileInfo>
#include "common/spacefile.h"

class PlayListView : public QTreeView
{
    Q_OBJECT
public:
    explicit PlayListView(QWidget *parent = nullptr);

private:
    QStandardItemModel *model;


public:
//    void addFile(SpaceFile file);
//    void addFiles(QList<SpaceFile> fileList);
//    void deleteFile();
//    void clearTracks();

    void addFile(QFileInfo fileInfo);
    void addFile(QList<QFileInfo> fileInfoList);




signals:

};

#endif // PLAYLISTVIEW_H
