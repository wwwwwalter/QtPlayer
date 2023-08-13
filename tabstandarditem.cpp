#include "tabstandarditem.h"

TabStandardItem::TabStandardItem(QString name)
    :QStandardItem(name)
{
    qDebug()<<"TabStandardItem";
}

TabStandardItem::~TabStandardItem()
{
    qDebug()<<"~TabStandardItem";

}
