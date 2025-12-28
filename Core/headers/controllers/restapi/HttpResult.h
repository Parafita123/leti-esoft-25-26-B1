//
// Created by Filipe on 28/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_HTTPRESULT_H
#define LETI_ESOFT_25_26_B1_HTTPRESULT_H

#pragma once
#include <string>
#include "thirdparty/SimpleJson.hpp"
#include "headers/controllers/restapi/HttpStatus.h"

class HttpResult {
private:
    int httpStatus;
    json::JSON result;

public:
    HttpResult();
    explicit HttpResult(int httpStatus);
    HttpResult(int httpStatus, const std::string &msg);
    HttpResult(int httpStatus, const std::wstring &msg);

    int getHttpStatus() const;
    json::JSON getResult() const;

    void setHttpStatus(int status);

    void setJsonResult(const json::JSON &obj);
    void setMessage(const std::string &msg);
    void setMessage(const std::wstring &msg);
};

#endif //LETI_ESOFT_25_26_B1_HTTPRESULT_H
