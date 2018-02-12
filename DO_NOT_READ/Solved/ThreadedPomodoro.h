#ifndef POMODOROTHREADEDCOUNTDOWN_H
#define POMODOROTHREADEDCOUNTDOWN_H

#include "IPomodoro.h"
#include <atomic>
#include <thread>

namespace CppLondonUni {
    class ThreadedPomodoro : public IThreadedCountdown {
    public:
        ~ThreadedPomodoro();

        std::string FormatCurrentTime() const override;

        void InvokeProcessLoop(uint32_t time, std::function<bool(uint32_t)>&& callback) override;
        void Interrupt() override;

    private:
        std::thread runner;
        std::atomic_bool isDone;
        std::atomic_uint_fast32_t time;
    };
}

#endif // POMODOROTHREADEDCOUNTDOWN_H
