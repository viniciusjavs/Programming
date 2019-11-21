// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 22 Dec 2016
// Chapter 5, Exercise 3

/*
  Program to convert temperature from Kelvin to Celsius.
  Check for error in the main program.
 */

#include "std_lib_facilities.h"

double ctok(double c) // converts to Kelvin
/*
  input: temperature in Celsius
  output: temperature in Kelvin [0,...)
 */
{
    double k = c + 273.15;
    return k;
}
int main()
{
    double c;
    cin >> c;
    double k = ctok(c);
    if (k < 0) error("Below Absolute Zero");
    cout << k << '\n';
}
