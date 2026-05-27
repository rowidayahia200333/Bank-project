#pragma once
#include"Employee.h"
#include"FilesHelper.h"
#include"FileManager.h"
#include"DataEntry.h"

class EmployeeManager
{
public:
    static Employee* search(int id, const string& password) {

        vector<Employee>& employees = Employee::get_all_Employees();

        for (auto& e : employees) {

            if (e.get_id() == id && e.get_password() == password) {
                return (&e);
            }

        }
        return nullptr;
    }

    static Employee* login(int id, const string& password) {
        Employee* e = search(id, password);

        if (e != nullptr) return e;
        return nullptr;
    }

    static void printEmployeeMenu() {
        cout << "\n======Employee menu=====\n";
        cout << "What would you like to do?\n\n"
            << "1- Display your info.\n2- Add a new Client.\n3- Search for a client.\n4- List all clients.\n"
            << "5- Edit a client info.\n6- Change your password.\n7- Logout\n\n";
    }

    static void newClient(Employee* employee) {
        string name{}, pass{};
        double balance{};
        cout << "Please enter the client info: \n";
        name = DataEntry::tryName();
        cout << "\n";
        pass = DataEntry::TryPassword();
        cout << "\n";
        balance = DataEntry::tryBalance();
        cin.ignore();

        int id = FilesHelper::getLast("ClientLastId.txt.txt");
        id++;
        FilesHelper::saveLast("ClientLastId.txt.txt", id);

        Client c(id, name, pass, balance);
        employee->addClient(c);
        cout << "\nClient added successfuly.\n";

    }

    static void liastAllClients(Employee* employee) {
        employee->listClient();
    }

    static void searchForClient(Employee* employee) {
        int id{};
        cout << "Please enter the client ID you want to search for: ";
        cin >> id;
        Client* c = employee->searchClient(id);
        if (c == nullptr) {
            cout << "\nClient not exist.\n";
        }
        else {
            cout << "\nClient info: \n\n" << c->get_info() << endl;
        }
    }

    static void editClientInfo(Employee* employee) {
        string name{}, pass{};
        double balance{};
        int id{};
        cout << "Please enter the ID of the client you want edit his info: ";
        id = DataEntry::TryID("ClientLastId.txt.txt");
        if (id == -1) {
            cout << "Invalid id, not found.";
            system("pause");
            employeeOptions(employee);
        }
        else {
            system("cls");

            name = DataEntry::tryName();
            cout << endl;
            pass = DataEntry::TryPassword();
            cout << endl;
            balance = DataEntry::tryBalance();
            employee->editClient(id, name, pass, balance);
            cout << "\nThis client edited successfuly.\n";
        }
    }

    static bool employeeOptions(Employee* employee) {
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
                cout << "Your info: \n" << employee->get_info() << endl;
                system("pause");
                break;
            case 2:
                system("cls");
                newClient(employee);
                FileManager::UpdateClients();
                system("pause");
                break;
            case 3:
                system("cls");
                searchForClient(employee);
                FileManager::UpdateClients();
                system("pause");
                break;
            case 4:
                system("cls");
                liastAllClients(employee);
                system("pause");
                break;
            case 5:
                system("cls");
                editClientInfo(employee);
                FileManager::UpdateClients();
                system("pause");
                break;
            case 6:
                system("cls");

                pass = DataEntry::TryPassword();
                employee->set_password(pass);
                cout << "Your password Updated successfuly." << endl;
                FileManager::UpdateEmpolyees();
                system("pause");
                break;
            case 7:
                return false;
                break;
            }
        }
    }

};