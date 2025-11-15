#include "Core/headers/controllers/ui/App.h"
#include "ConsoleApp/headers/views/MainView.h"

int main() {
    App app;
    MainView mainView(app);

    mainView.show();

    return 0;
}