//Chapter 3, Exercise 1
//Try this from page 81
/*
 * Program safe/unsafe conversions
*/
#include "std_lib_facilities.h"
int main()
{
  double d = 0;
  while (cin>>d) {
    int i = d;   //try to squeeze a double into a int
    char c = i;   //try to squeeze a int into a char
    int i2 = c;   //get the integer value of a character
    cout << "d == " << d   //original double
	 << "\ni == " << i   //converted to int
	 << "\ni2 == " << i2   //int value of a char
	 << "\n char (" << c << ")\n"; // the char
  }
}
