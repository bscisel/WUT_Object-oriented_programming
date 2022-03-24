#ifndef ADDCATEGORYDIALOG_H
#define ADDCATEGORYDIALOG_H

#include <QDialog>

namespace Ui
{
    class AddCategoryDialog;
}

class AddCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCategoryDialog(QWidget *parent = nullptr);
    ~AddCategoryDialog();
    /**
     * @brief Get the text from user input
     * @return QString Category name
     */
    QString get_name_from_input();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddCategoryDialog *ui;
};

#endif
