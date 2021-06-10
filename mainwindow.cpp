#include <iostream>
#include <QDialog>
#include <QFileDialog>
#include "mainwindow.h"
#include "adduserdialog.h"
#include "./ui_mainwindow.h"

Q_DECLARE_METATYPE(std::shared_ptr<User>)
Q_DECLARE_METATYPE(std::shared_ptr<Category>)


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

MainWindow::~MainWindow()
{
    delete ui;
    delete database;
    database_users->save_to_file();
    delete database_users;
    std::cout << "DESTRUCTOR" << std::endl;
}


////////////////////////////////////////////////////
//                   1 PAGE                       //
////////////////////////////////////////////////////

void MainWindow::on_selectUserButton_clicked()
{
    QListWidgetItem *user_item = ui->usersListWidget->currentItem();
    set_user_as_active(user_item);
}

void MainWindow::on_addUserButton_clicked()
{
    AddUserDialog dialog(this);
    if (dialog.exec()) {
        QString entered_user_name = dialog.get_name_from_input();
        if (!entered_user_name.isEmpty()) // trzeba to zrobic lepiej
        {
            std::shared_ptr<User> pointer_to_user = database_users->add_user(entered_user_name.toStdString());
            add_user_to_list(pointer_to_user, entered_user_name);
        }
    }
}

void MainWindow::on_exitButton_clicked() {
    close();
}

void MainWindow::on_newGameButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_usersListWidget_itemDoubleClicked(QListWidgetItem *user_item) {
    if (user_item != active_user)
        set_user_as_active(user_item);
}

void MainWindow::on_usersListWidget_itemSelectionChanged() {
    ui->selectUserButton->setEnabled(true);
    if (ui->usersListWidget->currentItem() == active_user)
        ui->selectUserButton->setEnabled(false);
}


////////////////////////////////////////////////////
//                   2 PAGE                       //
////////////////////////////////////////////////////

void MainWindow::on_selectCategoryButton_clicked() {
    QListWidgetItem *item = ui->categoriesListWidget->currentItem();
    set_category_as_selected(item);
}

void MainWindow::on_openFileButton_clicked()
{
    read_categories_from_file(QFileDialog::getOpenFileName(this, "Open database file", ".", "JSON Files (*.json)"));
}

void MainWindow::on_cancelButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_exitButton_2_clicked() {
    close();
}

void MainWindow::on_categoriesListWidget_itemDoubleClicked(QListWidgetItem *item) {
    if (item != selected_category)
        set_category_as_selected(item);
}

void MainWindow::on_categoriesListWidget_itemSelectionChanged() {
    ui->selectCategoryButton->setEnabled(true);
    if (ui->categoriesListWidget->currentItem() == selected_category)
        ui->selectCategoryButton->setEnabled(false);
}

////////////////////////////////////////////////////
//                   FUNCTIONS                    //
////////////////////////////////////////////////////

std::shared_ptr<User> MainWindow::get_pointer_to_active_user() const {
    return active_user->data(Qt::UserRole).value<std::shared_ptr<User>>();
}

std::shared_ptr<Category> MainWindow::get_pointer_to_selected_category() const {
    return selected_category->data(Qt::UserRole).value<std::shared_ptr<Category>>();
}

void MainWindow::set_user_as_active(QListWidgetItem *user_item) {
    active_user = user_item;
    ui->activeUserLabel->setText(user_item->text());
    ui->selectUserButton->setEnabled(false);
    ui->newGameButton->setEnabled(true);
}

void MainWindow::set_category_as_selected(QListWidgetItem *item) {
    selected_category = item;
    ui->selectedCategoryLabel->setText(item->text());
    ui->selectCategoryButton->setEnabled(false);
    ui->startButton->setEnabled(true);
}

void MainWindow::load_users_into_widgetlist() {
    for (auto &user : database_users->get_users()) {
        add_user_to_list(user, QString::fromStdString(user->get_name()));
    }
}

void MainWindow::read_categories_from_file(QString file_name) {
    if (database->open_file(file_name.toStdString())) {
        const auto &categories = database->get_categories();
        auto i = categories.size();
        database->read_data();
        for ( ; i != categories.size(); i++) { // -_-
            add_category_to_list(categories[i], QString::fromStdString(categories[i]->get_name()));
        }
    }
}

void MainWindow::add_user_to_list(const std::shared_ptr<User> &user, const QString &name) {
    QListWidgetItem *new_user_on_list = new QListWidgetItem(name);
    QVariant data;
    data.setValue(user);
    new_user_on_list->setData(Qt::UserRole, data);
    ui->usersListWidget->addItem(new_user_on_list);
}

void MainWindow::add_category_to_list(const std::shared_ptr<Category> &category, const QString &name) {
    QListWidgetItem *new_category_on_list = new QListWidgetItem(name);
    QVariant data;
    data.setValue(category);
    new_category_on_list->setData(Qt::UserRole, data);
    ui->categoriesListWidget->addItem(new_category_on_list);
}
