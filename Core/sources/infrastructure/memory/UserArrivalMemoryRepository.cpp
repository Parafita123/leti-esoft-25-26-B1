#include "headers/infrastructure/memory/UserArrivalMemoryRepository.h"
#include <ctime>

std::string UserArrivalMemoryRepository::toDayString(std::chrono::system_clock::time_point tp) {
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);

    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &tt);
#else
    localtime_r(&tt, &tm);
#endif

    char buf[11]; // YYYY-MM-DD + '\0'
    std::snprintf(buf, sizeof(buf), "%04d-%02d-%02d",
                  tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    return std::string(buf);
}

Result UserArrivalMemoryRepository::save(std::shared_ptr<UserArrival> obj) {
    if (!obj) return Result::NOK(L"UserArrival is null.");
    data.push_back(std::move(obj));
    return Result::OK(L"User arrival saved.");
}

bool UserArrivalMemoryRepository::exists(const std::string& snsUserNumber,
                                         int facilityID,
                                         const std::string& day) {
    for (const auto& a : data) {
        if (!a) continue;
        if (!a->getUser() || !a->getFacility()) continue;

        const std::string storedDay = toDayString(a->getArrivalTime());

        if (a->getUser()->getSNSUserNumber() == snsUserNumber &&
            a->getFacility()->getFacilityID() == facilityID &&
            storedDay == day) {
            return true;
        }
    }
    return false;
}
