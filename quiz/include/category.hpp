#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include "nlohmann/json.hpp"
#include "question.hpp"
#include <string>
#include <vector>

class Category
{
private:
    static unsigned category_counter;
    unsigned category_id;
    std::string name;
    std::vector<Question *> questions;

public:
    Category(const std::string &name, std::vector<Question *> questions = {})
        : name(name),
          questions(questions)
    {
        category_id = ++category_counter;
    }
    ~Category();
    const std::string &get_name() const { return name; }
    void set_name(const std::string &new_name) { name = new_name; }
    unsigned short get_id() const { return category_id; }
    const std::vector<Question *> &get_questions() const { return questions; }
    void add_question(Question *question) { questions.push_back(question); }
    int get_questions_number() const { return questions.size(); }
    static unsigned get_categories_number() { return category_counter; }
};

#endif
