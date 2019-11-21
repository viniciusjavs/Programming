// Copyright (C) 2016 vjavs
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Dec. 20, 2016
// Chapter 5, Exercise 1, Try this from page 139

/*
  Trying to compile some errors to see how the compiler responds.
  Adding new kind of errors.
 */

#include "std_lib_facilities.h"

int area(int length, int width); // calculate area of a rectangle

int main()
{
    // int x0 = arena(7);         // error: undeclared function
    // int x1 = area(7)           // error: wrong number of arguments
    // int x2 = area("seven", 7); // error: 1st argument has a wrong type
    // string x4 = area(7,7);     // error: wrong return type
    char x5 = area(7,7);          // error: linking error
}
