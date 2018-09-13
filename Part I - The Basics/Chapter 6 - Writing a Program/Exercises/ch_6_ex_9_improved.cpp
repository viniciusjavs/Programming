// Copyright (C) 2017 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 17 Jan 2017
// Chapter 6, Exercise 9

/*
  Program that reads digits and composes them into integers. Then prints the
  number in full.
 */

#include "std_lib_facilities.h"

vector<char> str_to_v(const string str)
/*
  Receives a string and returns a vector with each character of this string
 */
{
    for (auto c : str)
        if (c < '0' || c > '9')
            error("Bad input for \"guess\"", " - illegal characters");

    int size = 4;
    if (str.size() > size || !str.size())
        error("Bad input for \"guess\"", " - out of change number");

    vector<char> number;
    for (auto c : str)
        number.push_back(c);
    return number;
}

int v_to_int(const vector<char> v)
/*
  Function that convert a vector of chars in an int
 */
{
    int number = 0;
    for (int i = v.size() - 1; i >= 0; --i)
        number += pow(10, i) * (v[v.size() - 1 - i] - '0');
    return number;
}

int main()
try {
    string str;
    cin >> str; // read a number into a string

    const vector<string> full_name = {"one", "ten", "hundred", "thousand"};

    vector<char> digits = str_to_v(str);

    // print
    cout << v_to_int(digits) << " is ";
    for (int i = 0; i < digits.size(); ++i)
        if (digits[i] - '0') {
            cout << digits[i] << ' ' << full_name[digits.size() - 1 - i];
            if (digits[i] - '0' > 1) cout << "s";
            if (digits.size() - 1 - i) cout << " and ";
        }
    cout << '\n';

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
