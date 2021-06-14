#include "gtest/gtest.h"
#include "session.hpp"
#include "category.hpp"
#include <thread>
#include <chrono>

TEST(session, new_session)
{
    Session session;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    session.end_session();
    EXPECT_GE(session.get_session_time(), 200);
    EXPECT_LE(session.get_session_time(), 300);

    EXPECT_EQ(session.get_points_scored(), 0);
}

TEST(session, push_questions)
{
    Category category("Kategoria jeden");
    Question *question = new Question(3, "Pytanie jeden?");
    question->add_answer("Odpowiedz 1", true);
    question->add_answer("Odpowiedz 2", false);
    category.add_question(question);
    question = new Question(2, "Pytanie dwa?");
    question->add_answer("Odpowiedz 1 w drugim", true);
    question->add_answer("Odpowiedz 2 w drugim", false);
    category.add_question(question);

    std::vector<Question *> questions = category.get_questions();
    Session session;
    session.push_question(Answered_question(*questions[0], {Saved_answer(questions[0]->get_answers()[1], true)}));
    session.push_question(Answered_question(*questions[1]));

    EXPECT_EQ(session.get_answered_questions()[0].get_text(), "Pytanie jeden?");
    EXPECT_EQ(session.get_answered_questions()[0].get_answers()[1].get_text(), "Odpowiedz 2");
}

TEST(session, count_points)
{
    Category category("Kategoria jeden");
    Question *question = new Question(3, "Pytanie jeden?");
    question->add_answer("Odpowiedz 1", true);
    question->add_answer("Odpowiedz 2", false);
    category.add_question(question);
    question = new Question(2, "Pytanie dwa?");
    question->add_answer("Odpowiedz 1 w drugim", true);
    question->add_answer("Odpowiedz 2 w drugim", false);
    category.add_question(question);

    std::vector<Question *> questions = category.get_questions();
    Session session;
    EXPECT_EQ(session.get_points_scored(), 0);
    EXPECT_EQ(session.get_current_question_index(), 0);
    session.push_question(Answered_question(*questions[0], {Saved_answer(questions[0]->get_answers()[1], true)}));
    EXPECT_EQ(session.get_points_scored(), 0);
    EXPECT_EQ(session.get_current_question_index(), 1);
    session.push_question(Answered_question(*questions[1], {Saved_answer(questions[1]->get_answers()[0], true)}));
    EXPECT_EQ(session.get_points_scored(), 2);
    EXPECT_EQ(session.get_current_question_index(), 2);
}

TEST(session, read_session)
{
    Category category("Kategoria jeden");
    Question *question = new Question(3, "Pytanie jeden?");
    question->add_answer("Odpowiedz 1", true);
    question->add_answer("Odpowiedz 2", false);
    category.add_question(question);
    question = new Question(2, "Pytanie dwa?");
    question->add_answer("Odpowiedz 1 w drugim", true);
    question->add_answer("Odpowiedz 2 w drugim", false);
    category.add_question(question);

    std::vector<Question *> questions = category.get_questions();
    std::vector<Answered_question> answered_questions;
    answered_questions.push_back(Answered_question(*questions[0], {Saved_answer(questions[0]->get_answers()[1], true)}));
    answered_questions.push_back(Answered_question(*questions[1], {Saved_answer(questions[1]->get_answers()[0], true)}));

    std::vector<std::string> cat_names = {category.get_name()};
    Session session(uint64_t(1623580199), uint64_t(250), 2, 5, answered_questions, cat_names);

    EXPECT_EQ(session.get_selected_categories_names()[0], category.get_name());
}

TEST(session, select_questions)
{
    auto category = std::make_shared<Category>("Kategoria jeden");
    Question *question = new Question(3, "Pytanie jeden?");
    question->add_answer("Odpowiedz 1", true);
    question->add_answer("Odpowiedz 2", false);
    category->add_question(question);
    std::vector<std::shared_ptr<Category>> selected_categories;
    selected_categories.push_back(category);
    Session session;
    session.draw_questions(selected_categories, 1);
    EXPECT_EQ(session.get_points_to_score(), 3);
    EXPECT_EQ(session.get_current_question_index(), 0);
    EXPECT_EQ(session.get_current_question_text(), "Pytanie jeden?");
    EXPECT_EQ(session.get_current_question_answers_text()[0], "Odpowiedz 1");
    EXPECT_TRUE(session.next_question_exist());
    session.push_question(Answered_question(*question, {Saved_answer(question->get_answers()[1], true)}));
    EXPECT_FALSE(session.next_question_exist());
    session.end_session();
}