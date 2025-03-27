#pragma once

#include <thread>

struct TaskScheduler {
    int tasksExecuted = 0;

    template<typename Fn>
    void submit(Fn&& fn) {
        ++tasksExecuted;
        std::thread(std::forward<Fn>(fn)).detach();
    }
};
