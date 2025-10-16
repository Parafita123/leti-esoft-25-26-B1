# Supplementary Specification (FURPS+)

## Functionality

_Specifies functionalities that:  
&nbsp; &nbsp; (i) are common across several US/UC;  
&nbsp; &nbsp; (ii) are not related to US/UC, namely: Audit, Reporting and Security._

- Security:
    - Authentication: Integration with the _JoeProfiles_ system (cf. "... and authentication process, ... done through an integration with the  _JoeProfiles_ system")
- Reporting: 
    - General support is required since it is stated that "the user must be also able to access a set of reports"

## Usability 

_Evaluates the user interface. It has several subcategories,
among them: error prevention; interface aesthetics and design; help and
documentation; consistency and standards._

- "A rudimentary console User Interface (UI) might be developed just for demonstration purposes"

## Reliability
_Refers to the integrity, compliance and interoperability of the software. The requirements to be considered are: frequency and severity of failure, possibility of recovery, possibility of prediction, accuracy, average time between failures._

- n/a

## Performance
_Evaluates the performance requirements of the software, namely: response time, start-up time, recovery time, memory consumption, CPU usage, load capacity and application availability._

- n/a

## Supportability
_The supportability requirements gathers several characteristics, such as:
testability, adaptability, maintainability, compatibility,
configurability, installability, scalability and more._ 

- Testing:
    - Applying a TDD approach since it is stated "...adopt ...such as TDD and ..." 
    - "...development of the domain business logic... should be widely verified/validated by automatic regression tests"

- Others:
    - cf. "Adopt the English language as the default for development artifacts"

## +

### Design Constraints

_Specifies or constraints the system design process. Examples may include: programming languages, software process, mandatory standards/patterns, use of development tools, class library, etc._

- Adopting the OO paradigm (cf. "...adopt the best OO software development practices...")
- Adopting GRASP patterns (cf. "adopt the best ... practices, such as ... GRASP patterns")
- Adopting SOLID patterns (cf. "adopt the best ... practices, such as ... SOLID patterns")
- "Adopt the English language as the default for development artifacts"

### Implementation Constraints

_Specifies or constraints the code or construction of a system such
such as: mandatory standards/patterns, implementation languages,
database integrity, resource limits, operating system._

- "Adopt the English language ... including in the code";
- Using C++ as stated in "implement the core software parts ... in C++"

### Interface Constraints
_Specifies or constraints the features inherent to the interaction of the
system being developed with other external systems._

- Integration with _JoeProfiles_ for user registration and authentication (cf. "... done through an integration with the  _JoeProfiles_ system ...")

### Physical Constraints

_Specifies a limitation or physical requirement regarding the hardware used to house the system, as for example: material, shape, size or weight._

- n/a