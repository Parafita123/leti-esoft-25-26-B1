

#ifndef LETI_ESOFT_25_26_B1_SNSUSERREPOSITORY_H
#define LETI_ESOFT_25_26_B1_SNSUSERREPOSITORY_H

#include <memory>
#include <list>
#include <optional>
#include "headers/domain/model/SNSUser.h"
#include "headers/domain/shared/Result.h"

/**
 * Repository interface for persisting SNSUser entities.  It exposes
 * CRUD‑like operations that allow the service layer to save objects and
 * query them by their identifying attributes.  Concrete implementations
 * can store data in memory, files or databases without affecting
 * higher layers of the application.
 */
class SNSUserRepository {
public:
    virtual ~SNSUserRepository() = default;

    /**
     * Saves the given SNS user into the repository.  Implementations should
     * assume that the user has already passed validation at the service
     * layer and simply persist it.  They should return a Result
     * indicating success or failure.
     */
    virtual Result save(std::shared_ptr<SNSUser> user) = 0;

    /**
     * Returns all SNS users stored in the repository.  Useful for
     * queries and for checking duplicate data.
     */
    virtual std::list<std::shared_ptr<SNSUser>> getAll() = 0;

    /**
     * Looks up a user by their phone number.  If a match is found, the
     * method returns an optional containing the user; otherwise it
     * returns an empty optional.
     */
    virtual std::optional<std::shared_ptr<SNSUser>> getByPhoneNumber(const std::string &phone) = 0;

    /**
     * Looks up a user by their e‑mail address.
     */
    virtual std::optional<std::shared_ptr<SNSUser>> getByEmail(const std::string &email) = 0;

    /**
     * Looks up a user by their citizen card number.
     */
    virtual std::optional<std::shared_ptr<SNSUser>> getByCitizenCardNumber(const std::string &cc) = 0;

    /**
     * Looks up a user by their SNS user number.
     */
    virtual std::optional<std::shared_ptr<SNSUser>> getBySNSUserNumber(const std::string &sns) = 0;
};

#endif // LETI_ESOFT_25_26_B1_SNSUSERREPOSITORY_H