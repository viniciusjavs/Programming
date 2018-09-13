// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 20 Dez 2016
// Chapter 5, Exercise 1, Try this from page 138

/*
  Trying to compile some errors to see how compiler responds.
 */

#include "std_lib_facilities.h"

int area(int length, int width); // calculate area of a rectangle

int main()
{
    // int s1 = area(7;  // error: ) missing
    // int s2 = area(7)  // error: ; missing
    // Int s3 = area(7); // error: Int is not a type
    int s4 = area('7);   // error: non-terminated character (' missing)
}
