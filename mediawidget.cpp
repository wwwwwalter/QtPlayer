#include "mediawidget.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMouseEvent>
#include <QVBoxLayout>

MediaWidget::MediaWidget(QWidget *parent)
    : QWidget{parent}
{
    //ui
    //setStyleSheet("background-color: rgba(0, 255, 0, 0.5);");
    //play widget
    playWidget = new QWidget;
    playWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    QHBoxLayout *hboxlayout_play = new QHBoxLayout;
    playWidget->setLayout(hboxlayout_play);

    videoWidget = new VideoWidget;
    soundWidget = new QWidget;
    soundWidget->setStyleSheet("background-color: rgba(15, 15, 15, 0);");
    soundWidget->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Preferred);
    leftSoundSlider = new QSlider;
    rightSoundSlider = new QSlider;
    QHBoxLayout *hboxlayout_sound = new QHBoxLayout;
    soundWidget->setLayout(hboxlayout_sound);
    hboxlayout_sound->addWidget(leftSoundSlider);
    hboxlayout_sound->addWidget(rightSoundSlider);
    hboxlayout_play->addWidget(videoWidget);
    hboxlayout_play->addWidget(soundWidget);


    //video mask
    videoMask = new VideoMask;

    //stacked widget
    stackedWidget = new QStackedWidget(this);
    stackedWidget->insertWidget(0,playWidget);
    stackedWidget->insertWidget(1,videoMask);
    stackedWidget->setCurrentWidget(playWidget);


    //context menu
    setContextMenuPolicy(Qt::ActionsContextMenu);
    loadFileAction = new QAction(tr("local file"));
    loadUrlAction = new QAction(tr("Url path"));
    closeFileAction = new QAction(tr("close file"));
    addAction(loadFileAction);
    addAction(loadUrlAction);
    addAction(closeFileAction);

    connect(loadFileAction,&QAction::triggered,this,&MediaWidget::LoadLocalFile);
    connect(loadUrlAction,&QAction::triggered,this,&MediaWidget::LoadUrlFile);
    connect(closeFileAction,&QAction::triggered,this,&MediaWidget::CloseFile);


    //media
    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput;
    mediaPlayer->setAudioOutput(audioOutput);
    mediaPlayer->setVideoOutput(videoWidget);
    mediaPlayer->setLoops(-1);



\










}

void MediaWidget::LoadLocalFile()
{
    QString localFilePath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                         QDir::homePath()+"\\Videos",
                                                         tr("Videos (*.mp4)"));
    if(!localFilePath.isEmpty()){
        mediaPlayer->setSource(QUrl::fromLocalFile(localFilePath));
        mediaPlayer->play();

    }
}

void MediaWidget::LoadUrlFile()
{
    bool ok;
    QString UrlFilePath = QInputDialog::getText(this, tr("Open File"),
                                         tr("Url Path:"), QLineEdit::Normal,
                                         0, &ok);
    if (ok && !UrlFilePath.isEmpty()){
        qDebug()<<UrlFilePath;
    }
}

void MediaWidget::CloseFile()
{
    mediaPlayer->stop();
    mediaPlayer->setSource(QUrl::fromLocalFile(0));
}

void MediaWidget::UpdateVolume(float volume)
{
    qDebug()<<volume;
}

void MediaWidget::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"resize";
    stackedWidget->setGeometry(0,0,width(),height());
}


void MediaWidget::mousePressEvent(QMouseEvent *event)
{

    qDebug()<<"click";

}

void MediaWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"double click";

}
