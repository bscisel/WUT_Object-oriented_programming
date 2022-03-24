#include "gtest/gtest.h"
#include "database.hpp"

TEST(database, create_database)
{
    Database database;
    database.open_file("../../database_files/test_data.json");
    database.read_data();
    EXPECT_EQ(database.get_file_name(), "../../database_files/test_data.json");
    EXPECT_EQ(database.get_categories_number(), 1);
    auto categories = database.get_categories();
    EXPECT_EQ(categories[0]->get_questions()[0]->get_text(), "Pytanie numer jeden?");
    const std::vector<Answer> answers = database.get_categories()[0]->get_questions()[0]->get_answers();
    EXPECT_EQ(answers.size(), 4);
    EXPECT_EQ(database.get_questions_number(), 2);
}

TEST(database, add_category)
{
    Database database;
    database.open_file("../../database_files/test_data.json");
    database.read_data();
    EXPECT_EQ(database.get_categories_number(), 1);
    Question* question1 = new Question(2, "Question?");
    question1->add_answer("Odpowiedz A", true);
    question1->add_answer("Odpowiedz B", false);
    question1->add_answer("Odpowiedz C", false);
    question1->add_answer("Odpowiedz D", true);
    database.add_category("Kategoria dwa", {question1});
    EXPECT_EQ(database.get_categories_number(), 2);
    EXPECT_EQ(database.get_questions_number(), 3);
}