#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"Parser.h"
#include"String_Util.h"


class FilesHelper
{
public:
    static void saveLast(string fileName, int id) {

        ofstream setlastid;
        setlastid.open(fileName, ios::trunc);
        setlastid << id;
        setlastid.close();
    }

    static int getLast(string fileName) {

        ifstream getlastid;
        getlastid.open(fileName, ios::in);
        string lastid;

        if (getlastid >> lastid) {
            int id = stoi(lastid);

            getlastid.close();

            return id;
        }
        getlastid.close();
        return -1;
    }


    static void saveClient(const Client& c) {

        string id = to_string(c.get_id());
        string balance = String_Util::to_string_delux(c.get_balance());
        string s = id + "-" + c.get_name() + "-" + c.get_password() + "-" + balance;

        ofstream saveclient;
        saveclient.open("Client.txt.txt", ios::app);
        saveclient << s << endl;
        saveclient.close();


        saveLast("ClientLastId.txt.txt", c.get_id());

    }

    static void saveEmployee(string fileName, string lastIdFile, Employee e) {

        string id = to_string(e.get_id());
        string balance = String_Util::to_string_delux(e.get_salary());
        string s = id + "-" + e.get_name() + "-" + e.get_password() + "-" + balance + "\n";

        ofstream saveemployee;
        saveemployee.open(fileName, ios::app);
        saveemployee << s << endl;
        saveemployee.close();


        saveLast(lastIdFile, e.get_id());
    }

    //static vector<Client>& getClients() {

    //  vector<Client>& clients=Client::get_all_clients();
    //  ifstream  file;
    //  file.open("Client.txt.txt", ios::in);
    //  string line;
    //  while (getline(file, line)) {
    //    
    //    line = Parser::trim(line);

    //    if (line.empty()) continue;
    //    Client c = Parser::parseToClient(line);
    //    clients.push_back(c);
    //  /*  try {
    //      Client c = Parser::parseToClient(line);
    //      clients.push_back(c);   
    //    }
    //    catch (...) {
    //      continue;
    //    }*/
    //  }

    //  return clients;
    //}


    static void getClients() {

        //vector<Client>& clients = Client::get_all_clients();
        ifstream  file;
        file.open("Client.txt.txt", ios::in);
        string line;
        while (getline(file, line)) {

            //line = Parser::trim(line);

            if (line.empty()) continue;
            //Client c = Parser::parseToClient(line);
            Client::setAllClients(Parser::parseToClient(line));
            /*  try {
                Client c = Parser::parseToClient(line);
                clients.push_back(c);
              }
              catch (...) {
                continue;
              }*/
        }

    }


    //static vector<Employee>& getEmployees() {

    //  vector<Employee>& employees=Employee::get_all_Employees();
    //  ifstream  file;
    //  file.open("Employee.txt.txt", ios::in);
    //  string line;
    //  while (getline(file, line)) {

    //    line = Parser::trim(line);

    //    if (line.empty()) continue;

    //    Employee e = Parser::parseToEmployee(line);
    //    employees.push_back(e);

    //    /*try {
    //      Employee e = Parser::parseToEmployee(line);
    //      employees.push_back(e);
    //    }
    //    catch (...) {
    //      continue;
    //    }*/
    //  }
    //  file.close();

    //  return employees;

    //}

    static void getEmployees() {

        ifstream  file;
        file.open("Employee.txt.txt", ios::in);
        string line;
        while (getline(file, line)) {

            /*line = Parser::trim(line);*/

            if (line.empty()) continue;

            Employee e = Parser::parseToEmployee(line);
            /*employees.push_back(e);



            try {
              Employee e = Parser::parseToEmployee(line);
              employees.push_back(e);
            }
            catch (...) {
              continue;
            }*/
        }
        file.close();



    }

    //static vector<Employee>& getEmployees() {

    //  vector<Employee>& employees = Employee::get_all_Employees();
    //  ifstream  file;
    //  file.open("Employee.txt.txt", ios::in);
    //  string line;
    //  while (getline(file, line)) {

    //    line = Parser::trim(line);
    //    if (line.empty()) continue;

  //    Employee e = Parser::parseToEmployee(line);
  //    employees.push_back(e);

  //    /*try {
  //      Employee e = Parser::parseToEmployee(line);
  //      employees.push_back(e);
  //    }
  //    catch (...) {
  //      continue;
  //    }*/
  //  }
  //  file.close();

  //  return employees;

  //}


    static void getAdmins() {

        vector<Admin>& admins = Admin::get_all_Admins();
        ifstream  file;
        file.open("Admin.txt.txt", ios::in);
        string line;
        while (getline(file, line)) {

            /*line = Parser::trim(line);*/

            if (line.empty()) continue;
            /*try {
              Admin a = Parser::parseToAdmin(line);
              admins.push_back(a);
            }
            catch (...) {
              continue;
            }*/
        }
        file.close();


    }

    static void clearFile(string fileName, string lastIdFile) {

        ofstream file;
        file.open(fileName, ios::trunc);
        file.close();

        saveLast(lastIdFile, 0);
    }
};