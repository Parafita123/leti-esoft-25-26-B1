//
// Created by Filipe on 28/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_HTTPSTATUS_H
#define LETI_ESOFT_25_26_B1_HTTPSTATUS_H

#pragma once

struct HttpStatus {
    static const int HTTP_OK = 200;
    static const int HTTP_OK_EMPTY = 204;

    static const int HTTP_CREATED = 201;

    static const int HTTP_CLIENT_ERROR_BAD_REQUEST = 400;
    static const int HTTP_CLIENT_ERROR_NOT_AUTH = 401;
    static const int HTTP_CLIENT_ERROR_NOT_FOUND = 404;

    static const int HTTP_SERVER_ERROR = 500;
};

#endif //LETI_ESOFT_25_26_B1_HTTPSTATUS_H
