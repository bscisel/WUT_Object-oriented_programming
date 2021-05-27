#include "question.hpp"

void Question::add_answer(std::string text, bool is_correct)
{
    if (is_correct)
    {
        correct_count++;
        answers.push_back(new Correct_answer(text));
    }
    else
        answers.push_back(new Wrong_answer(text));
}