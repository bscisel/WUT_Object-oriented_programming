#include <iostream>
#include <QDialog>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          database(new Database),
                                          database_users(new Database_users("users.json"))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete database;
    delete database_users;
    std::cout << "DESTRUCTOR" << std::endl;
}

void MainWindow::on_openFileButton_clicked()
{
    Database data;
    std::cout << "siema" << std::endl;
}

void MainWindow::on_exitButton_clicked()
{
    std::cout << "siema2" << std::endl;
}

void MainWindow::on_addUserButton_clicked()
{
    QDialog dialog(this);
    dialog.exec();
    std::cout << "siema2" << std::endl;
}