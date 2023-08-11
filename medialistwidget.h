#ifndef MEDIALISTWIDGET_H
#define MEDIALISTWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QTabWidget>
#include <QStandardItemModel>


class MediaListWidget : public QTableView
{
    Q_OBJECT
public:
    explicit MediaListWidget(QWidget *parent = nullptr);
    ~MediaListWidget();


    QStandardItemModel *model;

    void AddMedia(QString name,QString path);






signals:

};

#endif // MEDIALISTWIDGET_H
