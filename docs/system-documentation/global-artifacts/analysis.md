# OO Analysis

The construction process of the domain model is based on client specifications, especially the nouns (for *concepts*) and verbs (for *relations*) used.

## Rationale to identify domain conceptual classes

To identify domain conceptual classes, we start by making a list of candidate conceptual classes inspired by the categories suggested in the book *"Applying UML and Patterns: An Introduction to Object-Oriented Analysis and Design and Iterative Development."*

Sprint 2 introduces and consolidates concepts related to:

* **Vaccine type specification** (US10)
* **Vaccine registration** (US11)
* **Employee registration** (US14)
* **Listing employees by role** (US15)

These user stories extend the domain with new concepts such as **VaccineType**, **Vaccine**, **VaccineTechnology**, **Employee**, **Role**, and their corresponding registries/containers.

Sprint 3 introduces:

* **List of all vaccines** (US12).
* **Vaccination center registration** (US13).
* **SNS User registration** (US20).
* **Vaccination appointment scheduling** (US30).

---

### *Conceptual Class Category List*

#### **Business Transactions**

* Appointment – vaccination appointment request made by a patient (SNS user).
* Vaccination Process – record of the administration of a vaccine dose to a patient, including observation and adverse reactions.
* Vaccine Type Specification – creation of a new vaccine type by an Administrator (US10).
* Vaccine Registration – registration of a new vaccine, based on a defined type and technology (US11).
* Employee Registration – registration of a new employee (Nurse or Receptionist) by an Administrator (US14).
* Employee Listing by Role – retrieval of employees filtered by role (US15).
* SNS User Registration – registering a new SNS user (US20).
* Vaccination Center Registration – registering a new vaccination center (US13).
* Vaccine List Retrieval – listing all vaccines, grouped by type (US12).
* Vaccine Appointment Scheduling – scheduling a vaccine appointment (US30).

---

#### **Transaction Line Items**

* (No direct correspondence in the current domain.)

---

#### **Product/Service related to a Transaction or Transaction Line Item**

* Vaccine – biological product administered to induce immunity, associated with a vaccine type and a technology (US11).
* Vaccine Type – general classification of vaccines, including code, disease, and technology platform (US10).
* Vaccine Brand – commercial designation and manufacturer of a specific vaccine.
* Vaccine Technology – predefined technology platform (e.g. live-attenuated, inactivated, subunit, toxoid, viral vector, mRNA).
* SNS User – individual who can schedule and receive vaccinations (US20).

---

#### **Transaction Records**

* Vaccination Certificate – document issued after completing the vaccination schedule.
* Vaccination History – collection of vaccination records for a patient.
* Adverse Reaction Record – record of observed adverse reactions.
* Employee Record – persistent record of an employee with identity and contact details (US14).
* Vaccine Type Record – persistent record describing a vaccine type (US10).
* Vaccine Record – persistent record describing a vaccine (US11).
* SNS User Record – persistent record describing an SNS user (US20).
* Vaccination Center Record – persistent record describing a vaccination center (US13).

---

#### **Roles of People or Organizations**

* SNS User – individual with an SNS/NHS number who can schedule and receive vaccines (US20).
* Receptionist – employee who confirms attendance and manages appointments (US14/US15).
* Nurse – employee who administers vaccines and records the vaccination process (US14/US15).
* Administrator / DGS Administrator – user who manages vaccine types, vaccines, and employees (US10, US11, US14, US15).
* Employee – abstraction representing staff working in the vaccination system (specialised as Nurse and Receptionist).
* DGS – Directorate-General of Health, responsible for the vaccination programme.

---

#### **Places**

* Vaccination Center – location where vaccines are administered (fixed or temporary centres) (US13).

---

#### **Noteworthy Events**

* Appointment Created – when a patient books a vaccination.
* Vaccination Performed – when a vaccine is administered.
* Adverse Reaction Observed – when an adverse reaction is recorded.
* Vaccine Type Created – when a new vaccine type is specified by an Administrator (US10).
* Vaccine Registered – when a new vaccine is added to the system (US11).
* Employee Registered – when a new employee is created in the system (US14).
* Employees Listed by Role – when the system presents the list of employees filtered by a given role (US15).
* SNS User Registered – when a new SNS user is registered (US20).
* Vaccination Center Registered – when a new vaccination center is registered (US13).
* Vaccine Appointment Scheduled – when an SNS user schedules a vaccination appointment (US30).

---

#### **Physical Objects**

* Vaccine Dose – physical unit administered to a patient.
* Vaccine – concrete product prepared for administration.

---

#### **Descriptions of Things**

* Vaccination Center – name, address, opening hours, maximum capacity, etc. (US13)
* Vaccine – commercial name, brand, type code, disease target, batch, expiration date, technology (US11).
* Vaccine Type – unique code (ID), disease, short description, technology platform (US10).
* Vaccine Technology – label/identifier of the technology platform (live-attenuated, inactivated, subunit, toxoid, viral vector, mRNA).
* Vaccine Brand – trade name and manufacturer.
* User / SNS User – name, date of birth, gender, address, phone, email, identification numbers (US20).
* Employee – name, postal address, phone number, email, citizen card number, role (US14).
* Role – function performed by an employee (Nurse, Receptionist, Administrator).
* Appointment – date, time, centre, vaccine type requested, status (US30).
* Vaccination Process – date/time, vaccine, batch, nurse, observations, adverse reactions.
* Vaccination Certificate – identifies patient, vaccines, and administration dates.

