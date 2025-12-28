//
// Created by Filipe on 28/12/2025.
//
#include "../headers/VaccineTypeRouter.h"

#include <headers/controllers/restapi/VaccineTypeController.h>
#include <headers/controllers/restapi/HttpResult.h>
#include <headers/controllers/restapi/HttpStatus.h>

VaccineTypeRouter::VaccineTypeRouter() : RouterConfig("/vaccine-types") {}

void VaccineTypeRouter::configure(httplib::Server &svr) {

    std::string base = this->baseResource + "(\\/?)";

    // GET /vaccine-types
    svr.Get(base, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            VaccineTypeController ctrl(extractBearerToken(req));
            result = ctrl.getAll();
        } catch (const std::invalid_argument&) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
            result.setMessage("Bearer Token Authorization is required.");
        } catch (...) {
            result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
            result.setMessage("Unexpected server error.");
        }
        setHttpResponse(res, result);
    });

    // POST /vaccine-types
    svr.Post(base, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            VaccineTypeController ctrl(extractBearerToken(req));
            auto jsonObj = json::JSON::Load(req.body);

            result = ctrl.postVaccineType(
                    jsonObj["typeCode"].ToString(),
                    jsonObj["disease"].ToString(),
                    jsonObj["description"].ToString()
            );
        } catch (const std::invalid_argument&) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
            result.setMessage("Bearer Token Authorization is required.");
        } catch (...) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
            result.setMessage("Invalid JSON body.");
        }
        setHttpResponse(res, result);
    });
}