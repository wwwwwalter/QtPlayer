#include "newspacelayoutdialog.h"
#include "ui_newspacelayoutdialog.h"


NewSpaceLayoutDialog::NewSpaceLayoutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSpaceLayoutDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Space layout"));



    connect(ui->buttonBox,&QDialogButtonBox::clicked,this,[=](QAbstractButton *button){
        if(ui->buttonBox->buttonRole(button)==QDialogButtonBox::ApplyRole){
            int rols = ui->tableView->selectedRowNum;
            int cols = ui->tableView->selectedColNum;

            switch (ui->tabWidget->currentIndex()) {
            case 0:
                emit UpdateSpaceLayout(rols,cols,CommomEnum::Grid);
                break;
            case 1:
                emit UpdateSpaceLayout(2,2,CommomEnum::Splitter);
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

NewSpaceLayoutDialog::~NewSpaceLayoutDialog()
{
    delete ui;
}


