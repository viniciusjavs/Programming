// Copyright (C) 2016 vjavs
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Dec. 22, 2016
// Chapter 5, Exercise 4

/*
  Program to convert temperature from Kelvin to Celsius
  Check for error inside function.
 */

#include "std_lib_facilities.h"

double ctok(double c) // converts to Kelvin
/*
  input: temperature in Celsius
  output: temperature in Kelvin [0,...)
 */
{
    double k = c + 273.15;
    if (k < 0) error("Below Absolute Zero");
    return k;
}

int main()
{
    double c;
    cin >> c;
    double k = ctok(c);
    cout << k << '\n';
}
