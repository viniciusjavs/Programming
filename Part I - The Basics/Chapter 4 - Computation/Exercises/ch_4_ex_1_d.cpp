//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 1, Try This - pag. 116
/*
 * C++ implementation of the first program ever to run
 * on a stored-program computer (the EDSAC) written by
 * David Wheeler - 1949, that calculate and print a
 * simple list of squares.
*/
#include "std_lib_facilities.h"

//function declaration
int square(int x);
// calculate and print a table of squares 0-99
int main()
{
  for (int i = 0; i < 100; ++i)
    cout << i << '\t' << square(i) << '\n';
}

int square(int x)
{
  int acc = 0;
  for (int i = 0; i < x; ++i) 
    acc += x;
  return acc;
}
