#include "pomodorotimeformatter.h"

#include <iomanip>
#include <sstream>

using namespace CppLondonUni;

std::string PomodoroTimeFormatter::FormatTime(uint32_t mins, uint32_t secs) const {
    std::stringstream secsStr;
    secsStr << mins << ':';
    secsStr << std::setw(2) << std::setfill('0') << secs;
    return secsStr.str();
}
