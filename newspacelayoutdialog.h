#ifndef NEWSPACELAYOUTDIALOG_H
#define NEWSPACELAYOUTDIALOG_H

#include <QDialog>
#include "common/commomenum.h"


namespace Ui {
class NewSpaceLayoutDialog;
}

class NewSpaceLayoutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewSpaceLayoutDialog(QWidget *parent = nullptr);
    ~NewSpaceLayoutDialog();

signals:
    void UpdateSpaceLayout(int rols,int cols,CommomEnum::SpaceType spaceLayoutType);





private:
    Ui::NewSpaceLayoutDialog *ui;


};

#endif // NEWSPACELAYOUTDIALOG_H
