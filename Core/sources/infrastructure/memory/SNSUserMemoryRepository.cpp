//
// SNSUserMemoryRepository.cpp
//
// Implements the in‑memory repository for SNSUser entities.  The
// repository simply stores shared pointers to SNSUser objects in a
// list.  It does not perform any validation or duplicate checking –
// those responsibilities are handled by the service layer.  Each
// retrieval method performs a linear search over the container to
// locate matching users.
//

#include "headers/infrastructure/memory/SNSUserMemoryRepository.h"

Result SNSUserMemoryRepository::save(std::shared_ptr<SNSUser> user) {
    // Persist the user by appending to the list.  Since the service
    // layer ensures no duplicates, we do not need to check here.
    this->container.push_back(user);
    return Result::OK(L"SNS user saved to memory");
}

std::list<std::shared_ptr<SNSUser>> SNSUserMemoryRepository::getAll() {
    // Return a copy of the list to prevent external modification of
    // internal state.
    std::list<std::shared_ptr<SNSUser>> copy;
    copy.insert(copy.end(), container.begin(), container.end());
    return copy;
}

std::optional<std::shared_ptr<SNSUser>> SNSUserMemoryRepository::getByPhoneNumber(const std::string &phone) {
    return findBy([&phone](const std::shared_ptr<SNSUser> &user) {
        return user->getPhoneNumber() == phone;
    });
}

std::optional<std::shared_ptr<SNSUser>> SNSUserMemoryRepository::getByEmail(const std::string &email) {
    return findBy([&email](const std::shared_ptr<SNSUser> &user) {
        return user->getEmail() == email;
    });
}

std::optional<std::shared_ptr<SNSUser>> SNSUserMemoryRepository::getByCitizenCardNumber(const std::string &cc) {
    return findBy([&cc](const std::shared_ptr<SNSUser> &user) {
        return user->getCitizenCardNumber() == cc;
    });
}

std::optional<std::shared_ptr<SNSUser>> SNSUserMemoryRepository::getBySNSUserNumber(const std::string &sns) {
    return findBy([&sns](const std::shared_ptr<SNSUser> &user) {
        return user->getSNSUserNumber() == sns;
    });
}