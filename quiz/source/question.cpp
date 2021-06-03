#include "question.hpp"

void Question::add_answer(const std::string &text, bool is_correct)
{
    answers.push_back(Answer(text, is_correct));
    if (is_correct)
        correct_count++;
}
