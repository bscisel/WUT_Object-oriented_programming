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
}

TEST(session, new_session2)
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
    session.push_question(Answered_question(*questions[0], 10421, {questions[0]->get_answers()[1]}));
    session.push_question(Answered_question(*questions[1], 13308));

    EXPECT_EQ(session.get_answered_questions()[0].get_text(), "Pytanie jeden?");
    EXPECT_EQ(session.get_answered_questions()[0].get_answers()[1]->get_text(), "Odpowiedz 2");
}

TEST (session, count_points)
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
    session.push_question(Answered_question(*questions[0], 10421, {questions[0]->get_answers()[1]}));
    EXPECT_EQ(session.get_points_scored(), 0);
    session.push_question(Answered_question(*questions[1], 13308, {questions[1]->get_answers()[0]}));
    EXPECT_EQ(session.get_points_scored(), 2);
}
