#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include "nlohmann/json.hpp"
#include "question.hpp"
#include <string>
#include <vector>

/**
 * @brief class Category is described by name and unique id number.
 * Contains vector of questions.
 */
class Category
{
private:
    static unsigned category_counter; /**< Counter of categories in the game -> used to assign unique id's to new categories */
    unsigned category_id; /**< Unique category identification number */
    std::string name; /**< category's name */
    std::vector<Question *> questions; /**> container with pointers to questions */

public:
    /**
     * @brief Construct a new Category object
     * Assigns unique id number. Category counter increased.
     * @param name
     * @param questions
     */
    Category(const std::string &name, std::vector<Question *> questions = {})
        : name(name),
          questions(questions)
    {
        category_id = ++category_counter;
    }
    /**
     * @brief Destroy the Category object
     * Destroys questions to which pointers are stored in the container.
     */
    ~Category();
    /**
     * @brief Get the name of the category
     * @return const std::string&
     */
    const std::string &get_name() const { return name; }
    /**
     * @brief Set the name of the category
     * @param new_name
     */
    void set_name(const std::string &new_name) { name = new_name; }
    /**
     * @brief Get the category's id
     * @return unsigned short
     */
    unsigned short get_id() const { return category_id; }
    /**
     * @brief Get the containers with pointers to questions in the category
     * @return const std::vector<Question *>&
     */
    const std::vector<Question *> &get_questions() const { return questions; }
    /**
     * @brief Add pointer to a question to the category's container
     * @param question
     */
    void add_question(Question *question) { questions.push_back(question); }
    /**
     * @brief Get the number of questions in the category
     * @return int
     */
    int get_questions_number() const { return questions.size(); }
    /**
     * @brief Get the number of categories
     * @return unsigned
     */
    static unsigned get_categories_number() { return category_counter; }
};

#endif
