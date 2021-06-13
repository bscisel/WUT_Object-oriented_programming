#ifndef SESSION_HPP
#define SESSION_HPP

#include "category.hpp"
#include "question.hpp"
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <random>

class Session
{
private:
    uint64_t start_time;
    uint64_t session_time;
    float points_scored{0.f};
    uint16_t points_to_score{0};
    std::vector<Answered_question> questions;
    std::vector<std::string> selected_categories_names;
    std::vector<Question *> randomly_selected_questions;
    uint8_t current_question_index{0};

public:
    Session();
    Session(uint64_t start_time,
            uint64_t session_time,
            float points_scored,
            uint16_t points_to_score,
            std::vector<Answered_question> questions,
            std::vector<std::string> selected_categories_names)
        : start_time(start_time),
          session_time(session_time),
          points_scored(points_scored),
          points_to_score(points_to_score),
          questions(questions),
          selected_categories_names(selected_categories_names) {}
    ~Session(){};
    void end_session();
    uint64_t get_start_time() const { return start_time; }
    uint64_t get_session_time() const { return session_time; }
    const std::vector<Answered_question> &get_answered_questions() const { return questions; }
    const std::vector<std::string> &get_selected_categories_names() const { return selected_categories_names; }
    const std::vector<Question *> &get_randomly_selected_questions() const { return randomly_selected_questions; }
    void push_question(Answered_question question);
    float get_points_scored() const { return points_scored; }
    uint8_t get_current_question_index() const { return current_question_index; }
    void draw_questions(const std::vector<std::shared_ptr<Category>> &selected_categories,
                        unsigned short int how_many);
    std::vector<std::string> get_current_question_answers_text();
    std::string get_current_question_text();
    Question *get_current_question();
    bool next_question_exist() { return current_question_index < randomly_selected_questions.size() ? true : false; }
    uint16_t get_points_to_score() const { return points_to_score; }
    std::string get_formatted_start_date() const;
    std::string get_formatted_session_time() const;
};

#endif
