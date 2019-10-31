// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Oct. 04
// Chapter 4, Exercise 18

/*
  Program that solves quadratic equations.
*/

#include "std_lib_facilities.h"

int main()
{
    cout << "Enter the elements 'a', 'b' and 'c': \n";
    double a, b, c;
    cin >> a >> b >> c;
    double d = b * b - 4 * a * c;
    double x1 = (-b + sqrt(d)) / 2 * a;
    double x2 = (-b - sqrt(d)) / 2 * a;
    cout << "Roots are: " << x1 << ' ' << x2 << '\n';
}
