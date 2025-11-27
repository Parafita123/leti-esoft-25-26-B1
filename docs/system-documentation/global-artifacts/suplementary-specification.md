# Supplementary Specification (FURPS+)

## Functionality

_Specifies functionalities that:_  
&nbsp;&nbsp;(i) are common across several US/UC;  
&nbsp;&nbsp;(ii) are not related to US/UC, namely: Audit, Reporting and Security._

- **Security:**
  - **Authentication:** The system must include a secure authentication mechanism that validates the identity of each user (Administrator, Nurse, Receptionist, or SNS User).
  - **Authorization:** Access to features and data must be restricted according to user roles — for example, only nurses can access health and vaccination history of SNS users.
  - **Data Protection:** Sensitive data (e.g., personal and medical information) must be stored securely and handled according to GDPR principles.

- **Reporting:**
  - General reporting capabilities are required to allow DGS administrators to obtain information about vaccination progress, center performance, vaccine usage, and user statistics.
  - Reports should allow filtering and aggregation by vaccine type, date, location, and other relevant parameters.

- **Audit:**
  - The system must record relevant operational events such as user logins, appointment scheduling, vaccination registration, and data modifications.
  - Audit logs must be accessible to administrators for verification and accountability purposes.

---

## Usability

_Evaluates the user interface. It has several subcategories, among them: error prevention; interface aesthetics and design; help and documentation; consistency and standards._

- A **rudimentary console-based User Interface (UI)** may be implemented for demonstration purposes.
- The UI should be **clear, consistent, and intuitive**, allowing users to easily perform their tasks.
- Input validation must be applied to prevent data entry errors (e.g., invalid dates or duplicated SNS numbers).
- All system messages, menus, and documentation must be written in **English**.
- Consistent terminology, structure, and flow must be maintained throughout the system to ensure usability.

---

## Reliability

_Refers to the integrity, compliance and interoperability of the software. The requirements to be considered are: frequency and severity of failure, possibility of recovery, possibility of prediction, accuracy, average time between failures._

- The system must ensure **data integrity** in all transactions (e.g., appointment scheduling, vaccination recording).
- In the event of an unexpected failure, operations should not result in data corruption.
- The system should allow **recovery from transient errors** such as database connection issues.
- Each vaccination event must be recorded accurately and consistently to prevent duplication or loss of data.

---

## Performance

_Evaluates the performance requirements of the software, namely: response time, start-up time, recovery time, memory consumption, CPU usage, load capacity and application availability._

- No strict performance requirements are defined for the prototype version.
- The system should provide acceptable response times under normal conditions of use (e.g., scheduling an appointment or recording a vaccination event).
- The prototype should be capable of managing a representative dataset (e.g., several thousand users and vaccination records) without degradation of usability.

---

## Supportability

_The supportability requirements gather several characteristics, such as: testability, adaptability, maintainability, compatibility, configurability, installability, scalability and more._

- **Testing:**
  - A **Test-Driven Development (TDD)** approach should be adopted.
  - The **domain business logic** must be verified through **automatic regression tests** to ensure correctness and prevent future errors.

- **Adaptability:**
  - The system should be easily adaptable to new pandemic scenarios or additional vaccine types.

- **Maintainability:**
  - The codebase must follow **Object-Oriented principles**, applying **GRASP** and **SOLID** design patterns to ensure modularity and maintainability.
  - All development artifacts (code, documentation, diagrams) must be in **English**.

- **Compatibility and Configurability:**
  - The system architecture should allow integration with other health systems (e.g., SNS databases or national vaccination registries).
  - Configuration files or parameters should enable easy adaptation to different deployment environments.

---

## +

### Design Constraints

_Specifies or constrains the system design process. Examples may include: programming languages, software process, mandatory standards/patterns, use of development tools, class library, etc._

- Adopting the **Object-Oriented (OO)** paradigm (cf. "...adopt the best OO software development practices...").
- Applying **GRASP** and **SOLID** patterns (cf. "adopt the best ... practices, such as ... GRASP patterns").
- Following a modular, layered architecture separating domain logic, data access, and presentation.
- Using **English** as the default language for all code and documentation.

---

### Implementation Constraints

_Specifies or constrains the code or construction of a system such as: mandatory standards/patterns, implementation languages, database integrity, resource limits, operating system._

- The core software parts must be implemented in **C++** (cf. "implement the core software parts ... in C++").
- Code, identifiers, and comments must be written in **English**.
- Database design must ensure **referential integrity** and prevent inconsistent data (e.g., orphaned records or invalid references).
- The prototype must be executable on standard computing environments without specific hardware dependencies.

---

### Interface Constraints

_Specifies or constrains the features inherent to the interaction of the system being developed with other external systems._

- The system must allow future **integration with national health databases** (e.g., SNS or DGS platforms) to validate user information or synchronize vaccination data.
- Interfaces must ensure **secure data exchange** and comply with privacy regulations.
- No external system integration is required for the current prototype stage.

---

### Physical Constraints

_Specifies a limitation or physical requirement regarding the hardware used to house the system, as for example: material, shape, size or weight._

- **n/a** — No specific physical or hardware requirements are defined for this prototype.
- The application is expected to run on a standard workstation or institutional computing environment.

---
