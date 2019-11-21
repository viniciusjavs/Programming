// Copyright (C) 2016 vjavs
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Dec. 22, 2016
// Chapter 5, Exercise 2

/*
  Correcting errors: program to convert temperature from Kelvin to Celsius
 */

#include "std_lib_facilities.h"

double ctok(double c) // converts to Kelvin
/*
  input: temperature in Celsius
  output: temperature in Kelvin
 */
{
    double k = c + 273.15;
    return k;
}
int main()
{
    double c = 0;       // declare input variable
    cin >> c;           // retrieve temperature to input variable
    double k = ctok(c); // convert temperature
    cout << k << '\n';  // print out temperature
}
