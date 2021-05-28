#include "database.hpp"
#include "category.hpp"
#include "question.hpp"
#include "nlohmann/json.hpp"

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