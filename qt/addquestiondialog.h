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
    /**
     * @brief Get the question text from user input
     * @return QString Question text
     */
    QString get_question_text_from_input();
    /**
     * @brief Get the llst of contents for answers from user input
     * @return QList<QString>
     */
    QList<QString> get_answers_text();
    /**
     * @brief Get the value of correctness to each answer from user input
     * @return QList<bool>
     */
    QList<bool> get_answers_correct();
    /**
     * @brief Get the number of points for a question from user input
     * @return int
     */
    int get_number_of_points();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddQuestionDialog *ui;
};

#endif
