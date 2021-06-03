#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "nlohmann/json.hpp"
#include "category.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using json = nlohmann::json;

class Database
{
private:
    std::string file_name;
    std::vector<std::shared_ptr<Category>> categories;
    json data;

public:
    Database(const std::string &file_name = {}) : file_name(file_name){};
    bool open_file(std::string f_name = {});
    bool read_data();
    bool save_to_file(std::string f_name = {});
    const std::string &get_file_name() { return file_name; }
    std::shared_ptr<Category> add_category(const std::string &name, std::vector<Question *> questions = {});
    const std::vector<std::shared_ptr<Category>> &get_categories() const { return categories; }
    unsigned long get_categories_number() const { return categories.size(); }
    unsigned long get_questions_number() const;
};

#endif
