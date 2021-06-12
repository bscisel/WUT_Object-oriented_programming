#include "addcategorydialog.h"
#include "ui_addcategorydialog.h"

AddCategoryDialog::AddCategoryDialog(QWidget *parent) : QDialog(parent),
                                                        ui(new Ui::AddCategoryDialog)
{
    ui->setupUi(this);
}

AddCategoryDialog::~AddCategoryDialog()
{
    delete ui;
}

void AddCategoryDialog::on_buttonBox_accepted()
{
    accept();
}

void AddCategoryDialog::on_buttonBox_rejected()
{
    reject();
}

QString AddCategoryDialog::get_name_from_input()
{
    return ui->categoryNameInput->text();
}