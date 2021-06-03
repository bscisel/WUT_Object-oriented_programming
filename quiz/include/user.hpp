#ifndef USER_HPP
#define USER_HPP

#include "session.hpp"
#include <string>
#include <vector>

class User
{
private:
    static unsigned short user_counter;
    unsigned short user_id;
    std::string name;
    float points;
    std::vector<Session> user_sessions;

public:
    User(std::string name, float points = {0.f}, std::vector<Session> user_sessions = {})
        : name(name), points(points), user_sessions(user_sessions)
    {
        user_id = ++user_counter;
    };
    unsigned get_user_id() const { return user_id; } // potrzebne jest id??
    const std::string &get_name() const { return name; }
    void add_points(float session_result) { points += session_result; }
    float get_points() const { return points; }
    void add_session();
    const std::vector<Session> &get_user_sessions() const { return user_sessions; }
};

#endif