#pragma once
#include<Windows.h>
#include<iostream>
using namespace std;
#include"ClientManager.h"
#include"FileManager.h"
#include"EmployeeManager.h"
#include"AdminManager.h"
#include"DataEntry.h"

class Screen
{
public:
    static void bankName() {
        int choice{};

        do {
            loginOptions();
            choice = loginAs();

            if (!(isValid(choice))) {
                cout << "Invalid choice you should choose number from 1 to 3\n\n";
                system("pause");
                system("cls");
            }

        } while (!(isValid(choice)));
        loginScreen(choice);

    }

    static void welcome() {
        cout << "\n\n\n\n\n\n";
        cout << "                                 $$$$$$\\   $$$$$$\\  $$\\   $$\\ $$$$$$$$\\ $$$$$$$$\\ \n";
        cout << "                                 $$  $$\\ $$  __$$\\ $$ |  $$ |\\__$$  |$$  _____|\n";
        cout << "                                 $$ |  $$ |$$ /  $$ |$$ |  $$ |   $$ |   $$ |      \n";
        cout << "                                 $$$$$$$  |$$ |  $$ |$$ |  $$ |   $$ |   $$$$$\\    \n";
        cout << "                                 $$  $$< $$ |  $$ |$$ |  $$ |   $$ |   $$  |   \n";
        cout << "                                 $$ |  $$ |$$ |  $$ |$$ |  $$ |   $$ |   $$ |      \n";
        cout << "                                 $$ |  $$ | $$$$$$  |\\$$$$$$  |   $$ |   $$$$$$$$\\ \n";
        cout << "                                 \\__|  \\__| \\______/  \\______/    \\__|   \\________|\n\n";

        cout << "                                 $$$$$$$\\   $$$$$$\\  $$\\   $$\\ $$\\   $$\\ \n";
        cout << "                                 $$  $$\\ $$  __$$\\ $$$\\  $$ |$$ | $$  |\n";
        cout << "                                 $$ |  $$ |$$ /  $$ |$$$$\\ $$ |$$ |$$  / \n";
        cout << "                                 $$$$$$$\\ |$$$$$$$$ |$$ $$\\$$ |$$$$$  /  \n";
        cout << "                                 $$  __$$\\ $$  __$$ |$$ \\$$$$ |$$  $$<   \n";
        cout << "                                 $$ |  $$ |$$ |  $$ |$$ |\\$$$ |$$ |\\$$\\  \n";
        cout << "                                 $$$$$$$  |$$ |  $$ |$$ | \\$$ |$$ | \\$$\\ \n";
        cout << "                                 \\_______/ \\|  \\__|\\__|  \\__|\\__|  \\__|\n";
        Sleep(2000);
        system("cls");
        bankName();
    }

    static void loginOptions() {
        cout << "How do you want to login as?\n1- Admin\n2- Employee\n3- Client\n\n";

    }

    static int loginAs() {

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        return choice;
    }

    static bool isValid(int choice) {
        return (choice >= 1 && choice <= 3);

    }

    static void loginScreen(int choice) {
        system("cls");
        int id{};
        string password{};
        Client* c;
        Employee* e;
        Admin* a;
        switch (choice) {
        case 3:
            cout << "Please enter your ID: ";
            cin >> id;
            password = DataEntry::TryPassword();
            c = ClientManager::login(id, password);
            if (c == nullptr) {
                cout << "\nInvalid ID or password\n\n";
                system("pause");
                system("cls");
                bankName();
            }
            else {
                system("cls");
                ClientManager::printClientMenu();
                bool is = ClientManager::clientOptions(c);
                if (!is) {
                    system("cls");
                    bankName();
                }
            }
            break;
        case 2:
            cout << "Please enter your ID: ";
            cin >> id;
            password = DataEntry::TryPassword();
            e = EmployeeManager::login(id, password);
            if (e == nullptr) {
                cout << "\nInvalid ID or password\n\n";
                system("pause");
                system("cls");
                bankName();
            }
            else {
                system("cls");
                EmployeeManager::printEmployeeMenu();
                bool is = EmployeeManager::employeeOptions(e);
                if (!is) {
                    system("cls");
                    bankName();
                }
            }
            break;
        case 1:
            cout << "Please enter your ID: ";
            cin >> id;

            password = DataEntry::TryPassword();
            a = AdminManager::login(id, password);
            if (a == nullptr) {
                cout << "\nInvalid ID or password\n\n";
                system("pause");
                system("cls");
                bankName();
            }
            else {
                system("cls");
                AdminManager::printEmployeeMenu();
                bool is = AdminManager::AdminOptions(a);
                if (!is) {
                    system("cls");
                    bankName();
                }
            }
            break;
        }
    }

    static void runApp() {
        system("color 74");
        FileManager::getAllData();
        welcome();

    }
};
