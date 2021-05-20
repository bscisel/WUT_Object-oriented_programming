#include "gtest/gtest.h"
#include "answer.hpp"

TEST(answer, create_correct_answer)
{
    Correct_answer answer("answer");
    EXPECT_EQ(answer.get_text(), "answer");
}

TEST(answer, create_wrong_answer)
{
    Wrong_answer answer("answer");
    EXPECT_EQ(answer.get_text(), "answer");
    EXPECT_NE(answer.get_text(), "awdwd");
}

