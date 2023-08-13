#ifndef SPACETABWIDGET_H
#define SPACETABWIDGET_H

#include <QWidget>
#include <QTabWidget>



class SpaceTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit SpaceTabWidget(QWidget *parent = nullptr);
    ~SpaceTabWidget();





public slots:
    void addSpaceTab(QString tabName);


signals:
    void noTab();


};

#endif // SPACETABWIDGET_H
