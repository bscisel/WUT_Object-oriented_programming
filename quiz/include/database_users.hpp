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

/**
 * @brief class Database_user stores data of the users
 * Allows to upload users' data each time when the game is open
 * and saves the new data at the end of it
 */
class Database_users
{
private:
    std::string file_name; /**< Name of the file with users' data */
    std::vector<std::shared_ptr<User>> users; /**< Container with pointers to the User objects */
    json data;

public:
    /**
     * @brief Construct a new Database_users object
     * @param file_name
     */
    Database_users(const std::string &file_name = {}) : file_name(file_name){};
    /**
     * @brief Open the file with data, load into json instance
     * @param f_name
     * @return true
     * @return false
     */
    bool open_file(std::string f_name = {});
    /**
     * @brief Reads users' data from json into User pointers container
     * @return true
     * @return false
     */
    bool read_data();
    /**
     * @brief Save users' data to a json file
     * @param f_name
     * @return true
     * @return false
     */
    bool save_to_file(std::string f_name = {});
    /**
     * @brief Get the file name
     * @return const std::string&
     */
    const std::string &get_file_name() { return file_name; }
    /**
     * @brief Create a new User and add a pointer to the container
     * @param name
     * @return std::shared_ptr<User>
     */
    std::shared_ptr<User> add_user(const std::string &name);
    /**
     * @brief Get the container with pointers to the User objects
     * @return const std::vector<std::shared_ptr<User>>&
     */
    const std::vector<std::shared_ptr<User>> &get_users() const { return users; }
    /**
     * @brief Get the number of users in the database
     * @return unsigned long
     */
    unsigned long get_users_number() const { return users.size(); }
};

#endif
