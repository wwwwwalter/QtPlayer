#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"

#include <QStandardItemModel>
#include <QStyleFactory>

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);


    //left setting list
    QStandardItemModel *model = new QStandardItemModel(8,1);
    model->setData(model->index(0,0),"Environment");
    model->setData(model->index(1,0),"Environment");
    model->setData(model->index(2,0),"Environment");
    model->setData(model->index(3,0),"Environment");
    model->setData(model->index(4,0),"Environment");
    model->setData(model->index(5,0),"Environment");
    model->setData(model->index(6,0),"Environment");
    model->setData(model->index(7,0),"Environment");
    ui->settingList->setModel(model);


    //Environment
    ui->themeComboBox->addItems(QStyleFactory::keys());
    connect(ui->themeComboBox,&QComboBox::currentIndexChanged,[=]{
        QApplication::setStyle(QStyleFactory::create(ui->themeComboBox->currentText()));
    });






}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}
