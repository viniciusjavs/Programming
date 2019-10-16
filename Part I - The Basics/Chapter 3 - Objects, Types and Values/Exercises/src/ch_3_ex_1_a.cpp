// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Aug. 29, 2016
// Chapter 3, Exercise 1
// Try this from page 65

/*
  Read name and age and print them.
  'age' should be read in years and printed in months.
 */

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter your first name and age:\n";
    string first_name;
    double age;
    cin >> first_name >> age;
    cout << "Hello, " << first_name << " (age  " << age * 12 << ")\n";
}
