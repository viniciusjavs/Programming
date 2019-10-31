// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 23
// Chapter 4, Exercise 5

/*
  Program that performs a very simple calculator.
*/

#include "std_lib_facilities.h"

int main()
{
    double lvalue, rvalue;
    char option;
    while (cin >> lvalue >> rvalue >> option) {
        string operation;
        double result;
        switch (option) {
        case '+':
            operation = "The sum of ";
            result = lvalue + rvalue;
            break;
        case '-':
            operation = "The difference between ";
            result = lvalue - rvalue;
            break;
        case '*':
            operation = "The multiplication of ";
            result = lvalue * rvalue;
            break;
        case '/':
            if (rvalue != 0) {
                operation = "The division of ";
                result = lvalue / rvalue;
            }
            else
                cout << "Error: Tentative of division by zero.\n";
            break;
        default:
            cout << "The operator '" << option << "' is not known.\n";
            break;
        }
        if (option == '+' || option == '-' || option == '*' ||
            (option == '/' && rvalue != 0))
            cout << operation << lvalue << " and " << rvalue << " is " << result
                 << '\n';
    }
}
