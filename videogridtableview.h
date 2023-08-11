#ifndef VIDEOGRIDTABLEVIEW_H
#define VIDEOGRIDTABLEVIEW_H

#include <QWidget>
#include <QTableView>>
#include <QStandardItemModel>
#include <QHeaderView>

class VideoGridTableView : public QTableView
{
    Q_OBJECT
public:
    explicit VideoGridTableView(QWidget *parent = nullptr);


public:
    QStandardItemModel *model;


    int beginColNum,endColNum;
    int beginRowNum,endRowNum;
    int selectedColNum;
    int selectedRowNum;

    // QWidget interface
protected:
    virtual void mouseReleaseEvent(QMouseEvent *event);

signals:

};

#endif // VIDEOGRIDTABLEVIEW_H
