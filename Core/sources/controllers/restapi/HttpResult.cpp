//
// Created by Filipe on 28/12/2025.
//
#include "headers/controllers/restapi/HttpResult.h"
#include "headers/domain/shared/StringUtils.h"

using json::JSON;

HttpResult::HttpResult() : httpStatus(HttpStatus::HTTP_OK), result(json::Object()) {}

HttpResult::HttpResult(int httpStatus) : httpStatus(httpStatus), result(json::Object()) {}

HttpResult::HttpResult(int httpStatus, const std::string &msg)
        : httpStatus(httpStatus), result(json::Object()) {
    result["message"] = msg;
}

HttpResult::HttpResult(int httpStatus, const std::wstring &msg)
        : httpStatus(httpStatus), result(json::Object()) {
    result["message"] = StringUtils::toString(msg);
}

int HttpResult::getHttpStatus() const { return httpStatus; }

JSON HttpResult::getResult() const { return result; }

void HttpResult::setHttpStatus(int status) { httpStatus = status; }

void HttpResult::setJsonResult(const JSON &obj) { result = obj; }

void HttpResult::setMessage(const std::string &msg) {
    result = json::Object();
    result["message"] = msg;
}

void HttpResult::setMessage(const std::wstring &msg) {
    setMessage(StringUtils::toString(msg));
}