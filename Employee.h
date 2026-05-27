#pragma once
#include "Person.h"
#include "Client.h"
#include<vector>

class Employee :public Person
{
    double salary;
    static vector<Employee>allEmployees;

public:
    Employee(int id, const string& name, const string& password, double salary) :
        Person(id, name, password)
    {
        if (Validation::is_valid_salary(salary)) this->salary = salary;
        else throw exception("Invalid salary");
    }

    static vector<Employee>& get_all_Employees() {
        return allEmployees;
    }

    void set_salary(double salary) {
        if (Validation::is_valid_salary(salary)) this->salary = salary;
        else throw exception("Invalid salary");
    }

    double get_salary() { return salary; }

    virtual string get_info()const {
        return Person::get_info() + "\nSalary: " + String_Util::to_string_delux(salary);
    }

    void addClient(Client& client) {

        Client::get_all_clients().push_back(client);
    }

    Client* searchClient(int id) {

        vector<Client>& c = Client::get_all_clients();

        for (int i = 0; i < c.size(); i++) {

            if (c[i].get_id() == id) {
                return (&c[i]);
            }

        }
        return nullptr;
    }

    void listClient() {

        vector<Client>& c = Client::get_all_clients();

        for (Client& clients : c) {

            cout << clients.get_info() << endl
                << "=============================================================================" << endl;
        }
    }

    void editClient(int id, const string& name, const string& password, double balance) {

        Client* c = searchClient(id);

        c->set_name(name);
        c->set_password(password);
        c->set_balance(balance);
    }
};