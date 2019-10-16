//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 3, Exercise 6
/*
 * Program that receives three integers and outputs it
 * in numerical sequence, separated by commas.
*/
#include "std_lib_facilities.h"
int main()
{
  cout << "Enter three integer numbers:\n";
  int val1, val2, val3;
  while (cin >> val1 >> val2 >> val3) {
    if (val1 < val2)
      if (val2 < val3) 
	cout << val1 << val2 << val3;
      else if (val3 > val1)
	cout << val1 << val3 << val2;
      else
	cout << val3 << val1 << val2;
    else if (val3 < val2)
	cout << val3 << val2 << val1;
      else if (val3 < val1) 
	  cout << val2 << val3 << val1;
      else 
	  cout << val2 << val1 << val3;
  }
}
