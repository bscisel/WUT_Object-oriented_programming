#ifndef USER_HPP
#define USER_HPP

#include "session.hpp"
#include <string>
#include <vector>

/**
 * @brief Class User describesc the player's profile,
 * stores his previous games and the total amount of points scored.
 */
class User
{
private:
    static unsigned short user_counter; /**< Users counter -> used to assign unique id to new players starting from 1 */
    unsigned short user_id; /**< Unique user identification number */
    std::string name; /**< User's name */
    float points; /**< Total points scored */
    std::vector<Session *> user_sessions; /**< Stored user's sessions */

public:
    /**
     * @brief Construct a new User object
     * When saved data uploaded from file, previous sessions and points scored are loaded.
     * Empty or zero otherwise.
     * User id assigned according to current number of users in the game.
     * @param name
     * @param points
     * @param user_sessions
     */
    User(std::string name, float points = {0.f}, std::vector<Session *> user_sessions = {})
        : name(name), points(points), user_sessions(user_sessions)
    {
        user_id = ++user_counter;
    };
    /**
     * @brief Destroy the User object
     * Deletes stored sessions.
     */
    ~User();
    /**
     * @brief Add the result of a current session to total urser's points
     * @param session_result
     */
    void add_points(float session_result) { points += session_result; }
    /**
     * @brief Get the user's id
     * @return unsigned
     */
    unsigned get_user_id() const { return user_id; }
    /**
     * @brief Get the user's name
     * @return const std::string&
     */
    const std::string &get_name() const { return name; }
    /**
     * @brief Get the total points scored
     * @return float
     */
    float get_points() const { return points; }
    /**
     * @brief Add a session to store it in user's sessions
     * Calls add_points() function.
     * @param session
     */
    void add_session(Session * session);
    /**
     * @brief Get all user's sessions
     * @return const std::vector<Session *>&
     */
    const std::vector<Session *> &get_user_sessions() const { return user_sessions; }
};

#endif