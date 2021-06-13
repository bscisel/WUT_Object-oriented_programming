#include "gtest/gtest.h"
#include "question.hpp"
#include "answer.hpp"
#include <memory>

TEST(question, create_question)
{
    Question question1(3, "Question?");
    EXPECT_EQ(question1.get_points(), 3);
    EXPECT_EQ(question1.get_text(), "Question?");
    EXPECT_EQ(question1.get_all_answers_number(), 0);
    EXPECT_EQ(question1.get_correct_answers_number(), 0);
}


TEST(question, create_question_nondefault)
{
    Question question1(3, "Question?");
    EXPECT_EQ(question1.get_points(), 3);
    EXPECT_EQ(question1.get_text(), "Question?");
    EXPECT_EQ(question1.get_all_answers_number(), 0);
    EXPECT_EQ(question1.get_correct_answers_number(), 0);
}

TEST(question, question_add_answer)
{
    Question question1(3, "Question?");
    EXPECT_EQ(question1.get_correct_answers_number(), 0);

    EXPECT_EQ(question1.get_points(), 3);
    EXPECT_EQ(question1.get_text(), "Question?");
    EXPECT_EQ(question1.get_all_answers_number(), 0);
    question1.add_answer("Odpowiedz A", true);
    question1.add_answer("Odpowiedz B", false);
    question1.add_answer("Odpowiedz C", false);
    question1.add_answer("Odpowiedz D", true);
    EXPECT_EQ(question1.get_all_answers_number(), 4);
    const std::vector<Answer> &user_answers = question1.get_answers();
    EXPECT_TRUE(user_answers[0].is_correct());
    EXPECT_FALSE(user_answers[1].is_correct());
    EXPECT_FALSE(user_answers[2].is_correct());
    EXPECT_TRUE(user_answers[3].is_correct());
    EXPECT_EQ(question1.get_correct_answers_number(), 2);

}

TEST(question, answered_question)
{
    Question question1(2, "Question?");
    question1.add_answer("Odpowiedz A", true);
    question1.add_answer("Odpowiedz B", false);
    question1.add_answer("Odpowiedz C", false);
    question1.add_answer("Odpowiedz D", true);
    EXPECT_EQ(question1.get_correct_answers_number(), 2);
    const std::vector<Answer> &answers = question1.get_answers();
    std::vector<Saved_answer> user_answers;
    user_answers.push_back(Saved_answer(answers[0], true));
    user_answers.push_back(Saved_answer(answers[3], true));
    Answered_question a_question1(question1, 8234, user_answers);
    EXPECT_EQ(a_question1.get_time(), 8234);
    EXPECT_EQ(a_question1.get_all_answers_number(), question1.get_all_answers_number());
    EXPECT_EQ(a_question1.get_user_answers_number(), 2);
    EXPECT_EQ(a_question1.get_correct_answers_number(), 2);
    a_question1.count_points();
    EXPECT_EQ(a_question1.get_points_scored(), 2);

}