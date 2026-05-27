#pragma once
#include"FilesHelper.h"
#include"DataSourceInterface.h"
#include<string>

class FileManager :public DataSourceInterface
{
public:
    void addClient(Client& client) {

        FilesHelper::saveClient(client);
    }

    void addEmployee(Employee& employee) {

        FilesHelper::saveEmployee("Employee.txt.txt", "EmployeeLastId.txt.txt", employee);
    }

    void addAdmin(Admin& admin) {

        FilesHelper::saveEmployee("Admin.txt.txt", "AdminLastId.txt.txt", admin);
    }

    static void getAllClients() {

        return FilesHelper::getClients();

    }

    static void getAllEmployees() {

        return FilesHelper::getEmployees();
    }

    static void getAllAdmins() {

        return FilesHelper::getAdmins();
    }

    static void getAllData() {

        getAllClients();
        getAllEmployees();
        getAllAdmins();
    }

    static void UpdateClients() {
        removeAllClients();

        vector<Client>& clients = Client::get_all_clients();
        for (Client& c : clients) {
            FilesHelper::saveClient(c);
        }
    }

    static void UpdateEmpolyees() {
        removeAllEmployees();

        vector<Employee>& employees = Employee::get_all_Employees();
        for (Employee& e : employees) {

            FilesHelper::saveEmployee("Employee.txt.txt", "EmployeeLastId.txt.txt", e);
        }
    }

    static void UpdateAdmins() {
        removeAllAdmins();

        vector<Admin>& admins = Admin::get_all_Admins();
        for (Admin& a : admins) {
            FilesHelper::saveEmployee("Admin.txt.txt", "AdminLastId.txt.txt", a);
        }
    }

    static void removeAllClients() {

        FilesHelper::clearFile("Client.txt.txt", "ClientLastId.txt.txt");
    }

    static void removeAllEmployees() {

        FilesHelper::clearFile("Employee.txt.txt", "EmployeeLastId.txt.txt");
    }

    static void removeAllAdmins() {

        FilesHelper::clearFile("Admin.txt.txt", "AdminLastId.txt.txt");
    }
};
