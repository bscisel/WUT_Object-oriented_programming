#ifndef SESSION_HPP
#define SESSION_HPP

#include "category.hpp"
#include "question.hpp"
#include <vector>
#include <chrono>
#include <algorithm>
#include <memory>
#include <random>

class Session
{
private:
    uint64_t start_time;
    uint64_t session_time;
    float points_scored{0.f};
    std::vector<Answered_question> questions;
    std::vector<std::string> selected_categories_names;
    std::vector<Question *> randomly_selected_questions;
    unsigned short int current_question_index = 0;

public:
    Session(uint64_t start_time = {0},
            uint64_t session_time = {0},
            float points_scored = {0.f},
            std::vector<Answered_question> questions = {},
            std::vector<std::string> selected_categories_names = {});
    void end_session();
    uint64_t get_start_time() const { return start_time; }
    uint64_t get_session_time() const { return session_time; }
    const std::vector<Answered_question> &get_answered_questions() const { return questions; }
    const std::vector<std::string> &get_selected_categories_names() const { return selected_categories_names; }
    const std::vector<Question *> &get_randomly_selected_questions() const { return randomly_selected_questions; }
    float count_points(const Answered_question &question) const;
    void push_question(Answered_question question)
    {
        questions.push_back(question);
        points_scored += count_points(question);
        current_question_index++;
    }
    float get_points_scored() const { return points_scored; }
    unsigned short int get_current_question_index() const { return current_question_index; }
    void draw_questions(const std::vector<std::shared_ptr<Category>> &selected_categories,
                        unsigned short int how_many);
};

#endif
