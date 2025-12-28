#include "Core/headers/controllers/ui/App.h"
#include "ConsoleApp/headers/views/MainView.h"
#include "RestAPI/headers/TasksServer.h"

int main() {
    App app;
    MainView mainView(app);

    mainView.show();

    return 0;
}