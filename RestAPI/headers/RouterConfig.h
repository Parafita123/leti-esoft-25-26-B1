//
// Created by Filipe on 28/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_ROUTERCONFIG_H
#define LETI_ESOFT_25_26_B1_ROUTERCONFIG_H

#pragma once
#include <string>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif

#include "../thirdparty/httplib.h"
#include <headers/controllers/restapi/HttpResult.h>

class RouterConfig {
protected:
    std::string baseResource;

    void setHttpResponse(httplib::Response &res, HttpResult &result);
    std::wstring extractBearerToken(const httplib::Request &req);

public:
    explicit RouterConfig(const std::string &baseResource);
    virtual ~RouterConfig() = default;

    virtual void configure(httplib::Server &svr) = 0;
};


#endif //LETI_ESOFT_25_26_B1_ROUTERCONFIG_H
