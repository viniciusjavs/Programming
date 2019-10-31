// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 27
// Chapter 4, Exercise 9

/*
  How many rice grains are given to 64 squares?
  What is the largest number of squares for which you can calculate the
  exact/approximate number of grains using a int/double?
*/

#include "std_lib_facilities.h"
#include <limits>

int main()
{
    int square = 1;
    int grain = 1, amount = 1;
    for (; amount != numeric_limits<int>::max();
         ++square, grain *= 2, amount += grain)
        ;
    cout << "The largest number of squares which can be"
         << " calculated using a 'int' is " << square << '\n';
    square = 1;
    double d_grain = 1, d_amount = 1;
    for (; d_amount < numeric_limits<double>::max();
         ++square, d_grain *= 2, d_amount += d_grain)
        ;
    cout << "The largest number of squares which can be"
         << " calculated using a 'double' is " << square - 1 << '\n';
}
