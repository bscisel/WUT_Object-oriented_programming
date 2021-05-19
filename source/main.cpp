#include "question.hpp"
#include "answer.hpp"
#include <iostream>
#include <string>
#include <type_traits>

template<typename Base, typename T>
inline bool instanceof(const T) {
   return std::is_base_of<Base, T>::value;
}

int main(){
    Correct_answer a("CORRECT");
    Wrong_answer b("WRONG");
    if(instanceof<Correct_answer>(b))
        std::cout << "TAK" << std::endl;
}
