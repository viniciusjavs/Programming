// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 25
// Chapter 4, Exercise 7

/*
  Program that performs a very simple calculator.
  Input sigle-digit numbers are written as either digits or spelled out.
*/

#include "std_lib_facilities.h"

int get_num(vector<string> digits)
/*
  Get a number from stdin, either digit or spelled out.
  return 0-9 digit, or size() as error.
  Note: without exception handling.
*/
{
    int digit = digits.size(); // out of range
    int int_value;
    if (cin >> int_value) {
        if (int_value >= 0 && int_value < digits.size()) digit = int_value;
    }
    else {
        cin.clear(); // use cin after error
        string str_value;
        cin >> str_value; // recupere from buffer
        for (int i = 0; i < digits.size(); ++i)
            if (str_value == digits[i]) digit = i;
    }
    return digit;
}

int main()
{
    vector<string> digits = {"zero", "one", "two",   "three", "four",
                             "five", "six", "seven", "eight", "nine"};
    while (true) {
        double lvalue, rvalue;
        lvalue = get_num(digits);
        rvalue = get_num(digits);
        if (lvalue < digits.size() && rvalue < digits.size()) {
            char option;
            cin >> option;
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
                cout << operation << lvalue << " and " << rvalue << " is "
                     << result << '\n';
        }
        else
            cout << "Error: invalid number\n";
    }
}
