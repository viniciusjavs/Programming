// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Aug. 29, 2016
// Chapter 3, Exercise 1
// Try this from page 68

/*
  Simple program to exercise operators.
*/

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter an integer value:\n";
    int n; // modified later
    cin >> n;
    cout << "n == " << n
	 << "\nn+1 == " << n + 1
         << "\nthree times n == " << 3 * n
	 << "\ntwice n == " << n + n
         << "\nn squared == " << n * n
	 << "\nhalf of n == " << n / 2;
    double n_double = n;
    cout << "\nsquare root of n == " << sqrt(n_double) << '\n';
}
