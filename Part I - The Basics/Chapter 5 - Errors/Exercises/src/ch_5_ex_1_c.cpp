// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 20 Dez 2016
// Chapter 5, Exercise 1, Try this from page 146

/*
  Test this program with a variety of values.
  Insert tests until all errors are caught.
 */

#include "std_lib_facilities.h"

int area(int length, int width) // calculate area of a rectangle
{
    return length * width;
}

int framed_area(int x, int y) // calculate area within frame
{
    return area(x-2,y-2);
}

int f(int x = -1, int y = 2, int z = 4)
{
    int area1 = area(x, y);
    if (area1 <= 0) error("non-positive area");
    int area2 = framed_area(1, z);
    if (area2 <= 0) error("non-positive area");
    int area3 = framed_area(y, z);
    if (area3 <= 0) error("non-positive area");
    double ratio = double(area1) / area3; // convert do double to get
                                          // floating-point division
    cout << area1 << area2 << area3 << ratio << '\n';
}

int main()
{
    //f();
    //f(0);
    //f(1);
    //f(2);
    //f(10000);
    //f(4,-1);
    //f(4,4);
    f(4,4,-1);
}
