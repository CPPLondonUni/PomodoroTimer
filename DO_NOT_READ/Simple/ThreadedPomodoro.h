#ifndef POMODOROTHREADEDCOUNTDOWN_H
#define POMODOROTHREADEDCOUNTDOWN_H

#include "IPomodoro.h"
#include <atomic>
#include <thread>

//Wrapper version for simple implementation.
namespace CppLondonUni {
    class ThreadedPomodoro : public IThreadedCountdown {
    public:
        ~ThreadedPomodoro();

        std::string FormatCurrentTime() const override;

        void InvokeProcessLoop(uint32_t time, std::function<bool(uint32_t)>&& callback) override;
        void Interrupt() override;

    private:
        std::unique_ptr<ISimpleCountdown> impl;
        std::thread runner;
    };
}

#endif // POMODOROTHREADEDCOUNTDOWN_H
