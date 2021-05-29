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
    virtual ~Answer(){std::cout<<"answer\n";};
};

class Correct_answer : public Answer
{
public:
    Correct_answer(const std::string &text) : Answer(text) {}
    bool is_correct() const { return true; }
    ~Correct_answer(){std::cout<<"cor answer\n";};
};

class Wrong_answer : public Answer
{
public:
    Wrong_answer(const std::string &text) : Answer(text) {}
    bool is_correct() const { return false; }
    ~Wrong_answer(){std::cout<<"wr answer\n";};
};

#endif
