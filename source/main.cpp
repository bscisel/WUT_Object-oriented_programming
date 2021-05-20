#include "question.hpp"
#include "answer.hpp"
#include <iostream>
#include <string>
#include <type_traits>


int main(){
    Question question1(1, 3, "Question?");
    question1.add_answer("Odpowiedz A", true);
    question1.add_answer("Odpowiedz B", false);
    question1.add_answer("Odpowiedz C", false);
    question1.add_answer("Odpowiedz D", true);
    const std::vector<Answer *> user_answers = question1.get_answers();
    std::cout << static_cast<int>(user_answers[0]->is_correct()) << std::endl;
}
