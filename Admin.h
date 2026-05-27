#pragma once
#include "Employee.h"
#include<vector>

class Admin : public Employee
{
    static vector<Admin>allAdmins;

public:
    Admin(int id, const string& name, const string& password, double salary)
        :Employee(id, name, password, salary)
    {
    }

    static vector<Admin>& get_all_Admins() {
        return allAdmins;
    }



    void addEmployee(Employee& employee) {

        Employee::get_all_Employees().push_back(employee);
    }

    Employee* searchEmployee(int id) {

        vector<Employee>& e = Employee::get_all_Employees();

        for (int i = 0; i < e.size(); i++) {

            if (e[i].get_id() == id) {
                return (&e[i]);
            }

        }
        return nullptr;
    }

    void editEmployee(int id, string name, string password, double salary) {

        Employee* e = searchEmployee(id);

        if (e == nullptr) {
            cout << "Employee not found!\n";
            system("pause");
        }

        e->set_name(name);
        e->set_password(password);
        e->set_salary(salary);

    }

    void listEmployee() {

        vector<Employee> e = Employee::get_all_Employees();

        for (int i = 0; i < e.size(); i++) {

            cout << e[i].get_info() << endl
                << "=============================================================================" << endl;
        }
    }
};
