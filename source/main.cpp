#include "database.hpp"
#include <iostream>

int main()
{
    Database siemka("data.json");
    siemka.open_file();
    siemka.read_data();
    
    std::cout << siemka.data["categories"][0]["name"] << std::endl;

}
