#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>
#include "TimeInterval.h"

class Resource {
private:
    int id;
    std::string name;
    std::vector<TimeInterval> intervals;

    bool hasConflictWith(const TimeInterval& interval) const;

public:
    Resource(int _id, const std::string& _name);
    int getId() const; 

    void addInterval(const TimeInterval& interval);
    bool hasConflict(const TimeInterval& interval) const;
    void showSchedule() const;
};

#endif