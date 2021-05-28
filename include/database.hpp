#include "category.hpp"
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>

using json = nlohmann::json;

class Database
{
private:
    std::string file_name;
    std::ifstream file;
    std::vector<Category> categories;

public:
    json data;
    Database(std::string file_name = {}) : file_name(file_name){};
    ~Database()
    {
        file.close();
    };
    bool open_file(std::string f_name = {});
    bool read_data();
};
