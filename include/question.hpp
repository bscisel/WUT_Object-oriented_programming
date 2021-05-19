#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <vector>
#include "answer.hpp"

class Question
{
private:
    unsigned short category_id;
    unsigned short points;
    std::string text;
    std::vector<Answer*> answers;

public:
    Question(unsigned short category_id, unsigned short points, std::string text) : category_id(category_id),
        points(points), text(text) {};
    unsigned short get_category_id() const { return category_id; }
    unsigned short get_points() const { return points; }
    const std::vector<Answer*> *get_answers() const { return &answers; }
    const std::string &get_text() const { return text; }
    unsigned short get_number_answers() const { return answers.size(); }

};

#endif
