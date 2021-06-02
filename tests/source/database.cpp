#include "gtest/gtest.h"
#include "database.hpp"

TEST(database, create_database)
{
    Database database("test_data.json");
    database.open_file();
    database.read_data();
    EXPECT_EQ(database.get_file_name(), "test_data.json");
    EXPECT_EQ(database.get_categories().size(), 1);
    database.add_category("Kategoria X");
    EXPECT_EQ(database.get_categories().size(), 2);
}