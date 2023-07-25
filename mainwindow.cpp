#include "mainwindow.h"

#include <QICon>
#include <QLabel>
#include <QMouseEvent>
#include <QPalette>
#include <QPushButton>
#include <QSlider>
#include <QTextEdit>
#include <QUrl>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //media
    player = new QMediaPlayer(this);


    //main widget
    setWindowIcon(QIcon(":/images/logo2.png"));
    stackedWidget = new QStackedWidget;
    videoWidget = new QVideoWidget;
    labelMask = new QLabel;
    labelMask->setText(tr("Video"));
    labelMask->setFont(QFont("微软雅黑",20,0,false));
    labelMask->setAlignment(Qt::AlignCenter);
    labelMask->setAttribute(Qt::WA_TranslucentBackground,true);
    QPalette palette;
    labelMask->setAutoFillBackground(true);
    palette.setColor(QPalette::WindowText,QColor("white"));
    labelMask->setPalette(palette);

    QVBoxLayout *vboxlayout_lablemask = new QVBoxLayout;
    QSlider *duration_slider = new QSlider;
    duration_slider->setOrientation(Qt::Horizontal);
    //duration_slider->setAutoFillBackground(true);
    //duration_slider->setAttribute(Qt::WA_TranslucentBackground,true);
    vboxlayout_lablemask->addStretch();
    vboxlayout_lablemask->addWidget(duration_slider);
    labelMask->setLayout(vboxlayout_lablemask);


    stackedWidget->insertWidget(0,labelMask);
    stackedWidget->insertWidget(1,videoWidget);
    stackedWidget->setMinimumSize(400,300);
    setCentralWidget(stackedWidget);



    //output
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setVideoOutput(videoWidget);
    player->setSource(QUrl::fromLocalFile("C:\\Users\\gzyit\\Videos\\taylor\\All Too Well.mp4"));

    //control
    //player->play();
    stackedWidget->setCurrentWidget(videoWidget);


























    //dock widget
    //left dock widget
    leftDockWidget = new QDockWidget(tr("list"),this);
    addDockWidget(Qt::LeftDockWidgetArea,leftDockWidget);
    QTextEdit *te1 = new QTextEdit();
    te1->setText(tr("Window1,The dock widget can be moved between docks by the user" ""));
    leftDockWidget->setWidget(te1);






    //bottom dock widget
    bottomDockWidget = new QDockWidget(tr("status"),this);
    addDockWidget(Qt::BottomDockWidgetArea,bottomDockWidget);

    QTextEdit *te2 = new QTextEdit();
    te2->setText(tr("Window2,The dock widget can be moved between docks by the user" ""));
    bottomDockWidget->setWidget(te2);

    //right dock widget
    rightDockWidget = new QDockWidget(tr("property"),this);
    addDockWidget(Qt::RightDockWidgetArea,rightDockWidget);
    QTextEdit *te3 = new QTextEdit();
    te3->setText(tr("Window3 The dock widget can be moved between docks by the user" ""));
    rightDockWidget->setWidget(te3);


}

MainWindow::~MainWindow()
{
}



void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    videoWidget->setFullScreen(true);
    event->accept();
}
