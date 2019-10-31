// Copyright (C) 2016 vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 15, 2016
// Chapter 4, Drill 1

/*
  Program that reads two ints continuously in a while-loop
  and prints them. Enter '|' to exit the program.
*/

#include "std_lib_facilities.h"

int main()
{
    int a, b;
    while (cin >> a >> b) { cout << a << '\t' << b << '\n'; }
}
