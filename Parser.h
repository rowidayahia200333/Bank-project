#pragma once
#include<iostream>
using namespace std;
#include <string>
#include<vector>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include <sstream>

class Parser
{
public:

    static string trim(string s) {
        int start = 0, end = s.size() - 1;

        while (start <= end && isspace(s[start])) start++;
        while (end >= start && isspace(s[end])) end--;

        return s.substr(start, end - start + 1);
    }

    static void cleanEnd(string& s) {
        while (!s.empty() && (s.back() == '.'||  s.back() == ',' || s.back() == ' ')) {
            s.pop_back();
        }
    }



    static vector<string> split(string line) {
        vector<string> words;
        stringstream ss(line);
        string temp;

        while (getline(ss, temp, '-')) {

            temp = trim(temp);
            cleanEnd(temp);

            if (!temp.empty()) {
                words.push_back(temp);
            }
        }

        return words;
    }

    static Client parseToClient(string line) {

        vector<string> client = split(line);

        if (client.size() < 4) {
            throw invalid_argument("Invalid client data");
        }

        int id = stoi(client[0]);
        double balance = stod(client[3]);

        /* cout << id<<" "<<client[1]<<" " << client[2]<<" "<<balance;*/

        return Client(id, client[1], client[2], balance);
    }

    static Employee parseToEmployee(string line) {

        vector<string> employee = split(line);

        if (employee.size() < 4) {
            throw invalid_argument("Invalid client data");
        }

        int id = stoi(employee[0]);
        double salary = stod(employee[3]);

        /* cout << id<<" "<<employee[1]<<" " << employee[2]<<" "<<salary;*/

        return Employee(id, employee[1], employee[2], salary);
    }

    static Admin parseToAdmin(string line) {

        vector<string> admin = split(line);

        if (admin.size() < 4) {
            throw invalid_argument("Invalid client data");
        }

        int id = stoi(admin[0]);
        double salary = stod(admin[3]);

        /* cout << id<<" "<<admin[1]<<" " << admin[2]<<" "<<salary;*/

        return Admin(id, admin[1], admin[2], salary);
    }
};
