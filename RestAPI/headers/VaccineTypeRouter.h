//
// Created by Filipe on 28/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINETYPEROUTER_H
#define LETI_ESOFT_25_26_B1_VACCINETYPEROUTER_H


#include "RouterConfig.h"

class VaccineTypeRouter : public RouterConfig {
public:
    VaccineTypeRouter();
    void configure(httplib::Server &svr) override;
};

#endif //LETI_ESOFT_25_26_B1_VACCINETYPEROUTER_H
