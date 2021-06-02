#ifndef ANSWER_HPP
#define ANSWER_HPP

#include <string>
#include <iostream>

class Answer
{
protected:
    std::string text;

public:
    Answer(const std::string &text) : text(text) {}
    std::string get_text() const { return text; };
    virtual bool is_correct() const = 0;
};

class Correct_answer : public Answer
{
public:
    Correct_answer(const std::string &text) : Answer(text) {}
    bool is_correct() const { return true; }
};

class Wrong_answer : public Answer
{
public:
    Wrong_answer(const std::string &text) : Answer(text) {}
    bool is_correct() const { return false; }
};

#endif
