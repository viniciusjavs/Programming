// Copyright (C) 2016 vjavs
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Dec. 22, 2016
// Chapter 5, Exercise 6

/*
  Program to convert temperature from Celsius to Fahrenheit and vice versa.
 */

#include "std_lib_facilities.h"

double ctof(double c) // converts to Fahrenheit
/*
  input: temperature in Celsius
  output: temperature in Fahrenheit
 */
{
    constexpr double ratio = 9.0 / 5.0;
    double f = ratio * c + 32;
    return f;
}

double ftoc(double f) // converts to Celsius
/*
  input:  temperature in Fahrenheit
  output: temperature in Celsius
 */
{
    constexpr double ratio = 5.0 / 9.0;
    double c = (f - 32) * ratio;
    return c;
}

int main()
{
    double c;
    cout << "Enter a temperature in Celsius degree: " << '\n';
    cin >> c;
    double f = ctof(c);
    cout << "Temperature in Fahrenheit degree is: " << f << '\n';
    cout << "Enter a temperature in Fahrenheit degree: " << '\n';
    cin >> f;
    c = ftoc(f);
    cout << "Temperature in Celsius degree is: " << c << '\n';
}
