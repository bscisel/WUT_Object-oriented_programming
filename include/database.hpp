#include "category.hpp"
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>
#include <string>
#include <iomanip>

using json = nlohmann::json;

class Database
{
private:
    std::string file_name;
    std::vector<Category> categories;
    json data;

public:
    Database(std::string file_name = {}) : file_name(file_name){};
    bool open_file(std::string f_name = {});
    bool read_data();
    bool save_to_file(std::string f_name = {});
    std::string get_file_name() { return file_name; }
    void add_category(std::string name, std::vector<Question *> questions = {});
    const std::vector<Category> &get_categories() const { return categories; }
};
