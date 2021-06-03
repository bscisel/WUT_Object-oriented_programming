#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>

namespace Ui
{
    class AddUserDialog;
}

class AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserDialog(QWidget *parent = nullptr);
    ~AddUserDialog();
    QString get_name_from_input();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddUserDialog *ui;
};

#endif
