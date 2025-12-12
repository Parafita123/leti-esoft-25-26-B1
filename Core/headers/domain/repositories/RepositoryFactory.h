

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