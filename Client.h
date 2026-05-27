#pragma once
#include "Person.h"
#include<vector>
class Client :public Person
{

    double balance;
    static vector<Client>allClients;


public:
    Client(int id, const string& name, const string& password, double balance) :
        Person(id, name, password)
    {
        if (Validation::is_valid_balance(balance))this->balance = balance;
        else throw exception("Invalid balance");

    }

    static vector<Client>& get_all_clients() {

        return allClients;
    }

    static  void setAllClients(const Client& client) {

        allClients.push_back(client);
    }

    void set_balance(double balance) {
        if (Validation::is_valid_balance(balance))this->balance = balance;
        else throw exception("Invalid balance");
    }

    double get_balance()const { return balance; }

    pair<double, bool> deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return{ balance,true };
        }
        return{ balance,false };
    }

    pair<double, bool> withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return{ balance,true };
        }
        return{ balance,false };
    }

    pair<double, bool> transferTo(double amount, Client*& recipient) {
        if (amount > 0 && amount <= balance) {

            withdraw(amount);
            recipient->deposit(amount);
            return { balance,true };
        }
        return{ balance,false };
    }

    string operation_report(pair<double, bool> operation)const {

        if (operation.second)return "Successful operation and your balance is: "
            + String_Util::to_string_delux(operation.first) + "\n";

        return "Faild operation and your balance is: " +
            String_Util::to_string_delux(operation.first) + "\n";
    }

    string get_info()const {

        return Person::get_info() +
            "\nbalance: " + String_Util::to_string_delux(balance);
    }

};