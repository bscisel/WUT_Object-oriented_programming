#ifndef QUESTION_HPP
#define QUESTION_HPP

#include "answer.hpp"
#include <string>
#include <vector>
#include <chrono>
#include <cmath>

class Question
{
protected:
    unsigned short points;
    std::string text;
    std::vector<Answer> answers;
    unsigned short correct_count{0};

public:
    Question() = default;
    ~Question() = default;
    Question(const Question &) = default;
    Question(unsigned short points, const std::string &text, unsigned short correct_count = {0})
        : points(points), text(text), correct_count(correct_count) {}
    unsigned short get_points() const { return points; }
    const std::vector<Answer> &get_answers() const { return answers; }
    const std::string &get_text() const { return text; }
    unsigned short get_all_answers_number() const { return answers.size(); }
    unsigned short get_correct_answers_number() const { return correct_count; }
    void add_answer(const std::string &text, bool is_correct);
};

class Answered_question : public Question
{
private:
    uint64_t time;
    std::vector<Saved_answer> user_answers;
    float points_scored;

public:
    Answered_question() = default;
    ~Answered_question() = default;
    Answered_question(const Answered_question &) = default;
    Answered_question(const Question &question, uint64_t time,
                      std::vector<Saved_answer> user_answers = {})
        : Question(question),
          time(time),
          user_answers(user_answers) {}
    const std::vector<Saved_answer> &get_users_answers() const { return user_answers; }
    uint64_t get_time() const { return time; }
    float get_points_scored () const { return points_scored; }
    unsigned short get_user_answers_number() const { return user_answers.size(); }
    float count_points();
};

#endif
