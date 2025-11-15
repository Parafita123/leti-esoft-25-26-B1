//
// Created by Filipe on 13/11/2025.
//

#ifndef UNTITLED1_MAINVIEW_H
#define UNTITLED1_MAINVIEW_H

#include "headers/controllers/ui/App.h"

class MainView {
private:
    App& app;   // acesso ao “mundo” da aplicação (containers, etc.)

    void showMenu() const;
    void handleOption(int option);

public:
    explicit MainView(App& app);

    // loop principal do menu
    void show();
};

#endif //UNTITLED1_MAINVIEW_H
