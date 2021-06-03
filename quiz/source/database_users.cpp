#include "database_users.hpp"
#include "user.hpp"
#include "nlohmann/json.hpp"
#include <memory>
#include <fstream>
#include <iomanip>

// void to_json(json &j, const std::shared_ptr<Answer> answer)
// {
//     j = {{"text", answer->get_text()}};
//     j["is_correct"] = answer->is_correct();
// }

// void to_json(json &j, const Question *question)
// {
//     j = {{"anwers", question->get_answers()}};
//     j["text"] = question->get_text();
//     j["points"] = question->get_points();
// }

void to_json(json &j, const std::shared_ptr<Answer> &answer)
{
    j["text"] = answer->get_text();
    j["is_correct"] = answer->is_correct();
}

void to_json(json &j, const Answered_question &a_question)
{
    j = {{"answers", a_question.get_answers()}};
    j = {{"user_answers", a_question.get_users_answers()}};
    j["points"] = a_question.get_points();
    j["text"] = a_question.get_text();
    j["correct_count"] = a_question.get_correct_answers_count();
    j["time"] = a_question.get_time();
}

void to_json(json &j, const Session &session)
{
    j = {{"questions", session.get_answered_questions()}};
    j["start_time"] = session.get_start_time();
    j["session_time"] = session.get_session_time();
    j["points_scored"] = session.get_points_scored();
}

void to_json(json &j, const std::shared_ptr<User> &user)
{
    j = {{"user_sessions", user->get_user_sessions()}};
    j["name"] = user->get_name();
    j["points"] = user->get_points();
}

void to_json(json &j, const Database_users &base)
{
    j = {{"users", base.get_users()}};
}

bool Database_users::open_file(std::string f_name)
{
    if (f_name.empty())
        f_name = file_name;

    std::ifstream input_file(f_name);
    if (input_file)
    {
        input_file >> data;
        input_file.close();
        return true;
    }
    return false;
}

bool Database_users::read_data()
{
    for (auto &user : data["users"])
    {
        // for (auto question : category["questions"])
        // {
        //     Question *new_question = new Question(question["points"], question["text"]);
        //     for (auto answer : question["answers"])
        //         new_question->add_answer(answer["text"], answer["is_correct"]);
        //     questions.push_back(new_question);
        // }
        users.push_back(std::make_shared<User>(user["name"], user["points"]));
    }
    return true;
}

bool Database_users::save_to_file(std::string f_name)
{
    if (f_name.empty())
    {
        f_name = file_name;
    }
    std::ofstream output_file(f_name);
    if (output_file)
    {
        to_json(data, *this);
        output_file << std::setw(4) << data << std::endl;
        output_file.close();
        return true;
    }
    return false;
}

std::shared_ptr<User> Database_users::add_user(std::string name)
{
    std::shared_ptr<User> pointer_to_user {std::make_shared<User>(name)};
    users.push_back(pointer_to_user);
    return pointer_to_user;
}
