//
// Created by Filipe on 28/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_TASKSSERVER_H
#define LETI_ESOFT_25_26_B1_TASKSSERVER_H

#include "../headers/VaccineTypeRouter.h"
#include <iostream>
#include <string>
#include "../thirdparty/httplib.h"

class TasksServer {
private:
    httplib::Server svr;
    std::ostream *logger;

    void log(const std::string &message);

public:
    TasksServer();
    explicit TasksServer(std::ostream *logger);

    void run();
    void run(int port);
    void run(std::string host, int port);
};
#endif //LETI_ESOFT_25_26_B1_TASKSSERVER_H
