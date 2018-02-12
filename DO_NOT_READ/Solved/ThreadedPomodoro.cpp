#include "ThreadedPomodoro.h"
#include "pomodorotimeformatter.h"

#include <chrono>

using namespace std::chrono;
using namespace std::chrono_literals;
using namespace CppLondonUni;

high_resolution_clock clk;
PomodoroTimeFormatter timeFormatter;

ThreadedPomodoro::~ThreadedPomodoro() {
    isDone = true;
    if (runner.joinable())
        runner.join();
}

std::string ThreadedPomodoro::FormatCurrentTime() const {
    auto cur = time.load();
    auto mins = cur / 60;
    auto secs = cur % 60;
    return timeFormatter.FormatTime(mins, secs);
}

void ThreadedPomodoro::InvokeProcessLoop(uint32_t start, std::function<bool(uint32_t)>&& callback) {
    time = start;
    if (runner.joinable()) {
        isDone = true;
        runner.join();
    }
    isDone = false;
    runner = std::thread{[&, callback = std::move(callback)] () mutable {
        do {
            auto start = clk.now();
            isDone = callback(time);
            auto end = 1s - (clk.now() - start);
            std::this_thread::sleep_for(end);
        } while(!isDone && time--);
        isDone = true;
    }};
}

void ThreadedPomodoro::Interrupt() {
    isDone = true;
}
