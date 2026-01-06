//
// Created by Gutaon 04/01/2026.
//


#pragma once
#include <memory>
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"

inline std::shared_ptr<RepositoryFactory> getSharedRepositoryFactory() {
    static std::shared_ptr<RepositoryFactory> instance =
        std::make_shared<MemoryRepositoryFactory>();
    return instance;
}

