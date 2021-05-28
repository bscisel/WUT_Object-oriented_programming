#ifndef USER_HPP
#define USER_HPP

#include <string>

class User
{
private:
    static unsigned user_counter;
    unsigned user_id;
    float points{0};
    std::string name;

public:
    User (std::string name) : name(name)
    {
        user_id = ++user_counter;
    };
    unsigned get_user_id() { return user_id; } //potrzebne jest id??
    std::string get_name() const { return name; }
    void add_points(float session_result) { points += session_result; }
    float get_points() const { return points; }
};

#endif