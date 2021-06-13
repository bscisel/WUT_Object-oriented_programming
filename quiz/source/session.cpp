#include "session.hpp"

uint64_t time()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

Session::Session()
{
    start_time = time();
}

void Session::end_session()
{
    session_time = time() - start_time;
    randomly_selected_questions.clear();
    current_question_index = 0;
}

void Session::push_question(Answered_question question)
{
    points_scored += question.count_points();
    questions.push_back(question);
    current_question_index++;
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
    for (auto &question : randomly_selected_questions)
        points_to_score += question->get_points();
}

std::vector<std::string> Session::get_current_question_answers_text()
{
    std::vector<std::string> result;
    for (auto &answer : randomly_selected_questions[current_question_index]->get_answers())
        result.push_back(answer.get_text());
    return result;
}

std::string Session::get_current_question_text()
{
    return randomly_selected_questions[current_question_index]->get_text();
}

Question *Session::get_current_question()
{
    return randomly_selected_questions[current_question_index];
}