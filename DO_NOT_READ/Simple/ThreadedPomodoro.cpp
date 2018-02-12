#include "ThreadedPomodoro.h"
#include "SimplePomodoro.h"

#include <chrono>

using namespace std::chrono;
using namespace std::chrono_literals;
using namespace CppLondonUni;

high_resolution_clock clk;

ThreadedPomodoro::~ThreadedPomodoro() {
    if (runner.joinable())
        runner.join();
}

std::string ThreadedPomodoro::FormatCurrentTime() const {
    return impl->FormatCurrentTime();
}

void ThreadedPomodoro::InvokeProcessLoop(uint32_t start, std::function<bool(uint32_t)>&& callback) {
    if (runner.joinable()) {
        impl->Cancel();
        runner.join();
    }
    impl = std::make_unique<SimplePomodoro>(start);
    runner = std::thread{[&, callback = std::move(callback)] () mutable {
        do {
            auto start = clk.now();
            if (callback(impl->CurrentCount()))
                impl->Cancel();
            auto end = 1s - (clk.now() - start);
            std::this_thread::sleep_for(end);
            impl->Decrement();
        } while(!impl->IsComplete());
        callback(0);
    }};
}

void ThreadedPomodoro::Interrupt() {
    impl->Cancel();
}
