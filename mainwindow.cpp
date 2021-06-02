#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "database.hpp"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFile_clicked() {
    Database data;
    std::cout << "siema" << std::endl;
}

void MainWindow::on_exitButton_clicked() {
    std::cout << "siema2" << std::endl;
}