#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include "database.hpp"
#include "database_users.hpp"
#include "session.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 1 page
    void on_selectUserButton_clicked();
    void on_addUserButton_clicked();
    void on_exitButton_clicked();
    void on_newGameButton_clicked();
    void on_usersListWidget_itemDoubleClicked(QListWidgetItem *user_item);
    void on_usersListWidget_itemSelectionChanged();
    
    // 2 page
    void on_openFileButton_clicked();
    void on_startButton_clicked();
    void on_addCategoryButton_clicked();
    void on_cancelButton_clicked();
    void on_exitButton_2_clicked();
    void on_categoriesListWidget_itemSelectionChanged();

    // 3 page
    void on_nextQuestionButton_clicked();
    void on_questionsListWidget_itemClicked(QListWidgetItem *item);
    void on_backToMainMenuButton_clicked();
    
private:
    Ui::MainWindow *ui;
    Database *database;
    Database_users *database_users;
    QListWidgetItem *active_user;
    Session *active_session;
    std::shared_ptr<User> get_pointer_to_active_user() const;
    std::shared_ptr<Category> get_pointer_to_category(QListWidgetItem *item) const;
    Answered_question get_answered_question(QListWidgetItem *item) const;
    
    void set_user_as_active(QListWidgetItem *user_item);
    
    void load_users_into_widgetlist();
    void read_categories_from_file(QString file_name);
    
    void add_user_to_list(const std::shared_ptr<User> &user, const QString &name);
    void add_category_to_list(const std::shared_ptr<Category> &category, const QString &name);

    void start_game();
    void display_next_question();
    void display_result(const Session *session);
    void display_answered_question(Answered_question question);
    void display_answer(QLabel *mark, QLabel *text, Saved_answer answer);
    void save_question();
};

#endif
