#ifndef SESSION_HPP
#define SESSION_HPP

#include "question.hpp"
#include <chrono>
#include <vector>

class Session
{
private:
    uint64_t start_time;
    uint64_t session_time;
    float points_scored{0};
    std::vector<Answered_question> questions;

public:
    Session();
    void end_session();
    uint64_t get_session_time() { return session_time; }
    const std::vector<Answered_question> &get_answered_questions() { return questions; }
    float count_points(const Answered_question &question) const;
    void push_question(Answered_question question)
    {
        questions.push_back(question);
        points_scored += count_points(question);
    }
    float get_points_scored() const { return points_scored; }
};

#endif
