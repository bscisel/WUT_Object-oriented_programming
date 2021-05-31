#include "database.hpp"
#include "question.hpp"
#include <iostream>

int main()
{
    Database siemka("data.json");
    if (siemka.open_file())
        std::cout << "Otwarto plik!" << std::endl;

    if (siemka.read_data())
        std::cout << "Przeczytano dane!" << std::endl;

    Question question1(3, "Question?");
    question1.add_answer("Odpowiedz A", true);
    question1.add_answer("Odpowiedz B", false);
    question1.add_answer("Odpowiedz C", false);
    question1.add_answer("Odpowiedz D", true);

    siemka.add_category("Nowa kategoria", {&question1});
    if (siemka.save_to_file("new_data.json"))
        std::cout << "Zapisano plik!" << std::endl;

    /*
    std::vector<std::shared_ptr <Answer>> user_answers;
    user_answers.push_back(question1.get_answers()[0]);
    Answered_question a_question1( question1, 8234, user_answers);
    */
}
