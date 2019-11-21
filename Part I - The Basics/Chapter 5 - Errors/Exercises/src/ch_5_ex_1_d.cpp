// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 21 Dec 2016
// Chapter 5, Exercise 1, Try this from page 153

/*
  A small program that uses error() without catching any exceptions.
 */

#include "std_lib_facilities.h"

int area(int length, int width) // calculate area of a rectangle
{
    return length * width;
}

int main()
{
    int x = -1, y = 2;
    int area1 = area(x, y);
    if (area1 <= 0) error("non-positive area");
}
