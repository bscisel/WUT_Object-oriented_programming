#include "session.hpp"
#include <chrono>

uint64_t time()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

Session::Session()
{
    start_time = time();
}

void Session::end_session()
{
    session_time = time() - start_time;
}