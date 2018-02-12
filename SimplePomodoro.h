#pragma once

#include "IPomodoro.h"

#include <sstream>
#include <iomanip>

namespace CppLondonUni {
    class SimplePomodoro : public ISimpleCountdown {
    public:
        SimplePomodoro(uint32_t start) : ISimpleCountdown{start}, currentTime{start} {}
        
        bool IsComplete() const override {
            return currentTime == 0;
        }
        
        uint32_t CurrentCount() const override {
            return currentTime;
        }
        
        void Decrement() override {
            --currentTime;
        }
        
        void Cancel() override {
            currentTime = 0;
        }
        
        std::string FormatCurrentTime() const override {
            auto mins = currentTime / 60;
            auto secs = currentTime % 60;
            std::stringstream secsStr;
            secsStr << mins << ':';
            secsStr << std::setw(2) << std::setfill('0') << secs;
            return secsStr.str();
        }
        
    private:        
        uint32_t currentTime;
    };
}
