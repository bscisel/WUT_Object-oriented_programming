#ifndef DATABASE_USERS_HPP
#define DATABASE_USERS_HPP

#include "user.hpp"
#include "session.hpp"
#include <vector>


class Database_users
{
private:
    std::string file_name;
    std::vector<std::shared_ptr<User>> users;
    std::vector<Session> sessions;

public:
    Database_users(std::string file_name = {}) : file_name(file_name){};
    bool open_file(std::string f_name = {});
    bool read_data();
    bool save_to_file(std::string f_name = {});
    std::string get_file_name() { return file_name; }
    void add_user(std::string name);
    const std::vector<std::shared_ptr<User>> &get_users() const { return users; }
    unsigned long get_users_number() const { return users.size(); }
};

#endif
