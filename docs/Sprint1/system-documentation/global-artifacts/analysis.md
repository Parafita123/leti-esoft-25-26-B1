# OO Analysis

The construction process of the domain model is based on client specifications, especially the nouns (for *concepts*) and verbs (for *relations*) used.

## Rationale to identify domain conceptual classes

To identify domain conceptual classes, start by making a list of candidate conceptual classes inspired by the list of categories suggested in the book *"Applying UML and Patterns: An Introduction to Object-Oriented Analysis and Design and Iterative Development."*

### *Conceptual Class Category List*

**Business Transactions**

* Appointment – vaccination appointment request made by a patient.
* Vaccination Process – record of the administration of a vaccine dose to a patient, including observation and adverse reactions.

---

**Transaction Line Items**

* (No direct correspondence in the current domain)

---

**Product/Service related to a Transaction or Transaction Line Item**

* Vaccine – biological product administered to induce immunity.
* Vaccine Type – general classification (mRNA, recombinant protein, inactivated virus, etc.).
* Vaccine Brand – commercial designation and manufacturer of a specific vaccine.

---

**Transaction Records**

* Vaccination Certificate – document issued after completing the vaccination schedule.
* Vaccination History – collection of vaccination records for a patient.
* Adverse Reaction Record – record of observed adverse reactions.

---

**Roles of People or Organizations**

* SNS User – individual with an NHS number who can schedule and receive vaccines.
* Receptionist – staff member who confirms attendance and records appointment status.
* Nurse – professional who administers vaccines and records the act.
* DGS Administrator – person who manages centers, staff, and configurations.

---

**Places**

* Vaccination Center – vaccination location (fixed and temporary centers).

---

**Noteworthy Events**

* Appointment Created – when a patient books a vaccination.
* Vaccination Performed – when a vaccine is administered.
* Adverse Reaction Observed – when an adverse reaction is recorded.

---

**Physical Objects**

* Vaccine Dose – physical unit administered.

---

**Descriptions of Things**

* Vaccination Center – includes name, address, schedule, and maximum capacity.
* Vaccine – code, target disease, description, batch, expiration date.
* Vaccine Type – technology (mRNA, protein subunit, etc.).
* Vaccine Brand – trade name and manufacturer.
* User – name, date of birth, gender, address, contact, and identifiers.
* Personnel – data of receptionists and nurses.
* Appointment – date, time, center, and vaccine type.
* Vaccination Process – date, time, type, brand, batch, notes.
* Vaccination Certificate – identifies patient, vaccines, and dates.

---

**Catalogs**

* Vaccine Type Catalog – list of the various approved vaccine technologies.
* Vaccine Brand Catalog – list of available commercial brands.
* Vaccination Centers Catalog – list of active centers (fixed and temporary).

---

**Containers**

* User Registry – collection of all patients registered in the system.
* Personnel Registry – list of all employees (receptionists and nurses).
* Appointment Registry – list of all scheduled appointments.
* Vaccine Inventory – stock of vaccines and their available batches at each center.

---

**Elements of Containers**

* (No additional elements identified)

---

**(Other) Organizations**

* DGS – Directorate-General of Health.

---

**Other (External/Collaborating) Systems**

* NHS – National Health Service.
* Adverse Reaction Reporting Systems – external notification systems.

---

**Records of finance, work, contracts, legal matters**

* (Not applicable)

---

**Financial Instruments**

* (Not applicable)

---

**Documents mentioned/used to perform some work**

* Vaccination Certificate – proof issued after vaccination.
* Adverse Reaction Report – documents sent for clinical analysis.

---

## Rationale to identify associations between conceptual classes

An association is a relationship between instances of objects that indicates a relevant connection worth remembering, or one that can be derived from the List of Common Associations:

* ***A*** is physically or logically part of ***B***
* ***A*** is physically or logically contained in/on ***B***
* ***A*** is a description for ***B***
* ***A*** is known/logged/recorded/reported/captured in ***B***
* ***A*** uses or manages or owns ***B***
* ***A*** is related to a transaction (item) of ***B***
* etc.

| **Concept (A)**     |     **Association**     |         **Concept (B)** |
| :------------------ | :---------------------: | ----------------------: |
| SNS User            |        schedules        |             Appointment |
| SNS User            |           owns          |     Vaccination History |
| SNS User            | receives vaccination at |      Vaccination Center |
| SNS User            |         obtains         | Vaccination Certificate |
| Receptionist        |         manages         |             Appointment |
| Nurse               |       administers       |                 Vaccine |
| Nurse               |         records         |     Vaccination Process |
| DGS Administrator   |         manages         |      Vaccination Center |
| DGS Administrator   |         manages         |               Personnel |
| DGS Administrator   |         manages         |         Vaccine Catalog |
| Vaccination Center  |          hosts          |               Personnel |
| Vaccination Center  |          stores         |                 Vaccine |
| Vaccine             |        belongs to       |            Vaccine Type |
| Vaccine             |       produced by       |           Vaccine Brand |
| Appointment         |       scheduled at      |      Vaccination Center |
| Appointment         |         requests        |            Vaccine Type |
| Vaccination Process |        refers to        |                 Vaccine |
| Vaccination Process |         reports         |        Adverse Reaction |

---

## Domain Model

![DM.svg](svg/DM.svg)
