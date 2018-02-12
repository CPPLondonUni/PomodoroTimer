#ifndef IPOMODORO_H
#define IPOMODORO_H

#include <cstdint>
#include <functional>
#include <string>

namespace CppLondonUni {
    
    // This is an interface for a generic class that formats the time
    // into a string. It is expected to add leading zeroes to the seconds.
    // So, for example, FormatTime(1, 4) should return "1:04"
    class ITimeFormatter {
    public:
        virtual std::string FormatTime(uint32_t mins, uint32_t secs) const = 0;
        virtual ~ITimeFormatter() = default;
    };

    // This is the interface for a simple countdown implementation.
    // It does not need to take care of any multithreading.
    class ISimpleCountdown {
    public:
        // This constructor is provided in the base for your convenience.
        // Your implementation should expose it via a "using" statement
        // or otherwise be wrapped as appropriate by your implementation.
        ISimpleCountdown(const uint32_t startTime) : startTime{startTime} {}
        
        // IsComplete should return true when we are finished counting down
        // otherwise, it should return false.
        virtual bool IsComplete() const = 0;
        
        // CurrentCount should return the number of seconds remaining.
        virtual uint32_t CurrentCount() const = 0;
        
        // Decrement should decrement the seconds remaining by 1.
        virtual void Decrement() = 0;
        
        // If Cancel is called, all subsequent calls to IsComplete should
        // return true.
        virtual void Cancel() = 0;
        
        // FormatCurrentTime should return a string of the current time remaining
        // in the same format as what FormatTime() returns.
        virtual std::string FormatCurrentTime() const = 0;

        virtual ~ISimpleCountdown() = default;

    protected:
        const uint32_t startTime;
    };

    // IThreadedCountdown is the interface for a class which will run the
    // countdown mechanism itself in a separate thread.
    class IThreadedCountdown {
    public:
        // InvokeProcessLoop should start the process of counting down.
        // If we are already counting down, it should cause us to start over
        // with the new time.
        // "time" is the total number of seconds to countdown for.
        // "callback" is a function that should be called every tick
        //            with the number of seconds remaining as its parameter.
        //            if it returns true, you should behave as if Interrupt()
        //            was called.
        virtual void InvokeProcessLoop(uint32_t time, std::function<bool(uint32_t)>&& callback) = 0;
        
        // Interrupt() should result in InvokeProcessLoop returning ASAP
        virtual void Interrupt() = 0;
        
        // Same requirements as FormatCurrentTime() in the ISimpleCountdown
        virtual std::string FormatCurrentTime() const = 0;

        virtual ~IThreadedCountdown() = default;
    };
}

#endif // IPOMODORO_H
