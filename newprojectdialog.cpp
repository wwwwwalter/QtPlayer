#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"



NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);



    connect(ui->buttonBox,&QDialogButtonBox::clicked,this,[=](QAbstractButton *button){
        if(ui->buttonBox->buttonRole(button)==QDialogButtonBox::ApplyRole){

            switch (ui->tabWidget->currentIndex()) {
            case 0:
                emit UpdateMediaGrid(ui->tableView->selectedRowNum,ui->tableView->selectedColNum,0);
                break;
            case 1:
                emit UpdateMediaGrid(2,2,1);
                break;
            case 2:
                //emit UpdateMediaGrid(ui->tableView->selectedRowNum,ui->tableView->selectedColNum,0);
                break;
            default:
                break;
            }
        }
    });



}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}


