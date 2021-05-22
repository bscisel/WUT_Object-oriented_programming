#include "gtest/gtest.h"
#include "session.hpp"
#include <thread>
#include <chrono>

TEST(session, new_session){
    Session session;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    session.end_session();
    EXPECT_GE(session.get_session_time(), 200);
}