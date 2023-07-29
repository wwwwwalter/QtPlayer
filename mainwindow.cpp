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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //mainwindow
    setWindowIcon(QIcon(":/images/logo2.png"));
    QApplication::setStyle(QStyleFactory::create("fusion"));

    //menu bar
    //File
    fileMenu = new QMenu(tr("File"));
    menuBar()->addMenu(fileMenu);

    //View
    viewMenu = new QMenu(tr("View"));
    menuBar()->addMenu(viewMenu);


    //Tools
    toolMenu = new QMenu(tr("Tools"));
    menuBar()->addMenu(toolMenu);

    //Help
    helpMenu = new QMenu(tr("Help"));
    changeStyleMenu = new QMenu(tr("change style"));




    QActionGroup *actionGroup= new QActionGroup(changeStyleMenu);
    //changeStyleMenu->addSection(tr("test"));
    QAction *windowsvista = new QAction(tr("windowsvista"));
    QAction *windows = new QAction(tr("windows"));
    QAction *fusion = new QAction(tr("fusion"));
    actionGroup->addAction(windowsvista);
    actionGroup->addAction(windows);
    actionGroup->addAction(fusion);

    changeStyleMenu->addAction(windowsvista);
    changeStyleMenu->addAction(windows);
    changeStyleMenu->addAction(fusion);
    changeStyleMenu->setDefaultAction(windowsvista);


    aboutAction = new QAction(tr("about"));
    aboutQtAction = new QAction(tr("about Qt"));
    helpMenu->addMenu(changeStyleMenu);
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
    menuBar()->addMenu(helpMenu);

    connect(aboutQtAction,&QAction::triggered,qApp,&QApplication::aboutQt);
    connect(windowsvista,&QAction::triggered,this,&MainWindow::UpdateStyleWindowsVista);
    connect(windows,&QAction::triggered,this,&MainWindow::UpdateStyleWindows);
    connect(fusion,&QAction::triggered,this,&MainWindow::UpdateStyleFusion);



    //central widget
    centralWidget = new QWidget;
    setCentralWidget(centralWidget);
    listMediaWidget = new QList<MediaWidget*>;
    QGridLayout *gridlayout = new QGridLayout;
    gridlayout->setSpacing(1);

    centralWidget->setLayout(gridlayout);


    for (int i = 0; i < 3; ++i) {
        gridlayout->setRowMinimumHeight(i,150);
        for (int j = 0; j < 3; ++j) {
            gridlayout->setColumnMinimumWidth(j,200);
            MediaWidget *mediaWidget = new MediaWidget;
            listMediaWidget->append(mediaWidget);
            gridlayout->addWidget(mediaWidget,i,j);
        }
    }







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

void MainWindow::UpdateStyleWindowsVista()
{
    QApplication::setStyle(QStyleFactory::create("windowsvista"));
}

void MainWindow::UpdateStyleWindows()
{
    QApplication::setStyle(QStyleFactory::create("windows"));
}

void MainWindow::UpdateStyleFusion()
{
    QApplication::setStyle(QStyleFactory::create("fusion"));
}




