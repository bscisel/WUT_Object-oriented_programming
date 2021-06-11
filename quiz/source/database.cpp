#include "database.hpp"

void to_json(json &j, const Answer &answer)
{
    j["text"] = answer.get_text();
    j["is_correct"] = answer.is_correct();
}

void to_json(json &j, const Question *question)
{
    j = {{"answers", question->get_answers()}};
    j["points"] = question->get_points();
    j["text"] = question->get_text();
}

void to_json(json &j, const std::shared_ptr<Category> &cat)
{
    j = {{"questions", cat->get_questions()}};
    j["name"] = cat->get_name();
}

void to_json(json &j, const Database &base)
{
    j = {{"categories", base.get_categories()}};
}

bool Database::open_file(std::string f_name)
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

bool Database::read_data()
{
    for (auto &category : data["categories"])
    {
        std::vector<Question *> questions;
        for (auto &question : category["questions"])
        {
            Question *new_question = new Question(question["points"], question["text"]);
            for (auto &answer : question["answers"])
                new_question->add_answer(answer["text"], answer["is_correct"]);
            questions.push_back(new_question);
        }
        categories.push_back(std::make_shared<Category>(category["name"], questions));
    }
    return true;
}

bool Database::save_to_file(std::string f_name)
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

std::shared_ptr<Category> Database::add_category(const std::string &name, std::vector<Question *> questions) // przez wartosc?
{
    std::shared_ptr<Category> pointer_to_category {std::make_shared<Category>(name, questions)};
    categories.push_back(pointer_to_category);
    return pointer_to_category;
}

unsigned long Database::get_questions_number() const
{
    unsigned long sum = 0;
    for (auto &category : categories)
        sum += category->get_questions_number();
    return sum;
}