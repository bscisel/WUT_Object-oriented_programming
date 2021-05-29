#include "database.hpp"
#include "question.hpp"
#include <iostream>

int main()
{

    /*Database siemka("data.json");
    siemka.open_file();
    siemka.read_data();

    std::cout << siemka.data["categories"][0]["name"] << std::endl;
    */
    Question question1(3, "Question?");
    question1.add_answer("Odpowiedz A", true);
    question1.add_answer("Odpowiedz B", false);
    question1.add_answer("Odpowiedz C", false);
    question1.add_answer("Odpowiedz D", true);
    //const std::vector<std::shared_ptr <Answer>> answers = question1.get_answers();
    std::vector<std::shared_ptr <Answer>> user_answers;
    user_answers.push_back(question1.get_answers()[0]);
    //user_answers.push_back(question1.get_answers()[2]);
    Answered_question a_question1( question1, 8234, user_answers);
}
