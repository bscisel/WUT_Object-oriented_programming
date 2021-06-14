#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "nlohmann/json.hpp"
#include "category.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using json = nlohmann::json;

/**
 * @brief Class Database
 * Upload and save categories with questions and their answers
 */
class Database
{
private:
    std::string file_name; /**< Name of the file of the database */
    std::vector<std::shared_ptr<Category>> categories; /**< Container with pointers to the categories */
    json data; /**< json instance to load and save databse */

public:
    /**
     * @brief Construct a new Database object
     * @param file_name
     */
    Database(const std::string &file_name = {}) : file_name(file_name){};
    /**
     * @brief Open a file if exists and load data to a json
     * @param f_name
     * @return true
     * @return false
     */
    bool open_file(std::string f_name = {});
    /**
     * @brief Read data from json instance into the container of categories
     * @return true
     * @return false
     */
    bool read_data();
    /**
     * @brief Save database (categories with questions and answers) to a file
     * @param f_name
     * @return true
     * @return false
     */
    bool save_to_file(std::string f_name = {});
    /**
     * @brief Get the name of a used file
     * @return const std::string&
     */
    const std::string &get_file_name() { return file_name; }
    /**
     * @brief Add a category to the container in the database
     * Returns a pointer to the newly aded category
     * @param name
     * @param questions
     * @return std::shared_ptr<Category>
     */
    std::shared_ptr<Category> add_category(const std::string &name, std::vector<Question *> questions = {});
    /**
     * @brief Get the container with pointers to all categories in the database
     * @return const std::vector<std::shared_ptr<Category>>&
     */
    const std::vector<std::shared_ptr<Category>> &get_categories() const { return categories; }
    /**
     * @brief Get the number of categories in the database
     * @return unsigned long
     */
    unsigned long get_categories_number() const { return categories.size(); }
    /**
     * @brief Get the number of questions in the database
     * @return unsigned long
     */
    unsigned long get_questions_number() const;
};

#endif
