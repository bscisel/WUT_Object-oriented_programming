#include "gtest/gtest.h"
#include "answer.hpp"
#include "saved_answer.hpp"


TEST(saved_answer, create_saved_correct_answer)
{
    Answer answer("correct answer", true);
    Saved_answer u_answer(answer, true);
    EXPECT_EQ(u_answer.get_text(),"correct answer");
    EXPECT_TRUE(u_answer.is_correct());
    EXPECT_TRUE(u_answer.get_user_answer());
}

TEST(saved_answer, create_saved_wrong_answer)
{
    Answer answer("correct answer", false);
    Saved_answer u_answer(answer, true);
    EXPECT_EQ(u_answer.get_text(),"correct answer");
    EXPECT_FALSE(u_answer.is_correct());
    EXPECT_TRUE(u_answer.get_user_answer());
}
