//
// Created by Filipe on 12/12/2025.
//
#include "headers/domain/model/Facility.h"

Facility::Facility(std::string name,
                   std::string postal_address,
                   std::string phone_number,
                   std::string email,
                   std::string website_address,
                   std::string opening_hours,
                   std::string closing_hours,
                   int max_vaccines_per_hour)
        : name(std::move(name)),
          postal_address(std::move(postal_address)),
          phone_number(std::move(phone_number)),
          email(std::move(email)),
          website_address(std::move(website_address)),
          opening_hours(std::move(opening_hours)),
          closing_hours(std::move(closing_hours)),
          max_vaccines_per_hour(max_vaccines_per_hour) {}

const std::string& Facility::getName() const { return name; }
