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
#include <QMenuBar>
#include <QApplication>
#include <QStyleFactory>
#include <QActionGroup>
#include <QDialog>
#include <QDialogButtonBox>
#include <QComboBox>
#include <preferencesdialog.h>
#include <QStatusBar>
#include <QToolButton>
#include <QFileDialog>
#include <QScrollArea>
#include <QSplitter>
#include <QMessageBox>
#include <QInputDialog>
#include "medialistwidget.h"
#include "newspacelayoutdialog.h"
#include <widgets/SpaceTab/spacetab.h>
#include "common/commomenum.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //mainwindow
    setWindowIcon(QIcon(":/images/logo2.png"));
    setWindowTitle(tr("XPlayer"));
    loadStyleSheet();
    resize(1500,800);



    //central widget
    centralStackWidget = new QStackedWidget;
    centralStackWidget->setContentsMargins(0,0,0,0);
    centralStackWidget->layout()->setContentsMargins(0,0,0,0);

    setCentralWidget(centralStackWidget);
    welcomePage = new WelComePage;
    spaceTabWidget = new SpaceTabWidget;
    connect(spaceTabWidget,&SpaceTabWidget::currentChanged,this,[=](int index){
        //TODO
    });

    connect(spaceTabWidget,&SpaceTabWidget::noTab,this,[=]{
        centralStackWidget->setCurrentWidget(welcomePage);
    });

    centralStackWidget->addWidget(welcomePage);
    centralStackWidget->addWidget(spaceTabWidget);
    centralStackWidget->setCurrentWidget(welcomePage);
















    //output



    //control



























    //top dock widget
    topDockWidget = new QDockWidget("AudioTrack",this);
    topDockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    QWidget *topDockTitleBar = new QWidget;
    topDockWidget->setTitleBarWidget(topDockTitleBar);
    addDockWidget(Qt::BottomDockWidgetArea,topDockWidget);
    audioTrackWidget = new AudioTrackWidget;
    topDockWidget->setWidget(audioTrackWidget);



    //left dock widget
    leftDockWidget = new QDockWidget(tr("MediaList"),this);
    topDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea,leftDockWidget);
    mediaListWidget = new MediaListWidget;
    leftDockWidget->setWidget(mediaListWidget);




    //right dock widget
    rightDockWidget = new QDockWidget(tr("Properties"),this);
    topDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,rightDockWidget);
    protertiesWidget = new PropertiesWidget;
    rightDockWidget->setWidget(protertiesWidget);



    //bottom dock widget
    bottomDockWidget = new QDockWidget(tr("VideoTrack"),this);
    bottomDockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    QWidget *bottomDockTitleBar = new QWidget;
    bottomDockWidget->setTitleBarWidget(bottomDockTitleBar);
    addDockWidget(Qt::BottomDockWidgetArea,bottomDockWidget);
    videoTrackWidget = new VideoTrackWidget;
    bottomDockWidget->setWidget(videoTrackWidget);

    //combine audio & video track
    tabifyDockWidget(bottomDockWidget,topDockWidget);
    bottomDockWidget->raise();





    //menu
    CreateActions();
    CreateMenus();
    //CreateToolBars();
    CreateStatusBars();


}

MainWindow::~MainWindow()
{
}





