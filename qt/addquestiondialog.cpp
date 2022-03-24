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

QList<QString> AddQuestionDialog::get_answers_text() {
    QList<QString> answers;
    answers.push_back(ui->answer1TextInput->text());
    answers.push_back(ui->answer2TextInput->text());
    answers.push_back(ui->answer3TextInput->text());
    answers.push_back(ui->answer4TextInput->text());
    return answers;
}

QList<bool> AddQuestionDialog::get_answers_correct() {
    QList<bool> result;
    result.push_back(ui->answer1CorrectCheckBox->isChecked());
    result.push_back(ui->answer2CorrectCheckBox->isChecked());
    result.push_back(ui->answer3CorrectCheckBox->isChecked());
    result.push_back(ui->answer4CorrectCheckBox->isChecked());
    return result;
}

int AddQuestionDialog::get_number_of_points() {
    return ui->numberOfPointsSpinBox->value();
}
