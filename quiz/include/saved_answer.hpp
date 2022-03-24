#ifndef SAVED_ANSWER_HPP
#define SAVED_ANSWER_HPP

#include "answer.hpp"

/**
 * @brief Saved_answer class is an object derrived from a base class Answer extended by
 * user's mark for the answer (true or false).
 *
 */
class Saved_answer : public Answer
{
    bool user_answer; /**< Saves if user marked the answer as correct */

public:
    /**
     * @brief Construct a new Saved_answer object
     * @param answer
     * @param user_answer
     */
    Saved_answer(const Answer &answer, bool user_answer)
        : Answer(answer), user_answer(user_answer) {}
    /**
     * @brief Get the user mark
     * @return true
     * @return false
     */
    bool get_user_answer() const { return user_answer; };
};

#endif
