#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <vector>
#include "answer.hpp"

class Question
{
private:
    unsigned short points;
    std::string text;
    std::vector<Answer *> answers;

public:
    Question(unsigned short points, std::string text) : points(points), text(text) {}
    unsigned short get_points() const { return points; }
    const std::vector<Answer *> &get_answers() const { return answers; }
    const std::string &get_text() const { return text; }
    unsigned short get_number_answers() const { return answers.size(); }
    void add_answer(std::string text, bool is_correct);
};

class Answered_question : public Question
{
private:
    double time;
    std::vector<Answer *> user_answers;

public:
    Answered_question(Question question, double time,
                      std::vector<Answer *> user_answers) : Question(question),
                                                            time(time), user_answers(user_answers) {}
    const std::vector<Answer *> &get_answers() { return user_answers; }
    double get_time() { return time; }
    unsigned short get_number_user_answers() const { return user_answers.size(); }
};

#endif
