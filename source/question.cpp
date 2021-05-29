#include "question.hpp"

void Question::add_answer(std::string text, bool is_correct)
{
    if (is_correct)
    {
        correct_count++;
        answers.push_back(std::make_shared<Correct_answer>(text));
    }
    else
        answers.push_back(std::make_shared<Wrong_answer>(text));
}

