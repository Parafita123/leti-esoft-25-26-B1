# Describing App Initialization

## Overview of the Designed Approach

- **App** is a singleton.
- The method **GetInstance** is _static_. Notice it is being called on the class and not to an **App instance** (the **":"** denotes an instance).
- The **App instance** is being created in a _lazy load_ fashion, i.e. it's created only when needed for the first time.
- The concrete **FactoryRepository** to be used is determined according to the configured information existing on the **config.ini** file which can be changed during the system implantation/deployment.
- Further, the created **FactoryRepository** is used to provide the object person, a way to get its own repositories.

![AppInit](AppInit.svg)

**It is a best practice to pass dependencies for a given object (e.g. Person) through its constructor.**

This best practice fosters maintainability and testability. 