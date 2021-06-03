#include <iostream>
#include <QDialog>
#include "mainwindow.h"
#include "adduserdialog.h"
#include "./ui_mainwindow.h"

Q_DECLARE_METATYPE(std::shared_ptr<User>)


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          database(new Database),
                                          database_users(new Database_users("users.json"))
{
    ui->setupUi(this);
    if (database_users->open_file()) {
        database_users->read_data();
        load_users_into_widgetlist();
    }
    std::cout << database_users->get_users_number() << std::endl; 
}

void MainWindow::load_users_into_widgetlist() {
    for (auto &user : database_users->get_users()) {
        add_user_to_list(user, QString::fromStdString(user->get_name()));
    }
}

void MainWindow::add_user_to_list(const std::shared_ptr<User> &user, const QString &name) {
    QListWidgetItem *new_user_on_list = new QListWidgetItem(name);
    QVariant data;
    data.setValue(user);
    new_user_on_list->setData(Qt::UserRole, data);
    ui->usersListWidget->addItem(new_user_on_list);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete database;
    database_users->save_to_file();
    delete database_users;
    std::cout << "DESTRUCTOR" << std::endl;
}

void MainWindow::on_openFileButton_clicked()
{
    
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_addUserButton_clicked()
{
    AddUserDialog dialog(this);
    if(dialog.exec()) {
        QString entered_user_name = dialog.get_name_from_input();
        std::shared_ptr<User> pointer_to_user = database_users->add_user(entered_user_name.toStdString());
        add_user_to_list(pointer_to_user, entered_user_name);
    }
}