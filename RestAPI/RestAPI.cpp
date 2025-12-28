//
// Created by Filipe on 28/12/2025.
//
#include "../RestAPI/headers/TasksServer.h"

int main() {
    TasksServer server;
    server.run("0.0.0.0", 8080);  // ou 127.0.0.1 se preferires
    return 0;
}