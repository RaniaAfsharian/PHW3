#include <iostream>
#include <algorithm>
#include "Resource.h"

Resource::Resource(int _id, const std::string& _name) : id(_id), name(_name) {}

int Resource::getId() const {
    return id;
}

bool Resource::hasConflictWith(const TimeInterval& interval) const {
    for (const auto& existing : intervals) {
        if (existing.overlaps(interval))
            return true;
    }
    return false;
}

void Resource::addInterval(const TimeInterval& interval) {
    if (!hasConflictWith(interval)) {
        intervals.push_back(interval);
        std::sort(intervals.begin(), intervals.end());
    } else {
        std::cout << "Conflict detected! Interval not added.\n";
    }
}

bool Resource::hasConflict(const TimeInterval& interval) const {
    return hasConflictWith(interval);
}

void Resource::showSchedule() const {
    std::cout << "Resource ID: " << id << " Name: " << name << "\nSchedule:\n";
    for (const auto& interval : intervals) {
        interval.Show();
        std::cout << "\n";
    }
}