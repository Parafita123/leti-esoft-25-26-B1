//
// Created by Guta on 2026-01-04.
//

#include "../headers/VaccineRouter.h"

#include <headers/controllers/restapi/VaccineController.h>
#include <headers/controllers/restapi/HttpResult.h>
#include <headers/controllers/restapi/HttpStatus.h>

VaccineRouter::VaccineRouter() : RouterConfig("/vaccines") {}

void VaccineRouter::configure(httplib::Server &svr) {
    // Define a regex pattern that matches the base resource with an optional
    // trailing slash.  This is consistent with the pattern used for other
    // routers in the project.
    std::string base = this->baseResource + "(\\/?)";

    // GET /vaccines
    svr.Get(base, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            VaccineController ctrl(extractBearerToken(req));
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

    // POST /vaccines
    svr.Post(base, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            VaccineController ctrl(extractBearerToken(req));
            auto jsonObj = json::JSON::Load(req.body);
            // Optional fields default to empty if missing.  JSON::ToString
            // returns an empty string when the type is not String.
            std::string lotStr;
            std::string expStr;
            if (jsonObj.hasKey("lot")) {
                lotStr = jsonObj["lot"].ToString();
            }
            if (jsonObj.hasKey("expirationDate")) {
                expStr = jsonObj["expirationDate"].ToString();
            }
            result = ctrl.postVaccine(
                    jsonObj["commercialName"].ToString(),
                    jsonObj["brand"].ToString(),
                    jsonObj["typeCode"].ToString(),
                    jsonObj["technology"].ToString(),
                    lotStr,
                    expStr
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