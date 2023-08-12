#include "welcomepage.h"

#include <QFile>
#include <QHBoxLayout>

WelComePage::WelComePage(QWidget *parent)
    : QWidget{parent}
{


    QVBoxLayout *vboxlayout = new QVBoxLayout;
    setLayout(vboxlayout);

    QLabel *picLabel = new QLabel;
    QLabel *shortcutLabel = new QLabel;
    vboxlayout->addWidget(picLabel);
    vboxlayout->addWidget(shortcutLabel);

    picLabel->setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
    picLabel->setPixmap(QPixmap(":/images/homepage_logo.png"));

    shortcutLabel->setAlignment(Qt::AlignHCenter);
    shortcutLabel->setTextFormat(Qt::MarkdownText);
    shortcutLabel->setFont(QFont("微软雅黑",15,-1,false));
    QFile file(":/markdowm/homepage.md");
    if(file.open(QFile::ReadOnly)){
        shortcutLabel->setText(QString::fromLocal8Bit(file.readAll()));
        file.close();
    }


}
