#include "user.hpp"

unsigned short User::user_counter{0};

void User::add_session(Session *session) {
    user_sessions.push_back(session);
    add_points(session->get_points_scored());
}

User::~User() {
    for (auto &session : user_sessions)
        delete session;
}