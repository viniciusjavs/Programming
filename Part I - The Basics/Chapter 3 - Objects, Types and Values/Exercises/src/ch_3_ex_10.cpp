// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Aug. 31, 2016
// Chapter 3, Exercise 10

/*
  Program that takes an operation followed by two operands and outputs the
  result. Valid operations are: + - * /.
*/

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter an operation (+, -, *, /) followed by two values: \n";
    string operation;
    double l_num, r_num;
    while (cin >> operation >> l_num >> r_num) {
        if (operation == "+")
            cout << l_num + r_num << '\n';
        else if (operation == "-")
            cout << l_num - r_num << '\n';
        else if (operation == "*")
            cout << l_num * r_num << '\n';
        else if (operation == "/")
            if (r_num != 0)
                cout << l_num / r_num << '\n';
            else
                cout << "Division by zero!" << '\n';
        else
            cout << "Invalid operation: " << operation << '\n';
    }
}
