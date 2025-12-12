#include <iostream>
#include "Time.h"

Time::Time(int h, int m) : hour(h), minute(m) {}

bool Time::operator<(const Time& other) const {
    if (hour < other.hour) return true;
    if (hour == other.hour && minute < other.minute) return true;
    return false;
}

bool Time::operator==(const Time& other) const {
    return (hour == other.hour && minute == other.minute);
}

int Time::operator-(const Time& other) const {
    int firstminutes = hour * 60 + minute;
    int secondminutes = other.hour * 60 + other.minute;
    return firstminutes - secondminutes;
}

void Time::Show() const {
    std::cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute;
}
