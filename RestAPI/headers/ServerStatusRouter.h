//
// Created by Filipe on 28/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_SERVERSTATUSROUTER_H
#define LETI_ESOFT_25_26_B1_SERVERSTATUSROUTER_H

#include "RouterConfig.h"

class ServerStatusRouter : public RouterConfig {
private:
    httplib::Server* server = nullptr;

public:
    ServerStatusRouter();
    void configure(httplib::Server &svr) override;
};

#endif //LETI_ESOFT_25_26_B1_SERVERSTATUSROUTER_H
