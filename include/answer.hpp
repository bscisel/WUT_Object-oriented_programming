#ifndef ANSWER_HPP
#define ANSWER_HPP

#include <string>

class Answer
{
protected:
    std::string text;

public:
    Answer(const std::string &text) : text(text){};
    std::string get_text() const { return text; };
};

class Correct_answer : public Answer
{
public:
    Correct_answer(const std::string &text) : Answer(text){};
};

class Wrong_answer : public Answer
{
public:
    Wrong_answer(const std::string &text) : Answer(text){};
};

#endif
