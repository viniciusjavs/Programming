// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 22 Dec 2016
// Chapter 5, Exercise 5

/*
  Program to convert temperature from Kelvin to Celsius and vice versa.
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

double ktoc(double k) // converts to Celsius
/*
  input: temperature in Kelvin [0,...)
  output: temperature in Celsius 
 */
{
    if (k < 0) error("Below Absolute Zero");
    double c = k - 273.15;
    return c;
}

int main()
{
    double c;
    cin >> c;
    double k = ctok(c);
    cout << k << '\n';
    cin >> k;
    c = ktoc(k);
    cout << c << '\n';
}
