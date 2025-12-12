#include <iostream>
#include "ResourceManager.h"
#include "Resource.h"

int ResourceManager::totalResources = 0;

ResourceManager::ResourceManager() {}

void ResourceManager::addResource(const Resource& resource) {
    resources.push_back(resource);
    totalResources++;
}

Resource* ResourceManager::findResourceById(int id) {
    for (auto& res : resources) {
        if (res.getId() == id)  
            return &res;
    }
    return nullptr;
}

void ResourceManager::showAllSchedules() const {
    std::cout << "Total Resources: " << totalResources << "\n";
    for (const auto& resource : resources) {
        resource.showSchedule();
        std::cout << "----------------------\n";
    }
}

int ResourceManager::getTotalResources() {
    return totalResources;
}