

#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include "headers/infrastructure/memory/SNSUserMemoryRepository.h"

MemoryRepositoryFactory::MemoryRepositoryFactory() {
    // repositories will be lazily created in getters
}

std::shared_ptr<SNSUserRepository> MemoryRepositoryFactory::getSNSUserRepository() {
    if (!this->snsRepo) {
        this->snsRepo = std::make_shared<SNSUserMemoryRepository>();
    }
    return this->snsRepo;
}