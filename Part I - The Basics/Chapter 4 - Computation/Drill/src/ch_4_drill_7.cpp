// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 20, 2016
// Chapter 4, Drill 7

/*
  Program that reads one double continuously in a while-loop
  followed by a proper unit, that are "cm", "m", "in" or "ft".
  Enter '|' to exit the program.
*/

#include "std_lib_facilities.h"

int main()
{
    double d;
    string unit;
    constexpr double cm_per_m = 100;
    constexpr double cm_per_in = 2.54;
    constexpr double in_per_ft = 12;
    while (cin >> d >> unit) {
        cout << '\'' << d << '\'' << " '" << unit << "'\n";
    }
}
