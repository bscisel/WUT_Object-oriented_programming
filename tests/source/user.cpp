#include "gtest/gtest.h"
#include "user.hpp"
#include "question.hpp"
#include "session.hpp"

TEST(user, create_user)
{
    User user("Natalia");
    EXPECT_EQ(user.get_name(), "Natalia");
    EXPECT_EQ(user.get_user_id(), 1);
    EXPECT_EQ(user.get_points(), 0);
    User user2("Bartek");
    EXPECT_EQ(user2.get_user_id(), 2);
}

TEST(user, add_points)
{
    User user2("Bartek");
    EXPECT_EQ(user2.get_points(), 0);
    user2.add_points(2.5);
    EXPECT_EQ(user2.get_points(), 2.5);
}


TEST(user, add_session)
{
    User user("Natalia");
    EXPECT_EQ(user.get_points(), 0);
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
    Session *session = new Session();

    session->push_question(Answered_question(*questions[0], 10421, {Saved_answer(questions[0]->get_answers()[1], true)}));
    session->push_question(Answered_question(*questions[1], 13308, {Saved_answer(questions[1]->get_answers()[0], true)}));
    session->end_session();
    user.add_session(session);
    EXPECT_EQ(user.get_points(), 2);

    EXPECT_EQ(user.get_user_sessions().size(), 1);
    EXPECT_EQ(user.get_user_sessions()[0], session);
}
