#ifndef ADDQUESTIONDIALOG_H
#define ADDQUESTIONDIALOG_H

#include <QDialog>

namespace Ui
{
    class AddQuestionDialog;
}

class AddQuestionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddQuestionDialog(QWidget *parent = nullptr);
    ~AddQuestionDialog();
    QString get_question_text_from_input();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddQuestionDialog *ui;
};

#endif
