#include <iostream>
#include <QDialog>
#include <QFileDialog>
#include "mainwindow.h"
#include "adduserdialog.h"
#include "./ui_mainwindow.h"

Q_DECLARE_METATYPE(std::shared_ptr<User>)
Q_DECLARE_METATYPE(std::shared_ptr<Category>)
Q_DECLARE_METATYPE(Answered_question)

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          database(new Database),
                                          database_users(new Database_users("users.json"))
{
    ui->setupUi(this);
    if (database_users->open_file())
    {
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
    if (dialog.exec())
    {
        QString entered_user_name = dialog.get_name_from_input();
        if (!entered_user_name.isEmpty()) // trzeba to zrobic lepiej
        {
            std::shared_ptr<User> pointer_to_user = database_users->add_user(entered_user_name.toStdString());
            add_user_to_list(pointer_to_user, entered_user_name);
        }
    }
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_newGameButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_usersListWidget_itemDoubleClicked(QListWidgetItem *user_item)
{
    if (user_item != active_user)
        set_user_as_active(user_item);
}

void MainWindow::on_usersListWidget_itemSelectionChanged()
{
    ui->selectUserButton->setEnabled(true);
    if (ui->usersListWidget->currentItem() == active_user)
        ui->selectUserButton->setEnabled(false);
}

////////////////////////////////////////////////////
//                   2 PAGE                       //
////////////////////////////////////////////////////

void MainWindow::on_openFileButton_clicked()
{
    read_categories_from_file(QFileDialog::getOpenFileName(this, "Open database file", ".", "JSON Files (*.json)"));
}

void MainWindow::on_startButton_clicked()
{
    start_game();
}

void MainWindow::on_cancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_exitButton_2_clicked()
{
    close();
}

void MainWindow::on_categoriesListWidget_itemSelectionChanged()
{
    ui->startButton->setEnabled(true);
    if (ui->categoriesListWidget->selectedItems().empty())
        ui->startButton->setEnabled(false);
}


////////////////////////////////////////////////////
//                   3 PAGE                       //
////////////////////////////////////////////////////


void MainWindow::on_nextQuestionButton_clicked() {
    save_question();
    if (active_session->next_question_exist())
        display_next_question();
    else {
        active_session->end_session();
        get_pointer_to_active_user()->add_session(active_session);
        display_result(active_session);
        active_session = nullptr;
    }
}

void MainWindow::on_answersListWidget_itemClicked(QListWidgetItem *item) {
    display_answered_question(get_answered_question(item));
}

void MainWindow::on_backToMainMenuButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}


////////////////////////////////////////////////////
//                   FUNCTIONS                    //
////////////////////////////////////////////////////

std::shared_ptr<User> MainWindow::get_pointer_to_active_user() const
{
    return active_user->data(Qt::UserRole).value<std::shared_ptr<User>>();
}

std::shared_ptr<Category> MainWindow::get_pointer_to_category(QListWidgetItem *item) const
{
    return item->data(Qt::UserRole).value<std::shared_ptr<Category>>();
}

Answered_question MainWindow::get_answered_question(QListWidgetItem *item) const
{
    return item->data(Qt::UserRole).value<Answered_question>();
}

void MainWindow::set_user_as_active(QListWidgetItem *user_item)
{
    active_user = user_item;
    ui->activeUserLabel->setText(user_item->text());
    ui->selectUserButton->setEnabled(false);
    ui->newGameButton->setEnabled(true);
}

void MainWindow::load_users_into_widgetlist()
{
    for (auto &user : database_users->get_users())
    {
        add_user_to_list(user, QString::fromStdString(user->get_name()));
    }
}

void MainWindow::read_categories_from_file(QString file_name)
{
    if (database->open_file(file_name.toStdString()))
    {
        const auto &categories = database->get_categories();
        auto i = categories.size();
        database->read_data();
        for (; i != categories.size(); i++)
        { // -_-
            add_category_to_list(categories[i], QString::fromStdString(categories[i]->get_name()));
        }
    }
}

void MainWindow::add_user_to_list(const std::shared_ptr<User> &user, const QString &name)
{
    QListWidgetItem *new_user_on_list = new QListWidgetItem(name);
    QVariant data;
    data.setValue(user);
    new_user_on_list->setData(Qt::UserRole, data);
    ui->usersListWidget->addItem(new_user_on_list);
}

void MainWindow::add_category_to_list(const std::shared_ptr<Category> &category, const QString &name)
{
    QListWidgetItem *new_category_on_list = new QListWidgetItem(name);
    QVariant data;
    data.setValue(category);
    new_category_on_list->setData(Qt::UserRole, data);
    ui->categoriesListWidget->addItem(new_category_on_list);
}

void MainWindow::start_game()
{
    std::vector<std::shared_ptr<Category>> selected_categories;
    for (auto category : ui->categoriesListWidget->selectedItems()) {
        selected_categories.push_back(get_pointer_to_category(category));
        category->setSelected(false);
    }
    active_session = new Session();
    active_session->draw_questions(selected_categories, 3);
    ui->stackedWidget->setCurrentIndex(2);
    display_next_question();
}

void MainWindow::display_next_question()
{
    ui->questionTextLabel->setText(QString::fromStdString(active_session->get_current_question_text()));
    std::vector<std::string> answers_text = active_session->get_current_question_answers_text();
    ui->answer1Button->setText(QString::fromStdString(answers_text[0]));
    ui->answer2Button->setText(QString::fromStdString(answers_text[1]));
    ui->answer3Button->setText(QString::fromStdString(answers_text[2]));
    ui->answer4Button->setText(QString::fromStdString(answers_text[3]));
    ui->answer1Button->setChecked(false);
    ui->answer2Button->setChecked(false);
    ui->answer3Button->setChecked(false);
    ui->answer4Button->setChecked(false);
}

void MainWindow::display_result(const Session *session) {
    ui->stackedWidget->setCurrentIndex(3);
    ui->pointsLabel->setText(QString::number(session->get_points_scored()) + QString("/") + QString::number(session->get_points_to_score()));
    ui->answersListWidget->clear();
    uint8_t i = 1;
    for (auto &answered_question : session->get_answered_questions()) {
        QListWidgetItem *new_question_on_list = new QListWidgetItem(QString("Question ") + QString::number(i));
        QVariant data;
        data.setValue(answered_question);
        new_question_on_list->setData(Qt::UserRole, data);
        ui->answersListWidget->addItem(new_question_on_list);
        i++;
    }
    on_answersListWidget_itemClicked(ui->answersListWidget->item(0));
    ui->answersListWidget->setCurrentRow(0);
}

void MainWindow::display_answered_question(Answered_question question)
{
    const std::vector<Saved_answer> &answers = question.get_users_answers();
    ui->answeredQuestionLabel->setText(QString::fromStdString(question.get_text()));
    ui->answerPointsLabel->setText(QString::number(question.get_points_scored()) + QString("/") + QString::number(question.get_points()));
    display_answer(ui->answer1Mark, ui->answer1Label, answers[0]);
    display_answer(ui->answer2Mark, ui->answer2Label, answers[1]);
    display_answer(ui->answer3Mark, ui->answer3Label, answers[2]);
    display_answer(ui->answer4Mark, ui->answer4Label, answers[3]);
}

void MainWindow::display_answer(QLabel *mark, QLabel *text, Saved_answer answer) {
    text->setText(QString::fromStdString(answer.get_text()));
    if (answer.get_user_answer() && answer.is_correct()) {
        mark->setText(QString("✔"));
        mark->setStyleSheet("color: #1FC600");
        text->setStyleSheet("color: #1FC600");
    }
    else if (!answer.get_user_answer() && answer.is_correct()) {
        mark->setText(QString("✔"));
        mark->setStyleSheet("color: #1FC600");
        text->setStyleSheet("color: #FF0000");
    }
    else if (!answer.get_user_answer() && !answer.is_correct()) {
        mark->setText(QString(" "));
        mark->setStyleSheet("color: #000000");
        text->setStyleSheet("color: #000000");
    }
    else {
        mark->setText(QString("✘"));
        mark->setStyleSheet("color: #FF0000");
        text->setStyleSheet("color: #FF0000");
    }
}


void MainWindow::save_question() {
    Question *current_question = active_session->get_current_question();
    const std::vector<Answer> &answers = current_question->get_answers();
    std::vector<Saved_answer> user_answers;
    user_answers.push_back(Saved_answer(answers[0], ui->answer1Button->isChecked()));
    user_answers.push_back(Saved_answer(answers[1], ui->answer2Button->isChecked()));
    user_answers.push_back(Saved_answer(answers[2], ui->answer3Button->isChecked()));
    user_answers.push_back(Saved_answer(answers[3], ui->answer4Button->isChecked()));
    active_session->push_question(Answered_question(*current_question, 0, user_answers));
    std::cout << active_session->get_points_scored() << std::endl;
}
