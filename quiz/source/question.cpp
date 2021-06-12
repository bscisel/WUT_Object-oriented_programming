#include "question.hpp"

void Question::add_answer(const std::string &text, bool is_correct)
{
    answers.push_back(Answer(text, is_correct));
    if (is_correct)
        correct_count++;
}

float Answered_question::count_points()
{
    uint8_t user_correct{0};
    uint8_t user_incorrect{0};
    // uint8_t all_answers = question.get_all_answers_number();
    uint8_t correct_answers = get_correct_answers_number();
    for (auto &answer : get_users_answers())
    {
        if (answer.get_user_answer()) {
            if (answer.is_correct())
                user_correct++;
            else
                user_incorrect++;
        }
    }
    float points{0};

    if (!correct_answers)
        points += get_points();
    else
        points += get_points() * (static_cast<float>(user_correct) / correct_answers);
    points *= pow(0.5, user_incorrect);
    points_scored = points;
    return points;
}