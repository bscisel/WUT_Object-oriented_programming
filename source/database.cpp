#include "database.hpp"
#include "category.hpp"
#include "question.hpp"
#include "nlohmann/json.hpp"

void to_json(json &j, const std::shared_ptr<Answer> answer)
{
    j = {{"text", answer->get_text()}};
    j["is_correct"] = answer->is_correct();
}

void to_json(json &j, const Question *question)
{
    j = {{"anwers", question->get_answers()}};
    j["text"] = question->get_text();
    j["points"] = question->get_points();
}

void to_json(json &j, const Category &cat)
{
    j = {{"questions", cat.get_questions()}};
    j["name"] = cat.get_name();
}

void to_json(json &j, const Database &base)
{
    j = {{"categories", base.get_categories()}};
}

bool Database::open_file(std::string f_name)
{
    if (f_name.empty())
        f_name = file_name;

    file.open(f_name);
    if (file)
    {
        file >> data;
        return true;
    }
    return false;
}

bool Database::read_data()
{
    if (file)
    {
        for (auto &category : data["categories"])
        {
            std::vector<Question *> questions;
            for (auto question : category["questions"])
            {
                Question *new_question = new Question(question["points"], question["text"]);
                for (auto answer : question["answers"])
                    new_question->add_answer(answer["text"], answer["is_correct"]);
                questions.push_back(new_question);
            }
            categories.push_back(Category(category["name"], questions));
        }
        return true;
    }
    return false;
}

bool Database::save_to_file(std::string f_name)
{
    if (f_name.empty() /* && f_name != file_name*/)
    {
        file.close();
        f_name = file_name;
        // file.open(f_name);
    }
    std::ofstream output(f_name);
    if (output)
    {
        to_json(data, *this);
        output << std::setw(4) << data << std::endl;
        return true;
    }
    return false;
}

void Database::add_category(std::string name, std::vector<Question *> questions)
{
    categories.push_back(Category(name, questions));
}
