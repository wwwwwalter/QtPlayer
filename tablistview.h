#ifndef TABLISTVIEW_H
#define TABLISTVIEW_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTreeView>

class TabListView : public QTreeView
{
    Q_OBJECT
public:
    explicit TabListView(QWidget *parent = nullptr);

private:
    QStandardItemModel *model;

public:
    void addTab(QString tabName);
    void updateTabName(int tabIndex,QString tabName);
    void deleteTab(int tabIndex);


    void addMedia(int tabIndex,QString mediaName);
    void addMedias(int tabIndex,QList<QString> mediaNameList);
    void updateMediaName(int tabIndex,int mediaIndex,QString mediaName);
    void deleteMedia(int tabIndex,int mediaIndex);
    void clearMedias(int tabIndex);





signals:

};

#endif // TABLISTVIEW_H
