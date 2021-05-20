#include "gtest/gtest.h"
#include "question.hpp"
#include "answer.hpp"

TEST(question, create_question)
{
    Question question1(1, 3, "Question?");
    EXPECT_EQ(question1.get_points(), 3);
    EXPECT_NE(question1.get_points(), 5);
    EXPECT_EQ(question1.get_category_id(), 1);
    EXPECT_NE(question1.get_category_id(), 2);
    EXPECT_EQ(question1.get_text(), "Question?");
    EXPECT_EQ(question1.get_number_answers(), 0);
}

TEST(question, question_add_answer)
{
    Question question1(1, 3, "Question?");
    EXPECT_EQ(question1.get_points(), 3);
    EXPECT_EQ(question1.get_category_id(), 1);
    EXPECT_EQ(question1.get_text(), "Question?");
    EXPECT_EQ(question1.get_number_answers(), 0);
    question1.add_answer("Odpowiedz A", true);
    question1.add_answer("Odpowiedz B", false);
    question1.add_answer("Odpowiedz C", false);
    question1.add_answer("Odpowiedz D", true);
    EXPECT_EQ(question1.get_number_answers(), 4);
    const std::vector<Answer *> user_answers = question1.get_answers();
    EXPECT_TRUE(user_answers[0]->is_correct());
    EXPECT_FALSE(user_answers[1]->is_correct());
    EXPECT_FALSE(user_answers[2]->is_correct());
    EXPECT_TRUE(user_answers[3]->is_correct());
}
