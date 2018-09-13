//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 3, Exercise 8
/*
 * Program to test that a number is odd or even
 * Bjarne Stroustrup technique - picking a defaul value and changing case needed.
*/
#include "std_lib_facilities.h"
int main()
{
  cout << "Enter a integer number :\n";
  int num;
  string res;
  while (cin >> num) {
    res = "even";
    if (num % 2 == 0) res = "odd";
    cout << "The number " << num << " is "<< res << "\n";
  }
}
