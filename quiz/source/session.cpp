#include "session.hpp"

uint64_t time()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

Session::Session(uint64_t start_time,
                 uint64_t session_time,
                 float points_scored,
                 std::vector<Answered_question> questions,
                 std::vector<std::string> selected_categories_names)
    : start_time(start_time),
      session_time(session_time),
      points_scored(points_scored),
      questions(questions),
      selected_categories_names(selected_categories_names)
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
    unsigned short all_answers = question.get_all_answers_number();
    unsigned short correct_answers = question.get_correct_answers_number();
    for (auto &answer : question.get_users_answers())
    {
        if (answer.is_correct())
            user_correct++;
        else
            user_incorrect++;
    }
    float points{0};

    if (!correct_answers)
        points += question.get_points();
    else
        points += question.get_points() * (static_cast<float>(user_correct) / correct_answers);
    if (all_answers - correct_answers)
        points -= question.get_points() * (static_cast<float>(user_incorrect) / (all_answers - correct_answers));
    return std::max(points, 0.f);
}

void Session::draw_questions(const std::vector<std::shared_ptr<Category>> &selected_categories,
                             unsigned short int how_many)
{
    std::vector<Question *> all_questions;
    for (auto category : selected_categories)
    {
        selected_categories_names.push_back(category->get_name());
        all_questions.insert(all_questions.end(), category->get_questions().begin(), category->get_questions().end());
    }
    std::sample(all_questions.begin(), all_questions.end(),
                std::back_inserter(randomly_selected_questions), how_many,
                std::mt19937{std::random_device{}()});
}