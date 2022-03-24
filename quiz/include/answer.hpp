#ifndef ANSWER_HPP
#define ANSWER_HPP

#include <string>

/**
 * @brief Class Answer corresponds to an answer for a multiple-choice question.
 * Each answer has it's content and bool value denoting it's correctness.
 */
class Answer
{
protected:
    std::string text; /**< The content of the answer. */
    bool correct; /**< Correctness marker. */

public:
    /**
     * @brief Construct a new Answer object
     * @param text
     * @param is_correct
     */
    Answer(const std::string &text, bool is_correct) : text(text), correct(is_correct) {}
    /**
     * @brief Get the text object
     * @return const std::string&
     */
    const std::string &get_text() const { return text; };
    /**
     * @brief Get if answer is correct
     * @return true
     * @return false
     */
    bool is_correct() const { return correct; };
};

#endif
