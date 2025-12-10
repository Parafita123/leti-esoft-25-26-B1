//
// RepositoryFactory.h
//
// Declares an abstract factory for obtaining repository instances.  The
// factory allows the application to switch between different
// persistence mechanisms (e.g. memory, file, database) at runtime by
// instantiating a different concrete factory.  Each concrete factory
// returns concrete repository implementations appropriate for the chosen
// storage mode【687714786585861†L360-L545】.
//

#ifndef LETI_ESOFT_25_26_B1_REPOSITORYFACTORY_H
#define LETI_ESOFT_25_26_B1_REPOSITORYFACTORY_H

#include <memory>
#include "SNSUserRepository.h"

class RepositoryFactory {
public:
    virtual ~RepositoryFactory() = default;

    /**
     * Returns a repository capable of persisting SNSUser objects.  The
     * returned pointer is shared to allow multiple services to reuse the
     * same repository instance.  Concrete factories decide which
     * implementation (e.g. in memory or database) is returned.
     */
    virtual std::shared_ptr<SNSUserRepository> getSNSUserRepository() = 0;
};

#endif // LETI_ESOFT_25_26_B1_REPOSITORYFACTORY_H