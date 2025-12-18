#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>
#include "TimeInterval.h"

class Resource {
private:
    int id;
    std::string name;
    std::string type;               
    std::vector<TimeInterval> intervals;

    bool hasConflictWith(const TimeInterval& interval) const;

public:
    Resource(int _id, const std::string& _name, const std::string& _type);
    int getId() const; 

    void addInterval(const TimeInterval& interval);
    bool hasConflict(const TimeInterval& interval) const;
    void printSchedule() const;      
};

#endif