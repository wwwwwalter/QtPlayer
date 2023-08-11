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
#include "medialistwidget.h"
#include "newprojectdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //mainwindow
    setWindowIcon(QIcon(":/images/logo2.png"));
    resize(1500,800);






    //central widget
    centralMainWidget = new QWidget;
    setCentralWidget(centralMainWidget);



    listMediaWidget = new QList<MediaWidget*>;
    ShowGridMediaWidgets(1,1);










    //widget
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







    //output



    //control



























    //top dock widget
    topDockWidget = new QDockWidget("AudioTrack",this);
    topDockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    addDockWidget(Qt::TopDockWidgetArea,topDockWidget);
    audioTrackWidget = new AudioTrackWidget;
    topDockWidget->setWidget(audioTrackWidget);
    topDockWidget->close();


    //left dock widget
    leftDockWidget = new QDockWidget(tr("MediaList"),this);
    addDockWidget(Qt::LeftDockWidgetArea,leftDockWidget);
    mediaListWidget = new MediaListWidget;
    leftDockWidget->setWidget(mediaListWidget);




    //right dock widget
    rightDockWidget = new QDockWidget(tr("Properties"),this);
    addDockWidget(Qt::RightDockWidgetArea,rightDockWidget);
    protertiesWidget = new PropertiesWidget;
    rightDockWidget->setWidget(protertiesWidget);



    //bottom dock widget
    bottomDockWidget = new QDockWidget(tr("VideoTrack"),this);
    bottomDockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    addDockWidget(Qt::BottomDockWidgetArea,bottomDockWidget);
    videoTrackWidget = new VideoTrackWidget;
    bottomDockWidget->setWidget(videoTrackWidget);





    //menu
    CreateActions();
    CreateMenus();
    //CreateToolBars();
    CreateStatusBars();


}

MainWindow::~MainWindow()
{
}

void MainWindow::ShowGridMediaWidgets(int rols, int cols)
{

    if(centralWidget()!=nullptr){
        //clean pre env
        delete centralWidget();
        centralMainWidget = new QWidget;
        setCentralWidget(centralMainWidget);
        QGridLayout *gridlayout = new QGridLayout;
        gridlayout->setSpacing(1);
        centralWidget()->setLayout(gridlayout);

        for (int i = 0; i < rols; ++i) {
            gridlayout->setRowMinimumHeight(i,150);
            for (int j = 0; j < cols; ++j) {
                gridlayout->setColumnMinimumWidth(j,200);
                MediaWidget *mediaWidget = new MediaWidget;
                listMediaWidget->append(mediaWidget);
                gridlayout->addWidget(mediaWidget,i,j);
            }
        }
    }
}

void MainWindow::ShowSplitterMediaWidgets(int rols, int cols)
{
    if(centralWidget()!=nullptr){
        //clean pre env
        delete centralWidget();
        QSplitter *splitterMain = new QSplitter(Qt::Vertical);
        QSplitter *splitterTop = new QSplitter(Qt::Horizontal);
        QSplitter *splitterBottom = new QSplitter(Qt::Horizontal);

        splitterMain->setHandleWidth(1);
        splitterTop->setHandleWidth(1);
        splitterBottom->setHandleWidth(1);

        MediaWidget *topLeft = new MediaWidget;
        MediaWidget *topRight = new MediaWidget;
        MediaWidget *bottomLeft = new MediaWidget;
        MediaWidget *bottomRight = new MediaWidget;
        splitterTop->addWidget(topLeft);
        splitterTop->addWidget(topRight);
        splitterBottom->addWidget(bottomLeft);
        splitterBottom->addWidget(bottomRight);
        splitterMain->addWidget(splitterTop);
        splitterMain->addWidget(splitterBottom);


        splitterTop->setStretchFactor(0,5);
        splitterTop->setStretchFactor(1,3);



        setCentralWidget(splitterMain);
    }
}

void MainWindow::CreateActions()
{
    //file actions
    newproject = new QAction(tr("New"));
    newproject->setShortcuts ( QKeySequence::New );
    connect(newproject,&QAction::triggered,this,[=]{
        NewProjectDialog newProjectDialog(this);
        connect(&newProjectDialog,&NewProjectDialog::UpdateMediaGrid,this,[=](int rols,int cols,int mediaWidgetStyle){
            switch (mediaWidgetStyle) {
            case 0:
                ShowGridMediaWidgets(rols,cols);
                break;
            case 1:
                ShowSplitterMediaWidgets();
                break;
            case 2:
                break;
            default:
                break;
            }

        });
        newProjectDialog.exec();
    });
    open = new QAction(tr("Open"));
    open->setShortcuts(QKeySequence::Open);
    connect(open,&QAction::triggered,this,[=]{
        QStringList mediaFilePath = QFileDialog::getOpenFileNames(this, tr("Open File"),
                                                             QDir::homePath()+"\\Videos",
                                                             tr("Videos(*.mp4 *.m3u8);;Music(*.mp4 *.wav);;All (*.*)"));
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
    file->addAction(open);
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

    //Help menu
    help = new QMenu(tr("&Help"));
    menuBar()->addMenu(help);
    help->addAction(about);
    help->addAction(aboutQt);
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






