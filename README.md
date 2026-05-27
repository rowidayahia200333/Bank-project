# Bank Management System 🏦

A robust, enterprise-inspired console application implemented in C++ that demonstrates high-level mastery of Object-Oriented Programming (OOP) principles. The system delivers tailored workflows for three distinct user roles (Clients, Employees, and Admins) and utilizes a custom-built file database for seamless data preservation.

---

## 🛠️ System Architecture & Data Flow

Unlike basic memory-volatile console applications, this project implements Data Persistence through local file streams. The heart of the system’s data layer relies on two specialized structural utilities:

### 1. The Parser Blueprint
The Parser class acts as the system's ETL (Extract, Transform, Load) engine. It bridges the gap between raw unstructured disk storage and active runtime RAM memory:
* Serialization: Decodes object memory footprints into highly structured, delimited record string patterns suited for standard output streaming.
* Deserialization: Tokenizes raw record lines, handles strict casting transitions, and recreates fully populated dynamic instances of Client, Employee, or Admin without structure degradation.

### 2. The FilesHelper Engine
An abstraction layer wrapping local file system directories. It coordinates secure bidirectional file access operations:
* Prevents data corruption during continuous write commits.
* Automates bulk vector loading routines to buffer data sets directly into runtime memory arrays on core launch sequences.
* Syncs real-time transactional runtime mutations back into flat file arrays upon graceful execution endings.

---

## 💻 Technical Depth & OOP Implementations

* Encapsulation & Clean Data Models: Structured domain models (Person, Client, Employee, Admin) enforce absolute state protection via strict access specifiers, private data fields, and unified input/output validation routines.
* Structural Inheritance: Eliminates redundant data declarations by establishing a core Person class, enabling specialized role expansions with focused structural traits.
* Unified UI Orchestration: The Screen::runApp() static gateway abstracts complex execution control, managing dynamic menus and context-switching without code coupling.

---

## 📂 Architectural Breakdown

The physical solution layout follows a modular design pattern to divide domain business definitions cleanly:

*   Client.h / Client.cpp — Context bounds for ledger balances, direct transactions, and password identity states.
*   Employee.h / Employee.cpp — Operations to register clients, update account indicators, and manage standard account loops.
*   Admin.h / Admin.cpp — Top-tier access tier empowering personnel allocation, corporate tracking, and system configuration overrides.
*   Parser.h — Custom string-tokenization mapping rules translating text into entities.
*   FilesHelper.h — Low-level local disk transaction layer.
*   Screen.h — The main presentation logic handling command-line dashboard interactions.

---

## 🚀 How to Build & Run

1. Clone or download this solution workspace files onto your environment.
2. Launch the underlying project solution tree configuration via Visual Studio.
3. Compile and launch the execution runtime using the Local Windows Debugger tool target.
