// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 16, 2016
// Chapter 4, Drill 5

/*
  Program that reads two doubles continuously in a while-loop
  and prints the smaller and larger values or if they are equals.
  If two numbers differ by less than 1.0/100, they will be printed
  because they are almost equal.
  Enter '|' to exit the program.
*/

#include "std_lib_facilities.h"

int main()
{
    double a, b;
    constexpr double epsilon{1.0 / 100}; // a very small number
    while (cin >> a >> b) {
        if (a > b) {
            cout << "the smaller value is: " << b << '\n';
            cout << "the larger value is: " << a << '\n';
            if (a - b < epsilon) cout << "the numbers are almost equal" << '\n';
        }
        else if (b > a) {
            cout << "the smaller value is: " << a << '\n';
            cout << "the larger value is: " << b << '\n';
            if (b - a < epsilon) cout << "the numbers are almost equal" << '\n';
        }
        else
            cout << "the numbers are equal" << '\n';
    }
}
