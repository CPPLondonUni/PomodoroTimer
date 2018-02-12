#ifndef POMODOROTIMEFORMATTER_H
#define POMODOROTIMEFORMATTER_H

#include "IPomodoro.h"

namespace CppLondonUni {
    class PomodoroTimeFormatter : public ITimeFormatter {
    public:
        std::string FormatTime(uint32_t mins, uint32_t secs) const override;
    };
}

#endif // POMODOROTIMEFORMATTER_H
