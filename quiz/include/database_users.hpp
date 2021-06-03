#ifndef DATABASE_USERS_HPP
#define DATABASE_USERS_HPP

#include "nlohmann/json.hpp"
#include "user.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <memory>

using json = nlohmann::json;

class Database_users
{
private:
    std::string file_name;
    std::vector<std::shared_ptr<User>> users;
    json data;

public:
    Database_users(const std::string &file_name = {}) : file_name(file_name){};
    bool open_file(std::string f_name = {});
    bool read_data();
    bool save_to_file(std::string f_name = {});
    const std::string &get_file_name() { return file_name; }
    std::shared_ptr<User> add_user(const std::string &name);
    const std::vector<std::shared_ptr<User>> &get_users() const { return users; }
    unsigned long get_users_number() const { return users.size(); }
};

#endif
