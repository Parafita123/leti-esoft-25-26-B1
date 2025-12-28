//
// Created by Filipe on 28/12/2025.
//
#include "../headers/TasksServer.h"
#include "../headers/ServerStatusRouter.h"
#include "../headers/VaccineTypeRouter.h"

TasksServer::TasksServer() : logger(&std::cout) {}

TasksServer::TasksServer(std::ostream *logger) {
    this->logger = (logger == nullptr) ? &std::cout : logger;
}

void TasksServer::run() {
    run("0.0.0.0", 8080);
}

void TasksServer::run(int port) {
    run("0.0.0.0", port);
}

void TasksServer::run(std::string host, int port) {
    log("Welcome to the RestAPI Server.");
    log("HTTP Server is being configured...");

    // /status
    log("\t ... configuring server status resource...");
    ServerStatusRouter ssRouter;
    ssRouter.configure(this->svr);

    // /vaccine-types
    log("\t ... configuring vaccine-types resource...");
    VaccineTypeRouter vtRouter;
    vtRouter.configure(this->svr);

    log("HTTP Server is listening on port " + std::to_string(port) + ".");
    this->svr.listen(host.c_str(), port);
    log("HTTP Server is stopping.");
}

void TasksServer::log(const std::string &message) {
    (*logger) << message << std::endl;
}
