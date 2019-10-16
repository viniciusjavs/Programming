// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Aug. 30, 2016
// Chapter 3, Exercise 8

/*
  Program to test if a number is odd or even.
  Bjarne Stroustrup technique - pick a default value and change it case needed.
*/

#include "std_lib_facilities.h"

int main()
{
    cout << "Enter a integer number :\n";
    int num;
    string res;
    while (cin >> num) {
        res = "even";
        if (num % 2 == 0) res = "odd";
        cout << "The number " << num << " is " << res << "\n";
    }
}
