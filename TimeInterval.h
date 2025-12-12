#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H

#include "Time.h"

class TimeInterval {
private:
    Time start;
    Time end;

public:
    TimeInterval(const Time& s, const Time& e);

    bool overlaps(const TimeInterval& other) const;
    int duration() const;
    TimeInterval merge(const TimeInterval& other) const;

    bool operator<(const TimeInterval& other) const;
    bool operator==(const TimeInterval& other) const;
    TimeInterval operator+(const TimeInterval& other) const;

    void Show() const;
};

#endif
