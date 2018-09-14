// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 22 Dec 2016
// Chapter 5, Exercise 1, Try this from page 166

/*
  Breaking post-condition in a function of a snippet code
 */

#include "std_lib_facilities.h"

int area(int length, int width)
/*
  calculate area of a rectangle
  pre-conditions: length and width are positive
  post-condition: returns a positive value that is the area
 */
{
    //if (length <= 0 || width <= 0)
    //    error("area() pre-condition");
    int a = length * width;
    if (a <= 0)
        error("area() post-condition");
    return a;
}

int main()
try {
    area(-1,-2); // pre-condition holds, but post-condition doesn't
}
catch (runtime_error& e) {
    cerr << e.what() << '\n';
}
