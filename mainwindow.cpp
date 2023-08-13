#include "mainwindow.h"



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
#include <QIcon>
#include "newspacelayoutdialog.h"
#include <widgets/SpaceTab/spacetab.h>
#include "common/commomenum.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //mainwindow
    setWindowIcon(QIcon(QString::fromLocal8Bit(":/images/green/logo.svg")));
    setWindowTitle(tr("XPlayer"));
    loadStyleSheet();
    resize(1500,800);
    QApplication::setStyle(QStyleFactory::create("Fusion"));



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

































    //tabList dock widget
    tabListDockWidget = new QDockWidget(tr("TabList"),this);
    tabListDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea,tabListDockWidget);
    tabListView = new TabListView;
    tabListDockWidget->setWidget(tabListView);



    //playList dock widget
    playListDockWidget = new QDockWidget(tr("MediaPlayList"),this);
    playListDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea,playListDockWidget);
    playListWidget = new PlayListView;
    playListDockWidget->setWidget(playListWidget);

    //not combine audio & video track
    //tabListDockWidget->raise();



    //properties dock widget
    propertiesDockWidget = new QDockWidget(tr("Properties"),this);
    propertiesDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,propertiesDockWidget);
    protertiesWidget = new PropertiesWidget;
    propertiesDockWidget->setWidget(protertiesWidget);


    //audioTrack dock widget
    audioTrackDockWidget = new QDockWidget("AudioTrack",this);
    audioTrackDockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    QWidget *topDockTitleBar = new QWidget;
    audioTrackDockWidget->setTitleBarWidget(topDockTitleBar);
    addDockWidget(Qt::BottomDockWidgetArea,audioTrackDockWidget);
    audioTrackWidget = new AudioTrackWidget;
    audioTrackDockWidget->setWidget(audioTrackWidget);

    //videoTrack dock widget
    videoTrackDockWidget = new QDockWidget(tr("VideoTrack"),this);
    videoTrackDockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    QWidget *bottomDockTitleBar = new QWidget;
    videoTrackDockWidget->setTitleBarWidget(bottomDockTitleBar);
    addDockWidget(Qt::BottomDockWidgetArea,videoTrackDockWidget);
    videoTrackWidget = new VideoTrackWidget;
    videoTrackDockWidget->setWidget(videoTrackWidget);

    //combine audio & video track
    tabifyDockWidget(videoTrackDockWidget,audioTrackDockWidget);
    videoTrackDockWidget->raise();





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
        QString tabName = QInputDialog::getText(this,tr("New Space Tab"),tr("Tab Name"));
        if(!tabName.isEmpty()){
            centralStackWidget->setCurrentWidget(spaceTabWidget);
            spaceTabWidget->addSpaceTab(tabName);
            tabListView->addTab(tabName);
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
            playListWidget->addFile(fileInfo);
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
    connect(opencv,&QAction::triggered,this,[=]{
        tabListView->deleteMedia(currentSpaceTabWidgetIndex(),1);
    });

    //space actions
    spaceLayout = new QAction(tr("Space layout"));
    spaceLayout->setShortcut(QKeySequence("Ctrl+L"));
    connect(spaceLayout,&QAction::triggered,this,[=]{
        NewSpaceLayoutDialog newSpaceLayoutDialog(this);
        connect(&newSpaceLayoutDialog,&NewSpaceLayoutDialog::UpdateSpaceLayout,this,[=](int rols,int cols,CommomEnum::SpaceType spaceType){
            if(currentSpaceTabWidget()!=nullptr){
                SpaceTab *tab = static_cast<SpaceTab*>(currentSpaceTabWidget());
                tab->editSelf(rols,cols,spaceType);
                QList<QString> tabNamelist(rols*cols,tr("media"));
                tabListView->addMedias(currentSpaceTabWidgetIndex(),tabNamelist);
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

    view->addAction(tabListDockWidget->toggleViewAction());
    view->addAction(playListDockWidget->toggleViewAction());
    view->addAction(propertiesDockWidget->toggleViewAction());
    view->addAction(videoTrackDockWidget->toggleViewAction());
    view->addAction(audioTrackDockWidget->toggleViewAction());


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

int MainWindow::currentSpaceTabWidgetIndex()
{
    return spaceTabWidget->currentIndex();
}






