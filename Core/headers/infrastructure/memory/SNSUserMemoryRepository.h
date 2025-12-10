//
// SNSUserMemoryRepository.h
//
// Provides an in‑memory repository for SNSUser entities.  The
// repository uses a standard list to store shared pointers to users.
// It implements the SNSUserRepository interface, allowing the service
// layer to persist and query users without knowing the underlying
// storage mechanism【687714786585861†L360-L545】.
//

#ifndef LETI_ESOFT_25_26_B1_SNSUSERMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_SNSUSERMEMORYREPOSITORY_H

#include <list>
#include <memory>
#include <optional>
#include <string>
#include "headers/domain/repositories/SNSUserRepository.h"

class SNSUserMemoryRepository : public SNSUserRepository {
private:
    std::list<std::shared_ptr<SNSUser>> container;

    /**
     * Helper method to find a user by a predicate.  It iterates over
     * the container and returns the first user that satisfies the
     * predicate.
     */
    template<typename Func>
    std::optional<std::shared_ptr<SNSUser>> findBy(Func predicate) {
        for (auto &user : container) {
            if (predicate(user)) {
                return std::make_optional(user);
            }
        }
        return std::nullopt;
    }

public:
    SNSUserMemoryRepository() = default;

    virtual Result save(std::shared_ptr<SNSUser> user) override;

    virtual std::list<std::shared_ptr<SNSUser>> getAll() override;

    virtual std::optional<std::shared_ptr<SNSUser>> getByPhoneNumber(const std::string &phone) override;

    virtual std::optional<std::shared_ptr<SNSUser>> getByEmail(const std::string &email) override;

    virtual std::optional<std::shared_ptr<SNSUser>> getByCitizenCardNumber(const std::string &cc) override;

    virtual std::optional<std::shared_ptr<SNSUser>> getBySNSUserNumber(const std::string &sns) override;
};

#endif // LETI_ESOFT_25_26_B1_SNSUSERMEMORYREPOSITORY_H