void MainWindow::CreateActions()
{
    //file actions
    newproject = new QAction(tr("New"));
    newproject->setShortcuts ( QKeySequence::New );
    connect(newproject,&QAction::triggered,this,[=]{

    });

    newTab = new QAction(tr("New Tab"));
    newTab->setShortcut(QKeySequence("Ctrl+T"));
    connect(newTab,&QAction::triggered,this,[=](){
        QString spaceName = QInputDialog::getText(this,tr("New Space Tab"),tr("Space Name"));
        if(!spaceName.isEmpty()){
            centralStackWidget->setCurrentWidget(spaceTabWidget);
            spaceTabWidget->addSpaceTab(spaceName);
        }
    });

    newWindow = new QAction(tr("New Window"));
    newWindow->setShortcut(QKeySequence("Ctrl+W"));
    connect(newWindow,&QAction::triggered,this,[=](){

    });
    open = new QAction(tr("Open"));
    open->setShortcuts(QKeySequence::Open);
    connect(open,&QAction::triggered,this,[=]{
        QStringList mediaFilePath = QFileDialog::getOpenFileNames(this, tr("Open File"),
                                                             QDir::homePath()+"\\Videos",
                                                             tr("Video(*.mp4 *.m3u8);;Audio(*.mp4 *.wav);;All (*.*)"));
        foreach (QString filePath,mediaFilePath) {
            QFileInfo fileInfo(filePath);
            mediaListWidget->AddMedia(fileInfo.fileName(),fileInfo.filePath());
        }
    });
    preferencs = new QAction(tr("Preferences"));
    connect(preferencs,&QAction::triggered,this,[=]{
        PreferencesDialog preferencesDialog(this);
        preferencesDialog.exec();
    });

    //edit actions
    undo = new QAction(tr("Undo"));
    undo->setShortcut(QKeySequence::Undo);
    redo = new QAction(tr("Redo"));
    redo->setShortcut(QKeySequence::Redo);

    //view actions


    //build actions
    buildproject = new QAction(tr("Build Project"));
    cleanproject = new QAction(tr("Clean Project"));

    //tools actions
    opencv = new QAction(tr("OpenCV"));
    ffmpeg = new QAction(tr("FFmpeg"));

    //space actions
    spaceLayout = new QAction(tr("Space layout"));
    spaceLayout->setShortcut(QKeySequence("Ctrl+L"));
    connect(spaceLayout,&QAction::triggered,this,[=]{
        NewSpaceLayoutDialog newSpaceLayoutDialog(this);
        connect(&newSpaceLayoutDialog,&NewSpaceLayoutDialog::UpdateSpaceLayout,this,[=](int rols,int cols,CommomEnum::SpaceType spaceType){
            if(currentSpaceTabWidget()!=nullptr){
                SpaceTab *tab = static_cast<SpaceTab*>(currentSpaceTabWidget());
                tab->editSelf(rols,cols,spaceType);
            }
            else{
                QMessageBox::warning(this,tr("Tips"),"Please new one space tab first!");
            }

        });
        newSpaceLayoutDialog.exec();
    });

    //help actions
    about = new QAction(tr("About"));
    aboutQt = new QAction(tr("AboutQt"));
    connect(aboutQt,&QAction::triggered,qApp,&QApplication::aboutQt);
    document = new QAction(tr("Document"));

}

void MainWindow::CreateMenus()
{
    //File menu
    file = new QMenu(tr("&File"));
    menuBar()->addMenu(file);
    file->addAction(newproject);
    file->addAction(newTab);
    file->addAction(newWindow);
    file->addSeparator();
    file->addAction(open);
    file->addSeparator();
    file->addAction(preferencs);

    //Edit menu
    edit = new QMenu(tr("&Edit"));
    menuBar()->addMenu(edit);
    edit->addAction(undo);
    edit->addAction(redo);

    //View menu
    view = new QMenu(tr("&View"));
    menuBar()->addMenu(view);
    view->addAction(topDockWidget->toggleViewAction());
    view->addAction(leftDockWidget->toggleViewAction());
    view->addAction(rightDockWidget->toggleViewAction());
    view->addAction(bottomDockWidget->toggleViewAction());


    //Build menu
    build = new QMenu(tr("&Build"));
    menuBar()->addMenu(build);
    build->addAction(buildproject);
    build->addAction(cleanproject);

    //Tools menu
    tools = new QMenu(tr("&Tools"));
    menuBar()->addMenu(tools);
    tools->addAction(opencv);
    tools->addAction(ffmpeg);

    //space menu
    space = new QMenu(tr("&Space"));
    menuBar()->addMenu(space);
    space->addAction(spaceLayout);

    //Help menu
    help = new QMenu(tr("&Help"));
    menuBar()->addMenu(help);
    help->addAction(about);
    help->addAction(aboutQt);
    help->addSeparator();
    help->addAction(document);


}

void MainWindow::CreateToolBars()
{
    fileToolBar = addToolBar(tr("fileToolBar"));
    fileToolBar->addAction(newproject);
    fileToolBar->addAction(open);
    fileToolBar->addAction(preferencs);

    helpToolBar = addToolBar(tr("helpToolBar"));
    helpToolBar->addAction(about);
    helpToolBar->addAction(aboutQt);

}

void MainWindow::CreateStatusBars()
{

}

void MainWindow::loadStyleSheet()
{
    QString qssFilePath = ":/qss/default.qss";
    QFile file(qssFilePath);
    if(file.open(QFile::ReadOnly)){
        qApp->setStyleSheet(QString::fromLocal8Bit(file.readAll()));
        file.close();
    }
}

void MainWindow::loadStyleSheet(QColor color)
{
    QString qssFilePath;
    if(color == Qt::white){
        qssFilePath = ":qss/white.qss";
    }
    else if(color == Qt::black){
        qssFilePath = ":qss/black.qss";
    }
    else{
        qssFilePath = ":qss/default.qss";
    }

    QFile file(qssFilePath);
    if(file.open(QFile::ReadOnly)){
        qApp->setStyleSheet(QString::fromLocal8Bit(file.readAll()));
        file.close();
    }
}

QWidget *MainWindow::currentSpaceTabWidget()
{
    return spaceTabWidget->currentWidget();
}






