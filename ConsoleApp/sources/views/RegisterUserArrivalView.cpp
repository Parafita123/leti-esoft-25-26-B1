//
// Created by Filipe on 20/12/2025.
//

#include "../ConsoleApp/headers/views/RegisterUserArrivalView.h"

#include <iostream>
#include <limits>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
#include <locale>

#include "headers/controllers/dto/UserArrivalDTO.h"
#include "headers/controllers/dto/FacilityDto.h"   // <<-- IMPORTANT

RegisterUserArrivalView::RegisterUserArrivalView(RegisterUserArrivalController& controller)
        : controller(controller) {}

bool RegisterUserArrivalView::askYesNo(const std::string& prompt) {
    while (true) {
        std::cout << prompt << " (Y/N): ";
        std::string ans;
        std::getline(std::cin, ans);

        if (ans == "Y" || ans == "y") return true;
        if (ans == "N" || ans == "n") return false;

        std::cout << "Please type Y or N.\n";
    }
}

void RegisterUserArrivalView::printNowTimestamp() {
    using namespace std::chrono;
    auto now = system_clock::now();
    std::time_t t = system_clock::to_time_t(now);

    std::cout << "Arrival time (now): "
              << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S")
              << "\n";
}

void RegisterUserArrivalView::show() {
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    std::cout << "\n=== US22 - Register SNS User Arrival ===\n";

    // 1) list facilities (controller -> repo)
    std::vector<FacilityDto> facilities = controller.listFacilities();
    if (facilities.empty()) {
        std::cout << "No facilities available.\n";
        return;
    }

    // 2) show and ask facility
    std::cout << "\nSelect the facility:\n";
    for (size_t i = 0; i < facilities.size(); ++i) {
        // FacilityDto is NOT a pointer, so use '.'
        // Adjust names if your dto uses different fields
        std::cout << "  " << (i + 1) << " - " << facilities[i].name << " (id=" << facilities[i].facilityID << ")\n";
    }

    int option = 0;
    while (true) {
        std::cout << "Facility option (1-" << facilities.size() << "): ";
        if (!(std::cin >> option)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (option >= 1 && static_cast<size_t>(option) <= facilities.size()) break;
        std::cout << "Out of range. Try again.\n";
    }

    // According to SD/CD: facilityID goes into DTO (use real facility id, not menu option)
    const FacilityDto selectedFacility = facilities[option - 1];
    const int facilityId = selectedFacility.facilityID;

    // 3) system asks SNS number, user types it
    int snsNumber = 0;
    while (true) {
        std::cout << "\nSNS User number: ";
        if (!(std::cin >> snsNumber)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid number. Try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }

    // 4) ask controller for summary (controller uses repo)
    // Controller likely expects string. If yours expects int, change this line accordingly.
    auto userOpt = controller.getSNSUserSummary(snsNumber);
    if (!userOpt.has_value()) {
        std::cout << "SNS User not found.\n";
        return;
    }

    SNSUserDto user = userOpt.value();
    std::cout << "\nUser found:\n";
    std::cout << "  Name: " << user.name << "\n";
    std::cout << "  SNS Number: " << user.snsUserNumber << "\n";

    // 5) records arrival time (now)
    std::cout << "\n";
    printNowTimestamp();

    // 6) build DTO
    UserArrivalDTO dto;
    dto.facilityID = facilityId;
    dto.sns_user_number = snsNumber; // int, matches your current DTO

    // 7) show DTO and ask confirmation
    std::cout << "\nYou entered:\n";
    std::cout << "  Facility: " << selectedFacility.name << " (id=" << dto.facilityID << ")\n";
    std::cout << "  SNS user number: " << dto.sns_user_number << "\n";

    if (!askYesNo("Confirm arrival registration?")) {
        std::cout << "Operation cancelled.\n";
        return;
    }

    // 8) call controller
    Result res = controller.registerArrival(dto);

    if (res.isOK()) {
        std::cout << "\nArrival registered successfully.\n";
        if (!res.getMessage().empty()) {
            std::wcout << L"Message: " << res.getMessage() << L"\n";
        }
    } else {
        std::cout << "\nFailed to register arrival.\n";
        if (!res.getMessage().empty()) {
            std::wcout << L"Reason: " << res.getMessage() << L"\n";
        }
    }
}
