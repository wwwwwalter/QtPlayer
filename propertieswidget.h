#ifndef PROPERTIESWIDGET_H
#define PROPERTIESWIDGET_H

#include <QWidget>
#include <QTabWidget>

class PropertiesWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit PropertiesWidget(QWidget *parent = nullptr);

private:
    QWidget *videoPropertyTab;
    QWidget *audioPropertyTab;

signals:

};

#endif // PROPERTIESWIDGET_H
