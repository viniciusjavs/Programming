// Copyright (C) 2017 vjavs
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Jan. 17, 2017
// Chapter 6, Exercise 9

/*
  Program that reads digits and composes them into integers and then prints the
  number in full.
 */

#include "std_lib_facilities.h"

string number_full = "--> ";

bool digit(char c)
{
    if (c >= '0' && c <= '9') return true;
    return false;
}

bool one(string str)
{
    number_full += str + " ones";
    return digit(str[0]);
}

bool ten(string str)
{
    number_full += str.substr(0, 1) + " tens " + "and ";
    return digit(str[0]) && one(str.substr(1));
}

bool hundred(string str)
{
    number_full += str.substr(0, 1) + " hundreds " + "and ";
    return digit(str[0]) && ten(str.substr(1));
}

bool thousand(string str)
{
    number_full += str.substr(0, 1) + " thousands " + "and ";
    return digit(str[0]) && hundred(str.substr(1));
}

bool cardinal(string str)
{
    bool pass = false;
    switch (str.size()) {
    case 1:
        pass = one(str);
        break;
    case 2:
        pass = ten(str);
        break;
    case 3:
        pass = hundred(str);
        break;
    case 4:
        pass = thousand(str);
        break;
    default:
        error("Out of range number");
    }
    return pass;
}

int main()
try {
    string str;
    cin >> str; // read a number into a string
    string res = "not OK";
    if (cardinal(str)) {
        cout << number_full << '\n';
        res = "OK";
    }
    cout << res << '\n';
    return 0;
}
catch (exception &e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}