---

#### **Catalogs**

* Vaccine Type Catalog – list of vaccine types that can be used when registering vaccines or scheduling appointments (US10).
* Vaccine Catalog – list of vaccines registered in the system (US11).
* Vaccination Centers Catalog – list of active fixed and temporary vaccination centres (US13).
* Employee Catalog – list of all employees registered in the system and their roles (US14/US15).
* Appointment Catalog – list of all vaccination appointments (US30).

---

#### **Containers**

* User Registry – collection of all SNS users (US20).
* Personnel / Employee Registry – collection of all employees (Nurses, Receptionists, Administrators) (US14).
* Appointment Registry – collection of all appointments in the system (US30).
* Vaccine Type Container – container responsible for storing and managing all vaccine types (US10).
* Vaccine Container – container responsible for storing and managing all vaccines (US11).
* Employee Container – container responsible for storing and managing employees (US14/US15).

---

#### **Elements of Containers**

* Individual User – element of the User Registry (US20).
* Individual Employee – element of the Employee Container.
* Individual Vaccine Type – element of the Vaccine Type Container.
* Individual Vaccine – element of the Vaccine Container.
* Individual Appointment – element of the Appointment Registry (US30).

---

#### **(Other) Organizations**

* DGS – Directorate-General of Health, that defines vaccination policies and requirements.

---

#### **Other (External/Collaborating) Systems**

* SNS / NHS – national health system, where users and health information are registered.
* Adverse Reaction Reporting Systems – external systems that receive adverse reaction reports.

---

#### **Records of finance, work, contracts, legal matters**

* Not applicable in the current scope.

---

#### **Financial Instruments**

* Not applicable.

---

#### **Documents mentioned/used to perform some work**

* Vaccination Certificate – proof issued after vaccination.
* Adverse Reaction Report – document with clinical details of adverse events.
* Employee Record – internal administrative document with employee personal and contact details.

---

## Rationale to identify associations between conceptual classes

An association is a relationship between instances of objects that indicates a relevant connection that should be remembered or can be derived from common association patterns:

* ***A*** is physically or logically part of ***B***
* ***A*** is physically or logically contained in/on ***B***
* ***A*** is a description for ***B***
* ***A*** is known/logged/recorded/reported/captured in ***B***
* ***A*** uses or manages or owns ***B***
* ***A*** is related to a transaction (item) of ***B***
* etc.

The following table summarises the main associations relevant for Sprint 2 (US10, US11, US14, US15) and Sprint 3 (US12, US13, US20, US30):

| **Concept (A)**      | **Association**         | **Concept (B)**         |
| -------------------- | ----------------------- | ----------------------- |
| SNS User             | schedules               | Appointment             |
| SNS User             | owns                    | Vaccination History     |
| SNS User             | receives vaccination at | Vaccination Center      |
| SNS User             | obtains                 | Vaccination Certificate |
| Receptionist         | manages                 | Appointment             |
| Nurse                | administers             | Vaccine                 |
| Nurse                | records                 | Vaccination Process     |
| Administrator        | manages                 | Vaccination Center      |
| Administrator        | manages                 | Employee                |
| Administrator        | creates                 | Vaccine Type            |
| Administrator        | registers               | Vaccine                 |
| Administrator        | registers               | Employee                |
| Administrator        | lists                   | Employee (by Role)      |
| Vaccination Center   | hosts                   | Employee                |
| Vaccination Center   | stores                  | Vaccine                 |
| Vaccine              | belongs to              | Vaccine Type            |
| Vaccine              | uses technology         | Vaccine Technology      |
| Vaccine              | produced by             | Vaccine Brand           |
| Appointment          | scheduled at            | Vaccination Center      |
| Appointment          | requests                | Vaccine Type            |
| Vaccination Process  | refers to               | Vaccine                 |
| Vaccination Process  | reports                 | Adverse Reaction        |
| Vaccine Type Catalog | contains                | Vaccine Type            |
| Vaccine Container    | contains                | Vaccine                 |
| Employee Container   | contains                | Employee                |
| Employee             | has                     | Role                    |
| Employee             | works at                | Vaccination Center      |
| SNS User             | registers               | SNS User                |

---

## Domain Model

The domain model for Sprint 2 and Sprint 3 incorporates all the above conceptual classes and associations. It includes at least the following core concepts:

* **Actors / People**: SNS User, Administrator, Nurse, Receptionist, Employee
* **Medical domain**: Vaccine, VaccineType, VaccineBrand, VaccineTechnology, VaccinationProcess, VaccinationCenter
* **Administration / Staff management**: Employee, Role, EmployeeContainer
* **Catalogs / Containers**: VaccineTypeCatalog, VaccineContainer, EmployeeContainer, AppointmentRegistry

These classes, together with their attributes and associations, are represented in the domain model diagram:

![DM.svg](svg/DM.svg)
