//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 6
/*
 * Program that converts a digit to its corresponding spelled-out value
 * and converts spelled-out numbers into their digit form.
*/

#include "std_lib_facilities.h"

int main()
{
  vector<string> digits
    = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  while (true) {
    int in_int;
    if (cin >> in_int)
      if (in_int >= 0 && in_int < 10)
	cout << digits[in_int] << '\n';
      else
	cout << "Error: "<< in_int << " is out of range!\n";
    else {
      cin.clear();
      string in_str;
      cin >> in_str;  //recupere from buffer
      int pos = digits.size();  //out of range
      for (int i = 0; i < digits.size(); ++i)
	if (in_str == digits[i])
	  pos = i;
      if (pos != digits.size())
	cout << pos << '\n';
      else
	cout << "Error: " << in_str << " is a unknown value\n";
    }
  }
}
