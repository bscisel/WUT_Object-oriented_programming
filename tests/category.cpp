#include "gtest/gtest.h"
#include "category.hpp"

TEST(category, create_category)
{
    Category category1("Category 1");
    Category category2("Category 2");
    EXPECT_EQ(category1.get_id(), 1);
    EXPECT_EQ(category2.get_id(), 2);
    EXPECT_EQ(Category::get_number_categories(), 2);
    EXPECT_EQ(category1.get_number_questions(), 0);
    category1.add_question(new Question(3, "Jak masz na imie?"));
    category1.add_question(new Question(2, "Ile masz lat?"));
    EXPECT_EQ(category1.get_number_questions(), 2);
}