#pragma once
#include <iostream>
#include <cctype>
using namespace std;

class Validation
{

    static bool is_all_alpha(const string& name) {
        for (int i = 0; i < name.size(); i++) {

            if (!isalpha(name[i])) return false;

        }
        return true;
    }

    static bool is_there_spaces(const string& password) {
        for (int i = 0; i < password.size(); i++) {

            if ((password[i] == ' ')) return false;
        }
        return true;
    }

public:


    static bool is_valid_name(const string& name) {
        return (((name.size() >= 3 && name.size() <= 20) && is_all_alpha(name)));
    }

    static bool is_valid_password(const string& password) {
        return((password.size() >= 8 && password.size() <= 20 && is_there_spaces(password)));

    }

    static bool is_valid_balance(double balance) {
        return(balance >= 1500);
    }

    static bool is_valid_salary(double salary) {
        return(salary >= 5000);
    }

};