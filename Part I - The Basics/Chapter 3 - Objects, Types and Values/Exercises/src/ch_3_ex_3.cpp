// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Aug. 29, 2016
// Chapter 3, Exercise 3

/*
  Program to check how the compiler reacts when using bad variable names (a.k.a
  identifiers).
*/

#include "std_lib_facilities.h"

int main()
{
    // int while = 0; // Not Passed! [error: expected unqualified-id]
    double d$ = 1; // Passed!
    // A valid identifier must begin with a non-digit character (Latin letter,
    // underscore, or Unicode non-digit character)
    double $ = 1; // Passed!
    // char 1c = 'c'; // Not Passed! [error: expected unqualified-id]
    string name = "vinicius";
    int loops = 0;
    double dS = 1.0;
    char c1 = 'c';
}
