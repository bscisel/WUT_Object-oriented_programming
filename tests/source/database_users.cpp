#include "gtest/gtest.h"
#include "database_users.hpp"

TEST(database_user, create_users_database)
{
    Database_users database;
    database.add_user("Natalia");
    EXPECT_EQ(database.get_users_number(), 1);
    EXPECT_EQ(database.get_users()[0]->get_name(), "Natalia");
}


TEST(database_users, read_from_file)
{
    Database_users database_u;
    database_u.open_file("../../database_files/users_test.json");
    database_u.read_data();
    EXPECT_EQ(database_u.get_users_number(), 1);
    EXPECT_EQ(database_u.get_users()[0]->get_name(), "Natalia");
}
