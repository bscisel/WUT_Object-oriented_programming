#include "session.hpp"
#include <chrono>
#include <algorithm>

uint64_t time()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

Session::Session(uint64_t start_time,
                 uint64_t session_time,
                 float points_scored,
                 std::vector<Answered_question> questions)
    : start_time(start_time),
      session_time(session_time),
      points_scored(points_scored),
      questions(questions)
{
    start_time = time();
}

void Session::end_session()
{
    session_time = time() - start_time;
}

float Session::count_points(const Answered_question &question) const
{
    unsigned short user_correct{0};
    unsigned short user_incorrect{0};
    unsigned short all_answers = question.get_number_answers();
    unsigned short correct_answers = question.get_correct_answers_count();
    for (auto answer : question.get_users_answers())
    {
        if (answer->is_correct())
            user_correct++;
        else
            user_incorrect++;
    }
    float points{0};

    if (!correct_answers)
        points += question.get_points();
    else
        points += question.get_points() * (user_correct / correct_answers);
    if (all_answers - correct_answers)
        points -= question.get_points() * (user_incorrect / (all_answers - correct_answers));
    return std::max(points, 0.f);
}
