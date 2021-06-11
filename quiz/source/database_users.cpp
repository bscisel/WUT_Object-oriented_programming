#include "database_users.hpp"

void to_json(json &j, const Saved_answer &saved_answer)
{
    j["text"] = saved_answer.get_text();
    j["correct"] = saved_answer.is_correct();
}

void to_json(json &j, const Answered_question &a_question)
{
    j = {{"user_answers", a_question.get_users_answers()}};
    j["points"] = a_question.get_points();
    j["text"] = a_question.get_text();
    j["correct_count"] = a_question.get_correct_answers_number();
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
        std::vector<Session> user_sessions;
        for (auto &session : user["user_sessions"])
        {
            std::vector<Answered_question> questions;
            for (auto &question : session["questions"])
            {
                std::vector<Saved_answer> user_answers;
                for (auto &saved_answer : question["user_answers"])
                {
                    user_answers.push_back(Saved_answer(
                        Answer(saved_answer["text"], saved_answer["correct"])));
                }
                questions.push_back(Answered_question(
                    Question(question["points"], question["text"], question["correct_count"]),
                    question["time"],
                    user_answers));
            }
            user_sessions.push_back(Session(session["start_time"],
                                            session["session_time"],
                                            session["points_scored"],
                                            questions));
        }
        users.push_back(std::make_shared<User>(user["name"], user["points"], user_sessions));
    }
    return true;
}

bool Database_users::save_to_file(std::string f_name)
{
    if (f_name.empty())
        f_name = file_name;

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

std::shared_ptr<User> Database_users::add_user(const std::string &name)
{
    std::shared_ptr<User> pointer_to_user{std::make_shared<User>(name)};
    users.push_back(pointer_to_user);
    return pointer_to_user;
}
