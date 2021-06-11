#ifndef ANSWER_HPP
#define ANSWER_HPP

#include <string>

class Answer
{
protected:
    std::string text;
    bool correct;

public:
    Answer(const std::string &text, bool is_correct) : text(text), correct(is_correct) {}
    const std::string &get_text() const { return text; };
    bool is_correct() const { return correct; };
};

class Saved_answer : public Answer
{
public:
    Saved_answer(const Answer &answer) : Answer(answer) {}
};

#endif
