#pragma once
#include <string>
using namespace std;

class String_Util
{
public:
    static string to_string_delux(double num) {

        string s = to_string(num);
        while (s[s.size() - 1] == '0')s.erase(s.size() - 1);

        if (s.size() - 1 == ',')s.erase(s.size() - 1);

        return s;
    }
};

