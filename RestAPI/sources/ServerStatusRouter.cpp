//
// Created by Filipe on 28/12/2025.
//

#include "../headers/ServerStatusRouter.h"
#include <headers/controllers/restapi/HttpResult.h>

ServerStatusRouter::ServerStatusRouter() : RouterConfig("/status") {}

void ServerStatusRouter::configure(httplib::Server &svr) {
    this->server = &svr;

    std::string patternBase = this->baseResource + "(\\/?)";

    // GET /status  -> 200 OK
    svr.Get(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result(HttpStatus::HTTP_OK);
        result.setJsonResult("OK");
        setHttpResponse(res, result);
    });

    // POST /status/stop -> para o servidor
    std::string patternStop = this->baseResource + "/stop";
    svr.Post(patternStop, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result(HttpStatus::HTTP_OK);
        result.setJsonResult("Shutting down the server.");
        setHttpResponse(res, result);

        if (this->server) this->server->stop();
    });

    // handler para 404 etc
    svr.set_error_handler([&](const auto &req, auto &res) {
        if (res.status == HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND) {
            HttpResult result(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND);
            std::string msg = "Resource not found: " + req.method + " " + req.path;
            result.setJsonResult(msg);
            setHttpResponse(res, result);
        }
    });

    // handler de exceptions
    svr.set_exception_handler([&](const auto &req, auto &res, std::exception &e) {
        HttpResult result(HttpStatus::HTTP_SERVER_ERROR);
        result.setJsonResult("An error occurred on server.");
        setHttpResponse(res, result);
    });
}
