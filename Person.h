#pragma once
#include <iostream>
#include<exception>
#include "Validation.h"
#include "String_Util.h"
using namespace std;

class Person
{
    string name, password;
    int id;

public:
    Person(int id, const string& name, const string& password) :
        id(id)
    {
        if (Validation::is_valid_name(name))this->name = name;
        else throw exception("Invalid Name");

        if (Validation::is_valid_password(password))this->password = password;
        else throw exception("Invalid Password");
    }

    void set_name(const string& name) {

        if (Validation::is_valid_name(name)) {

            this->name = name;
        }
    }
    void set_password(const string& password) {
        if (Validation::is_valid_password(password)) {

            this->password = password;
        }
    }

    const string& get_password()const { return password; }

    const string& get_name() const { return name; }

    int get_id()const { return id; }

    virtual string get_info()const {

        return "Id: " + to_string(id) + "\nName: " + name + "\nPassword: " + password;

    }
};
