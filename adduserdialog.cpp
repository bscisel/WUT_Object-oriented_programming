#include "adduserdialog.h"
#include "ui_adduserdialog.h"

AddUserDialog::AddUserDialog(QWidget *parent) : QDialog(parent),
                                                ui(new Ui::AddUserDialog)
{
    ui->setupUi(this);
}

AddUserDialog::~AddUserDialog()
{
    qDebug("On faktycznie znika");
    delete ui;
}

void AddUserDialog::on_buttonBox_accepted() {
    accept();
}

void AddUserDialog::on_buttonBox_rejected() {
    reject();
}

QString AddUserDialog::get_name_from_input() {
    return ui->userNameInput->text();
}