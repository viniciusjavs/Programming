//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 3, Exercise 7
/*
 * Program that receives three strings and outputs it
 * in alphabetical order, separated by commas.
*/
#include "std_lib_facilities.h"
int main()
{
  cout << "Enter three string values :\n";
  string val1, val2, val3, min, med, max;
  while (cin >> val1 >> val2 >> val3) {
    if (val1 < val2)
      if (val1 < val3)
	if (val2 < val3) { min = val1; med = val2; max = val3; }
	else { min = val1; med = val3; max = val2; }

    if (val2 < val3)
      if (val2 < val1)
	if (val3 < val1)  { min = val2; med = val3; max = val1; }
	else   { min = val2; med = val1; max = val3; }
    
    if (val3 < val1)
      if (val3 < val2)
	if (val1 < val2) { min = val3; med = val1; max = val2; }
	else { min =val3; med=val2; max=val1; }
    cout << min << ", " << med << ", " << max;
  }
}
