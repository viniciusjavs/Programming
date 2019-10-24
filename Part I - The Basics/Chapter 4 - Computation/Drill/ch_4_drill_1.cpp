//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Drill 1
/*
 * Program that reads two ints continously into a while-loop
 * and prints them. Entering '|' exits the program.
*/
#include "../../../include/std_lib_facilities.h"

int main()
{
  int a, b;
  while (cin >> a >> b) {
    cout << a << '\t' << b << '\n';
  }
}
