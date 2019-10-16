// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Aug. 29, 2016
// Chapter 3, Exercise 4

/*
  Program that receives two integers and returns its comparison, product, sum,
  difference and ratio.
*/

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter two integers numbers:\n";
    int val1, val2;
    while (cin >> val1 >> val2) {
        if (val1 < val2) {
            cout << "smaller: " << val1;
            cout << "\nlarger: " << val2;
            cout << "\ndifference: " << val2 - val1;
            cout << "\nratio: " << val1 / val2;
        }
        else if (val1 > val2) {
            cout << "smaller: " << val2;
            cout << "\nlarger: " << val1;
            cout << "\ndifference: " << val1 - val2;
            cout << "\nratio: " << val2 / val1;
        }
        else {
            cout << val1 << "==" << val2;
            cout << "\ndifference: 0";
            cout << "\nratio: 1";
        }
        cout << "\nsum: " << val1 + val2;
        cout << "\nproduct: " << val1 * val2 << '\n';
    }
}
