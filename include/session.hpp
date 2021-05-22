#ifndef SESSION_HPP
#define SESSION_HPP

#include <chrono>

class Session
{
private:
    uint64_t start_time;
    uint64_t session_time;
public:
    Session();
    void end_session();
    uint64_t get_session_time() { return session_time; }
};

#endif
