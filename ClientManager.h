#pragma once
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include<vector>
#include"FilesHelper.h"
#include"FileManager.h"
#include"DataEntry.h"

class ClientManager
{
public:

    static Client* search(int id, const string& password) {

        vector<Client>& clients = Client::get_all_clients();

        for (auto& c : clients) {

            if (c.get_id() == id && c.get_password() == password) {
                return (&c);
            }

        }
        return nullptr;
    }

    static Client* login(int id, string& password) {

        Client* c = search(id, password);

        if (c != nullptr) return c;
        return nullptr;

    }

    static void printClientMenu() {
        cout << "\n======Client menu=====\n";
        cout << "What would you like to do?\n\n"
            << "1- Check your balance\n" << "2- Display your info\n3- Deposit\n4- Withdraw\n"
            << "5- Transfer amount of money to somebody else\n6- Change your password\n"
            << "7- Logout\n\n";
    }

    static bool clientOptions(Client* client) {
        Client* c;
        string pass{};
        double amount{};
        int choice{}, Id{};
        while (true) {
            system("cls");
            printClientMenu();
            cout << "Enter your choice : ";
            cin >> choice;

            switch (choice) {
            case 1:
                system("cls");
                cout << "Your balance is: " << client->get_balance() << endl;
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "Your account info: \n" << client->get_info() << endl;
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "Please enter the amount you want to deposit: ";
                cin >> amount;
                cout << client->operation_report(client->deposit(amount)) << endl;
                FileManager::UpdateClients();
                system("pause");
                break;
            case 4:
                system("cls");
                cout << "Please enter the amount you want to withdraw: ";
                cin >> amount;
                cout << client->operation_report(client->withdraw(amount)) << endl;
                FileManager::UpdateClients();
                system("pause");
                break;
            case 5:
                system("cls");
                cout << "Please enter the amount you want to transfer to another account: ";
                cin >> amount;
                cout << "Please enter the another account informations: \nAnother account ID: ";
                cin >> Id;
                cout << endl;
                pass = DataEntry::TryPassword();
                c = login(Id, pass);
                if (c == nullptr) {
                    cout << "Invalid ID or password.\n";

                }
                else {
                    cout << client->operation_report(client->transferTo(amount, c)) << endl;

                    FileManager::UpdateClients();

                }
                system("pause");
                break;

            case 6:
                system("cls");

                pass = DataEntry::TryPassword();
                client->set_password(pass);
                cout << "Your password Updated successfuly." << endl;
                FileManager::UpdateClients();
                system("pause");
                break;
            case 7:
                return false;
                break;
            }
        }
    }

};
