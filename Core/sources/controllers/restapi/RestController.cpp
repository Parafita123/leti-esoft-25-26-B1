//
// Created by Filipe on 28/12/2025.
//
#include "headers/controllers/restapi/RestController.h"

RestController::RestController(const std::wstring& bearerToken) : token(bearerToken) {
    validateBearerToken(bearerToken);
}

void RestController::validateBearerToken(const std::wstring& token) {
    if (token.empty()) throw std::invalid_argument("Missing Authorization header");
}
