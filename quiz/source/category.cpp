#include "category.hpp"

unsigned Category::category_counter{0};

Category::~Category()
{
    for (auto &question : questions)
        delete question;
}
