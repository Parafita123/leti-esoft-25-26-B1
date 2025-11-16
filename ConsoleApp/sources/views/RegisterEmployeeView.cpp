//
// Created by diogo on 16/11/2025.
//
#include "../../headers/views/RegisterEmployeeView.h"

#include <codecvt>
#include <iostream>
#include <locale>

static std::string ws2s(const std::wstring& w) {
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    return conv.to_bytes(w);
}
RegisterEmployeeView::RegisterEmployeeView(RegisterEmployeeController controller)
        : controller(controller) {}

void RegisterEmployeeView::run()
{
    std::string name, postalAddress, phone, email, cc, role;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter postal address: ";
    std::getline(std::cin, postalAddress);

    std::cout << "Enter phone: ";
    std::getline(std::cin, phone);

    std::cout << "Enter email: ";
    std::getline(std::cin, email);

    std::cout << "Enter citizen card number: ";
    std::getline(std::cin, cc);

    std::cout << "Select role (nurse/receptionist): ";
    std::getline(std::cin, role);

    Employee e = controller.createEmployee(name, postalAddress, phone, email, cc, role);

    std::cout << "\nConfirm registration? (y/n): ";
    char c;
    std::cin >> c;

    if (c == 'y' || c == 'Y')
    {
        Result r = controller.saveRegisteredEmployee(e);
        std::cout << ws2s(r.getMessage()) << "\n";
    }
    else
    {
        std::cout << "Operation cancelled.\n";
    }
}