#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <string>
#include "Resource.h"

class ResourceManager {
private:
    std::vector<Resource> resources;
    static int totalResources; 

public:
    ResourceManager();

    void addResource(const Resource& resource);
    Resource* findResourceById(int id);
    void showAllSchedules() const;

    static int getTotalResources();
};

#endif
