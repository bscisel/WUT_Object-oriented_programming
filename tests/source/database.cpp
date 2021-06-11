#include "gtest/gtest.h"
#include "database.hpp"

TEST(database, create_database)
{
    Database database;
    database.open_file("test_data.json");
    database.read_data();
    EXPECT_EQ(database.get_categories().size(), 1);
    auto categories = database.get_categories();
    EXPECT_EQ(categories[0]->get_questions()[0]->get_text(), "At which corner did Michael Schumacher break his leg in 1999?");
    const std::vector<Answer> answers = database.get_categories()[0]->get_questions()[0]->get_answers();
    EXPECT_EQ(answers.size(), 4);
}