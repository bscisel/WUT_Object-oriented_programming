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

TEST(answer, create_saved_correct_answer)
{
    Answer answer("correct answer", true);
    Saved_answer u_answer(answer, true);
    EXPECT_EQ(u_answer.get_text(),"correct answer");
    EXPECT_TRUE(u_answer.is_correct());
    EXPECT_TRUE(u_answer.get_user_answer());
}

TEST(answer, create_saved_wrong_answer)
{
    Answer answer("correct answer", false);
    Saved_answer u_answer(answer, true);
    EXPECT_EQ(u_answer.get_text(),"correct answer");
    EXPECT_FALSE(u_answer.is_correct());
    EXPECT_TRUE(u_answer.get_user_answer());
}