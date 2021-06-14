#ifndef QUESTION_HPP
#define QUESTION_HPP

#include "answer.hpp"
#include <string>
#include <vector>
#include <chrono>
#include <cmath>

/**
 * @brief class Question includes the text of the question, number of points to score,
 * containers of Answers objects as possible answers for the question
 * and number of good answers among them.
 */
class Question
{
protected:
    unsigned short points; /**< Number of points to score */
    std::string text; /**< The content of the question */
    std::vector<Answer> answers; /**< Container with possible answers to the question */
    unsigned short correct_count{0}; /**< Number of correct answers for the question */

public:
    Question() = default;
    ~Question() = default;
    Question(const Question &) = default;
    /**
     * @brief Construct a new Question object
     * @param points
     * @param text
     * @param correct_count
     */
    Question(unsigned short points, const std::string &text, unsigned short correct_count = {0})
        : points(points), text(text), correct_count(correct_count) {}
    /**
     * @brief Get the number of points to score for the question
     * @return unsigned short
     */
    unsigned short get_points() const { return points; }
    /**
     * @brief Get the container of answers
     * @return const std::vector<Answer>&
     */
    const std::vector<Answer> &get_answers() const { return answers; }
    /**
     * @brief Get the content of the quesion
     * @return const std::string&
     */
    const std::string &get_text() const { return text; }
    /**
     * @brief Get the number of all answers for the question
     * @return unsigned short
     */
    unsigned short get_all_answers_number() const { return answers.size(); }
    /**
     * @brief Get the number of correct answers for the question
     * @return unsigned short
     */
    unsigned short get_correct_answers_number() const { return correct_count; }
    /**
     * @brief Add an answer to the container
     * Pushes an Answer object to the container,
     * increases correct answers' counter if correct.
     * @param text
     * @param is_correct
     */
    void add_answer(const std::string &text, bool is_correct);
};

/**
 * @brief Class Answered_question is derrived from class Question,
 * extended by a container of user's answers to the question
 * and calculated number of points he scored.
 */
class Answered_question : public Question
{
private:
    std::vector<Saved_answer> user_answers; /**< Container with user's answers */
    float points_scored{0.f}; /**> Number of points scored by the user with given answers for the question */

public:
    Answered_question() = default;
    ~Answered_question() = default;
    Answered_question(const Answered_question &) = default;
    /**
     * @brief Construct a new Answered_question object
     * @param question
     * @param user_answers
     * @param points_scored
     */
    Answered_question(const Question &question,
                      std::vector<Saved_answer> user_answers = {},
                      float points_scored = {0})
        : Question(question),
          user_answers(user_answers),
          points_scored(points_scored) {}
    /**
     * @brief Get the user's answers
     * @return const std::vector<Saved_answer>&
     */
    const std::vector<Saved_answer> &get_users_answers() const { return user_answers; }
    /**
     * @brief Get the points scored for the question by the user
     * @return float
     */
    float get_points_scored() const { return points_scored; }
    /**
     * @brief Counts the points scored on the basis of user's answers
     * Called during a session.
     * @return float
     */
    float count_points();
};

#endif
