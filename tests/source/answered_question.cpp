#include "gtest/gtest.h"
#include "question.hpp"
#include "answered_question.hpp"
#include "answer.hpp"
#include "saved_answer.hpp"

TEST(answered_question, answered_question)
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
    Answered_question a_question1(question1, user_answers);
    EXPECT_EQ(a_question1.get_all_answers_number(), question1.get_all_answers_number());
    EXPECT_EQ(a_question1.get_correct_answers_number(), 2);
    a_question1.count_points();
    EXPECT_EQ(a_question1.get_points_scored(), 2);
}
