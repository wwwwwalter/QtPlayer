#ifndef SPACETAB_H
#define SPACETAB_H

#include <QGridLayout>
#include <QSplitter>
#include <QWidget>
#include <mediawidget.h>
#include <common/commomenum.h>

class SpaceTab : public QWidget
{
    Q_OBJECT
public:
    explicit SpaceTab(QWidget *parent = nullptr);
    ~SpaceTab();


    QList<MediaWidget *> getMediaWidgetList() const;

private:
    QList<MediaWidget*> mediaWidgetList;
    QList<QObject*> childrenList;
    QGridLayout *centralLayout; //grid
    QVBoxLayout *vBoxLayout;    //splitter
    QSplitter *centralWidget;   //splitter


    void editSelfToGridLayout(int rols,int cols);
    void editSelfToSplitterLayout(int rols,int cols);

public slots:
    void editSelf(int rols,int cols, CommomEnum::SpaceType spaceType);


signals:



};

#endif // SPACETAB_H
