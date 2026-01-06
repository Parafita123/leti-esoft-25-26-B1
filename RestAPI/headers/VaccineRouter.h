//
// Created by Guta on 2026-01-04.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINEROUTER_H
#define LETI_ESOFT_25_26_B1_VACCINEROUTER_H

#include "RouterConfig.h"

/**
 * Router configuration for the vaccine REST resource.  This
 * router registers handlers for GET and POST requests on the
 * `/vaccines` endpoint, delegating business logic to the
 * VaccineController.  It follows the same pattern used for
 * VaccineTypeRouter, including bearer token enforcement and
 * JSON parsing.
 */
class VaccineRouter : public RouterConfig {
public:
    VaccineRouter();
    void configure(httplib::Server &svr) override;
};

#endif // LETI_ESOFT_25_26_B1_VACCINEROUTER_H