#include <iostream>
#include <stdexcept> 
#include "TimeInterval.h"

TimeInterval::TimeInterval(const Time& s, const Time& e) : start(s), end(e) {}


bool TimeInterval::overlaps(const TimeInterval& other) const {
    return (start < other.end) && (other.start < end);
}
int TimeInterval::duration() const {
    return end - start;
}

TimeInterval TimeInterval::merge(const TimeInterval& other) const {
    Time newStart = (start < other.start) ? start : other.start;
    Time newEnd = (end < other.end) ? other.end : end;
    return TimeInterval(newStart, newEnd);
}

bool TimeInterval::operator<(const TimeInterval& other) const {
    return start < other.start;
}

bool TimeInterval::operator==(const TimeInterval& other) const {
    return (start == other.start) && (end == other.end);
}

TimeInterval TimeInterval::operator+(const TimeInterval& other) const {
    if (overlaps(other) || end == other.start || other.end == start) {
        return merge(other);
    }
    
    throw std::runtime_error("Intervals cannot be merged: they are neither overlapping nor adjacent.");
}

void TimeInterval::Show() const {
    start.Show();
    std::cout << " - ";
    end.Show();
}