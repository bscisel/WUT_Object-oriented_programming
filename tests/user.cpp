#include "gtest/gtest.h"
#include "user.hpp"

TEST (user, create_user)
{
    User user ("Natalia");
    EXPECT_EQ(user.get_name(), "Natalia");
    EXPECT_EQ(user.get_user_id(), 1);
    EXPECT_EQ(user.get_points(), 0);
    User user2 ("Bartek");
    EXPECT_EQ(user2.get_user_id(), 2);
}

TEST (user, add_session_result)
{
    User user2 ("Bartek");
    EXPECT_EQ(user2.get_points(), 0);
    user2.add_points(2.5);
    EXPECT_EQ(user2.get_points(), 2.5);
}