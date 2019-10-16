// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Aug. 29, 2016
// Chapter 3, Exercise 1
// Try this from page 81

/*
  Program safe/unsafe(a.k.a "narrowing") conversions.
  It shows how conversions from double to int and from int to char are done on
  your machine.
*/

#include "std_lib_facilities.h"

int main()
{
    // universal and uniform initialization
    double ds[]{2, 3, 128, 256, 1024, -127, 56, 89, 56.9, 56.2};
    for (const auto &d : ds) {
        int i = d;               // try to squeeze a double into a int
        char c = i;              // try to squeeze a int into a char
        int i2 = c;              // get the integer value of a character
        cout << "\nd == " << d   // original double
             << "\ni == " << i   // converted to int
             << "\ni2 == " << i2 // int value of a char
             << "\nchar (" << c << ")\n"; // the char
    }
}
