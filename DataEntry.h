#pragma once
#include<iostream>
using namespace std;
#include"Validation.h"
#include<string>
#include<exception>
#include"FilesHelper.h"

class DataEntry
{
public:

    static int TryID(string fileName) {
        int id;
        int lastid = FilesHelper::getLast(fileName);
        cin >> id;
        if (id > 0 && id <= lastid) {
            return id;
        }
        else return -1;
    }

    static string TryPassword() {
        string pass{};
        while (true) {
            cout << "Please enter the password: ";
            cin >> pass;
            try {

                if (!Validation::is_valid_password(pass))
                    throw runtime_error("Invalid password");


                else  break;
            }
            catch (const exception& e) {
                cout << e.what() << endl;

            }

        }
        return pass;
    }

    static double tryBalance() {
        double balance;
        while (true) {

            cout << "Please enter the balance: ";
            cin >> balance;

            try {
                if (!(Validation::is_valid_balance(balance)))
                    throw exception("Invalid balance");

                else break;
            }
            catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
        return balance;
    }

    static string tryName() {
        cin.ignore();
        string name;
        while (true) {


            cout << "Please enter the name: ";
            getline(cin, name);


            try {
                if (!(Validation::is_valid_name(name)))
                    throw exception("Invalid name");

                else break;
            }
            catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
        return name;
    }

    static double trySalary() {
        double salary;
        while (true) {

            cout << "Please enter the salary: ";
            cin >> salary;

            try {
                if (!(Validation::is_valid_salary(salary)))
                    throw exception("Invalid salary");

                else break;
            }
            catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
        return salary;
    }

};
