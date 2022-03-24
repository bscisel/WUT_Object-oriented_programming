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
    void on_statisticsButton_clicked();
    void on_usersListWidget_itemDoubleClicked(QListWidgetItem *user_item);
    void on_usersListWidget_itemSelectionChanged();

    // 2 page
    void on_openFileButton_clicked();
    void on_startButton_clicked();
    void on_addCategoryButton_clicked();
    void on_addQuestionButton_clicked();
    void on_saveToFileButton_clicked();
    void on_cancelButton_clicked();
    void on_exitButton_2_clicked();
    void on_categoriesListWidget_itemSelectionChanged();

    // 3 page
    void on_nextQuestionButton_clicked();
    void on_questionsListWidget_itemClicked(QListWidgetItem *item);
    void on_backToMainMenuButton_clicked();
    void on_goToStatisticsButton_clicked();

    // 4 page
    void on_showButton_clicked();
    void on_backButton_clicked();
    void on_sessionResultsWidget_itemSelectionChanged();


private:
    Ui::MainWindow *ui; /**< Main Window */
    Database *database; /**< Database with categories */
    Database_users *database_users; /**< Database of users */
    QListWidgetItem *active_user; /**< Selected user item */
    Session *active_session; /**< Current seesion */
    bool came_from_statistics;
    /**
     * @brief Get the pointer to a User from the given item
     * @param user
     * @return std::shared_ptr<User>
     */
    std::shared_ptr<User> get_pointer_to_user(const QListWidgetItem *user) const;
    /**
     * @brief Get the pointer to a Category from the given item
     * @param item
     * @return std::shared_ptr<Category>
     */
    std::shared_ptr<Category> get_pointer_to_category(QListWidgetItem *item) const;
    /**
     * @brief Get the answered question from the given item
     * @param item
     * @return Answered_question
     */
    Answered_question get_answered_question(QListWidgetItem *item) const;

    /**
     * @brief Set selected item as an active user
     * @param user_item
     */
    void set_user_as_active(QListWidgetItem *user_item);
    /**
     * @brief Load users from database into the List widget
     */
    void load_users_into_widgetlist();
    /**
     * @brief Load database from file
     * Create items representing categories adn add them to a list widget.
     * @param file_name
     */
    void read_categories_from_file(QString file_name);
    /**
     * @brief Save database into a json file from user input
     */
    void save_database_to_file();

    /**
     * @brief Create an item representing user and add it to a list widget
     * @param user
     * @param name
     */
    void add_user_to_list(const std::shared_ptr<User> &user, const QString &name);
    /**
     * @brief Create an item representing category and add it to a list widget
     * @param category
     * @param name
     */
    void add_category_to_list(const std::shared_ptr<Category> &category, const QString &name);
    /**
     * @brief Read user input: question text, answers texts and correct value
     * Create a Question and add it to each of selected categories from list
     */
    void add_question();

    /**
     * @brief Create a new session, draw 5 questions from selected categories,
     * calls display_next_question()
     */
    void start_game();
    /**
     * @brief Read an active (not yet answered) question if exists from session container
     * Display question's text, set button's text to question's answers contents
     */
    void display_next_question();
    /**
     * @brief Read and display session data including list of answered questions
     * @param session
     */
    void display_result(const Session *session);
    /**
     * @brief Display question's text and all answers
     * Display user's mark and correctness for each answer
     * Calls display_answer()
     * @param question
     */
    void display_answered_question(Answered_question question);
    /**
     * @brief Displays an answer depening on its correctness and user's mark
     * @param mark
     * @param text
     * @param answer
     */
    void display_answer(QLabel *mark, QLabel *text, Saved_answer answer);
    /**
     * @brief Saves user's answers
     * Adds a pointer to an answered question to the session's container
     */
    void save_question();
    /**
     * @brief Read user's session,
     * Create item representing the sessions and display them in a list widget
     * @param user
     */
    void show_statistics_page(const std::shared_ptr<User> &user);
    /**
     * @brief Count total number of questions in selected categories
     * Used to unable a start of the session with too few questions
     * @return uint64_t
     */
    uint64_t count_questions_in_selected_categories();
};

#endif
