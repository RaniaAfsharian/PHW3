#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Resource.h"

Resource::Resource(int _id, const std::string& _name, const std::string& _type)
    : id(_id), name(_name), type(_type) {}

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
        throw std::runtime_error("Conflict detected! Interval not added.");
    }
}

bool Resource::hasConflict(const TimeInterval& interval) const {
    return hasConflictWith(interval);
}

void Resource::printSchedule() const {
    std::cout << "Resource ID: " << id 
              << " Name: " << name 
              << " Type: " << type << "\nSchedule:\n";
    for (const auto& interval : intervals) {
        interval.Show();
        std::cout << "\n";
    }
}