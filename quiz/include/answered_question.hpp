#ifndef ANSWERED_QUESTION_HPP
#define ANSWERED_QUESTION_HPP

#include "question.hpp"

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
