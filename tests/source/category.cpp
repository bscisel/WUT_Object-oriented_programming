#include "gtest/gtest.h"
#include "category.hpp"

TEST(category, create_category)
{
    Category category1("Category 1");
    Category category2("Category 2");
    EXPECT_EQ(category1.get_id(), 1);
    EXPECT_EQ(category2.get_id(), 2);
    EXPECT_EQ(category1.get_name(), "Category 1");
    EXPECT_EQ(category2.get_name(), "Category 2");
    category2.set_name("Category 3");
    EXPECT_EQ(category2.get_name(), "Category 3");
    EXPECT_EQ(Category::get_categories_number(), 2);
    EXPECT_EQ(category1.get_questions_number(), 0);
    category1.add_question(new Question(3, "Jak masz na imie?"));
    category1.add_question(new Question(2, "Ile masz lat?"));
    EXPECT_EQ(category1.get_questions_number(), 2);
    EXPECT_EQ(category1.get_questions()[0]->get_text(), "Jak masz na imie?");
}