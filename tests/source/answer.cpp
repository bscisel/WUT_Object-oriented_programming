#include "gtest/gtest.h"
#include "answer.hpp"

TEST(answer, create_correct_answer)
{
    Answer answer("correct answer", true);
    EXPECT_EQ(answer.get_text(), "correct answer");
    EXPECT_TRUE(answer.is_correct());
}

TEST(answer, create_wrong_answer)
{
    Answer answer("wrong answer", false);
    EXPECT_EQ(answer.get_text(), "wrong answer");
    EXPECT_FALSE(answer.is_correct());
}
