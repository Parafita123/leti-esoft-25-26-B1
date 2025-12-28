//
// Created by Filipe on 28/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_RESTCONTROLLER_H
#define LETI_ESOFT_25_26_B1_RESTCONTROLLER_H

#pragma once
#include <string>
#include <stdexcept>

class RestController {
protected:
    std::wstring token;

    static void validateBearerToken(const std::wstring& token);
public:
    explicit RestController(const std::wstring& bearerToken);
    virtual ~RestController() = default;
};

#endif //LETI_ESOFT_25_26_B1_RESTCONTROLLER_H
