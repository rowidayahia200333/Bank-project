#pragma once
#include "EmployeeManager.h"
#include"Admin.h"


class AdminManager :public EmployeeManager

{
public:
    static Admin* search(int id, const string& password) {

        vector<Admin>& admins = Admin::get_all_Admins();

        for (auto& a : admins) {

            if (a.get_id() == id && a.get_password() == password) {
                return (&a);
            }

        }
        return nullptr;
    }

    static Admin* login(int id, const string& password) {
        Admin* a = search(id, password);

        if (a != nullptr) return a;
        return nullptr;
    }

    static void  printEmployeeMenu() {
        cout << "\n======Admin menu=====\n";
        cout << "What would you like to do?\n\n"
            << "1- Display your info.\n2- Add a new Client.\n3- Search for a client.\n4- List all clients.\n"
            << "5- Edit a client info.\n6- Add a new Employee.\n7- Search for an employee.\n8- List all employees.\n9 - Edit an employee info.\n"
            << "10- Change your password.\n11- Logout\n\n";
    }

    static void newEmployee(Admin* admin) {
        string name{}, pass{};
        double salary{};
        cout << "Please enter the Employee info: \n";
        name = DataEntry::tryName();
        cout << "\n";
        pass = DataEntry::TryPassword();
        cout << "\n";
        salary = DataEntry::trySalary();
        cin.ignore();

        int id = FilesHelper::getLast("EmployeeLastId.txt.txt");
        id++;
        FilesHelper::saveLast("EmployeeLastId.txt.txt", id);

        Employee e(id, name, pass, salary);
        admin->addEmployee(e);
        cout << "\nEmployee added successfuly.\n";

    }

    static void searchForEmployee(Admin* admin) {
        int id{};
        cout << "Please enter the Employee ID you want to search for: ";
        cin >> id;
        Employee* e = admin->searchEmployee(id);
        if (e == nullptr) {
            cout << "\nEmployee not exist.\n";
        }
        else {
            cout << "\nEmployee info: \n\n" << e->get_info() << endl;
        }
    }

    static void liastAllEmployees(Admin* admin) {
        admin->listEmployee();
    }

    static void editEmployeeInfo(Admin* admin) {
        string name{}, pass{};
        double salary{};
        int id{};
        cout << "Please enter the ID of the employee you want edit his info: ";
        id = DataEntry::TryID("EmployeeLastId.txt.txt");
        if (id == -1) {
            cout << "Invalid id, not found.";
            system("pause");
            AdminOptions(admin);
        }
        else {
            system("cls");

            name = DataEntry::tryName();
            cout << "\n";
            pass = DataEntry::TryPassword();
            cout << "\n";
            salary = DataEntry::trySalary();
            admin->editEmployee(id, name, pass, salary);
            cout << "\nThis employee edited successfuly.\n";
        }
    }
    static bool AdminOptions(Admin* admin) {
        int choice{};

        while (true) {
            system("cls");
            printEmployeeMenu();
            cout << "Enter your choice : ";
            cin >> choice;
            string pass{};
            switch (choice) {
            case 1:
                system("cls");
                cout << "Your info: \n" << admin->get_info() << endl;
                system("pause");
                break;
            case 2:
                system("cls");
                newClient(admin);
                FileManager::UpdateClients();
                system("pause");
                break;
            case 3:
                system("cls");
                searchForClient(admin);
                FileManager::UpdateClients();
                system("pause");
                break;
            case 4:
                system("cls");
                liastAllClients(admin);
                system("pause");
                break;
            case 5:
                system("cls");
                editClientInfo(admin);
                FileManager::UpdateClients();
                system("pause");
                break;
            case 6:
                system("cls");
                newEmployee(admin);
                FileManager::UpdateEmpolyees();
                system("pause");
                break;
            case 7:
                system("cls");
                searchForEmployee(admin);
                FileManager::UpdateEmpolyees();
                system("pause");
                break;
            case 8:
                system("cls");
                liastAllEmployees(admin);
                system("pause");
                break;
            case 9:
                system("cls");
                editEmployeeInfo(admin);
                FileManager::UpdateEmpolyees();
                system("pause");
                break;
            case 10:
                system("cls");

                pass = DataEntry::TryPassword();
                admin->set_password(pass);
                cout << "Your password Updated successfuly." << endl;
                FileManager::UpdateAdmins();
                system("pause");
                break;
            case 11:
                return false;
                break;
            }
        }
    }


};

