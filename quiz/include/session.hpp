#ifndef SESSION_HPP
#define SESSION_HPP

#include "question.hpp"
#include <vector>
#include <chrono>
#include <algorithm>

class Session
{
private:
    uint64_t start_time;
    uint64_t session_time;
    float points_scored{0.f};
    std::vector<Answered_question> questions;

public:
    Session(uint64_t start_time = {0},
            uint64_t session_time = {0},
            float points_scored = {0.f},
            std::vector<Answered_question> questions = {});
    void end_session();
    uint64_t get_start_time() const { return start_time; }
    uint64_t get_session_time() const { return session_time; }
    const std::vector<Answered_question> &get_answered_questions() const { return questions; }
    float count_points(const Answered_question &question) const;
    void push_question(Answered_question question)
    {
        questions.push_back(question);
        points_scored += count_points(question);
    }
    float get_points_scored() const { return points_scored; }
};

#endif
