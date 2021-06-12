#include "addquestiondialog.h"
#include "ui_addquestiondialog.h"

AddQuestionDialog::AddQuestionDialog(QWidget *parent) : QDialog(parent),
                                                        ui(new Ui::AddQuestionDialog)
{
    ui->setupUi(this);
}

AddQuestionDialog::~AddQuestionDialog()
{
    delete ui;
}

void AddQuestionDialog::on_buttonBox_accepted()
{
    accept();
}

void AddQuestionDialog::on_buttonBox_rejected()
{
    reject();
}

QString AddQuestionDialog::get_question_text_from_input()
{
    return ui->questionTextInput->text();
}