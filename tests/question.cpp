#include "gtest/gtest.h"
#include "question.hpp"
#include "answer.hpp"
#include <memory>

TEST(question, create_question)
{
    Question question1(3, "Question?");
    EXPECT_EQ(question1.get_points(), 3);
    EXPECT_NE(question1.get_points(), 5);
    EXPECT_EQ(question1.get_text(), "Question?");
    EXPECT_EQ(question1.get_number_answers(), 0);
}

TEST(question, question_add_answer)
{
    Question question1(3, "Question?");
    EXPECT_EQ(question1.get_points(), 3);
    EXPECT_EQ(question1.get_text(), "Question?");
    EXPECT_EQ(question1.get_number_answers(), 0);
    question1.add_answer("Odpowiedz A", true);
    question1.add_answer("Odpowiedz B", false);
    question1.add_answer("Odpowiedz C", false);
    question1.add_answer("Odpowiedz D", true);
    EXPECT_EQ(question1.get_number_answers(), 4);
    const std::vector <std::shared_ptr <Answer>> user_answers = question1.get_answers();
    EXPECT_TRUE(user_answers[0]->is_correct());
    EXPECT_FALSE(user_answers[1]->is_correct());
    EXPECT_FALSE(user_answers[2]->is_correct());
    EXPECT_TRUE(user_answers[3]->is_correct());
}

TEST(question, answered_question)
{
    Question question1(3, "Question?");
    question1.add_answer("Odpowiedz A", true);
    question1.add_answer("Odpowiedz B", false);
    question1.add_answer("Odpowiedz C", false);
    question1.add_answer("Odpowiedz D", true);
    const std::vector<std::shared_ptr <Answer>> answers = question1.get_answers();
    std::vector<std::shared_ptr <Answer>> user_answers;
    user_answers.push_back(answers[0]);
    user_answers.push_back(answers[2]);
    Answered_question a_question1(question1, 8234, user_answers);
    EXPECT_EQ(a_question1.get_time(), 8234);
    EXPECT_EQ(a_question1.get_time(), 8234);
    EXPECT_EQ(a_question1.get_number_answers(), question1.get_number_answers());
    EXPECT_EQ(a_question1.get_number_user_answers(), 2);
}