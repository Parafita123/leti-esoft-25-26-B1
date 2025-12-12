

#ifndef LETI_ESOFT_25_26_B1_MEMORYREPOSITORYFACTORY_H
#define LETI_ESOFT_25_26_B1_MEMORYREPOSITORYFACTORY_H

#include <memory>
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/domain/repositories/SNSUserRepository.h"

class MemoryRepositoryFactory : public RepositoryFactory {
private:
    // A single instance of the SNS user repository stored as a member
    // so that repeated calls return the same object.  This mirrors the
    // behaviour seen in DemoTasks where repositories are reused.
    std::shared_ptr<SNSUserRepository> snsRepo;

public:
    MemoryRepositoryFactory();
    virtual std::shared_ptr<SNSUserRepository> getSNSUserRepository() override;
};

#endif // LETI_ESOFT_25_26_B1_MEMORYREPOSITORYFACTORY_H