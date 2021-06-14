#ifndef SESSION_HPP
#define SESSION_HPP

#include "category.hpp"
#include "question.hpp"
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <random>

/**
 * @brief Class Session represents user's session of the game.
 * Session's total time, session's start time,
 * number of points in total to score, points scored by the user.
 * Containers: names of selected categories,
 * randomly selected questions from chosen categories,
 * user's answers to selected questions.
 */
class Session
{
private:
    uint64_t start_time; /**< Session's start time */
    uint64_t session_time; /**< Session's duration */
    float points_scored{0.f}; /**< Points scored by the user during the session */
    uint16_t points_to_score{0}; /**< Maximum points that can be scored in the session */
    std::vector<Answered_question> questions; /**< Container of questions already answered by the user in the session */
    std::vector<std::string> selected_categories_names; /**< Container with names of selected categories to be used in the session as a database for questions */
    std::vector<Question *> randomly_selected_questions; /**< Container with pointers to randomly selected questions from selected database */
    uint8_t current_question_index{0}; /**< Index of the question to be answered */

public:
    /**
    * @brief Construct a new Session object
    * Used when starting a new session. Saves the session's start time.
    */
    Session();
    /**
     * @brief Construct a new Session object
     * Used to load a session from user's database.
     * @param start_time
     * @param session_time
     * @param points_scored
     * @param points_to_score
     * @param questions
     * @param selected_categories_names
     */
    Session(uint64_t start_time,
            uint64_t session_time,
            float points_scored,
            uint16_t points_to_score,
            std::vector<Answered_question> questions,
            std::vector<std::string> selected_categories_names)
        : start_time(start_time),
          session_time(session_time),
          points_scored(points_scored),
          points_to_score(points_to_score),
          questions(questions),
          selected_categories_names(selected_categories_names) {}
    ~Session(){};
    /**
     * @brief Ends the session.
     * Calculates duration of the session.
     * Cleans container of drawn questions, sets the current question index to 0.
     */
    void end_session();
    /**
     * @brief Get the session's start time
     * @return uint64_t
     */
    uint64_t get_start_time() const { return start_time; }
    /**
     * @brief Get the duration of the session
     * @return uint64_t
     */
    uint64_t get_session_time() const { return session_time; }
    /**
     * @brief Get the questions answered by the user during the session
     * @return const std::vector<Answered_question>&
     */
    const std::vector<Answered_question> &get_answered_questions() const { return questions; }
    /**
     * @brief Get the names of selected for the session categories
     * @return const std::vector<std::string>&
     */
    const std::vector<std::string> &get_selected_categories_names() const { return selected_categories_names; }
    /**
     * @brief Get the questions drawn during the session
     * @return const std::vector<Question *>&
     */
    const std::vector<Question *> &get_randomly_selected_questions() const { return randomly_selected_questions; }
    /**
     * @brief Add a question answered by the user to the session's container
     * Current question index increased.
     * Adds points scored for the question to the total amount of the points scored during the session
     * @param question
     */
    void push_question(Answered_question question);
    /**
     * @brief Get the points scored in the session
     * @return float
     */
    float get_points_scored() const { return points_scored; }
    /**
     * @brief Get the index of the current question
     * @return uint8_t
     */
    uint8_t get_current_question_index() const { return current_question_index; }
    /**
     * @brief Draw a question from questions from selected categories
     * Fills in names of selected categories and container with drawn questions.
     * Calculates the maximum points to score for a session
     * @param selected_categories container with pointers to seleceted categories
     * @param how_many number of questions to be drawn
     */
    void draw_questions(const std::vector<std::shared_ptr<Category>> &selected_categories,
                        unsigned short int how_many);
    /**
     * @brief Get the vector of contents of all answers to the current question
     * @return std::vector<std::string>
     */
    std::vector<std::string> get_current_question_answers_text();
    /**
     * @brief Get the current question text
     * @return std::string
     */
    std::string get_current_question_text();
    /**
     * @brief Get the pointer to the current question
     * @return Question*
     */
    Question *get_current_question();
    /**
     * @brief True if there are unaswered questions
     * @return true
     * @return false
     */
    bool next_question_exist() { return current_question_index < randomly_selected_questions.size() ? true : false; }
    /**
     * @brief Get the maximum total points for the session
     * @return uint16_t
     */
    uint16_t get_points_to_score() const { return points_to_score; }
    /**
     * @brief Get the formatted date of the session's start
     * @return std::string
     */
    std::string get_formatted_start_date() const;
    /**
     * @brief Get the formatted time of the session's duration
     * @return std::string
     */
    std::string get_formatted_session_time() const;
};

#endif
