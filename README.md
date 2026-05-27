# Bank Management System 🏦

A comprehensive console-based Bank Management System implemented in C++ that demonstrates the core principles of Object-Oriented Programming (OOP). The application provides separate, secure dashboards for Clients, Employees, and Admins to manage accounts and banking workflows.

## 🛠️ Key Features
- Three-Tier User System: Distinct functionalities and access levels for Clients, Employees, and Admins.
- Data Persistence: Built-in storage mechanism that saves and loads all entity records seamlessly using file handling.
- Robust Architecture: Uses dedicated components like a custom Parser for string-to-object mapping and a FilesHelper utility to manage text files safely.
- Input Validation: Clean and managed screens to prevent execution crashes during runtime transactions.

## 💻 Tech Stack & Concepts
- Language: C++
- Paradigm: Object-Oriented Programming (Inheritance, Polymorphism, Encapsulation, Abstraction).
- Storage: Text-file based database (File I/O Streams).

## 📂 Project Structure Highlights
- Client.h / Client.cpp - Handles client balances, details, and personal operations.
- Employee.h / Employee.cpp - Manages client accounts and basic bank operations.
- Admin.h / Admin.cpp - Controls employee records and system-wide configurations.
- Parser.h - Parses structured text lines into functional class objects.
- FilesHelper.h - Handles reading from and writing to local data stores.
- Screen.h - Orchestrates the command-line interface (runApp()).

## 🚀 How to Run
1. Clone the repository or download the source files.
2. Open the solution in Visual Studio.
3. Compile and build the project using the Local Windows Debugger.
