#ifndef CATEGORY_HPP
#define CATEGORY_HPP

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
    Category(std::string name, std::vector<Question *> questions = {}) : name(name), questions(questions)
    {
        category_id = ++category_counter;
    }
    std::string get_name() const { return name; }
    void set_name(std::string new_name) { name = new_name; }
    unsigned short get_id() const { return category_id; }
    const std::vector<Question *> &get_questions() { return questions; }
    static unsigned get_number_categories() { return category_counter; } // nie w database?
    void add_question(Question *question) { questions.push_back(question); }
    int get_number_questions() { return questions.size(); }
};

#endif
