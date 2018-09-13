//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 1, Try This - pag. 113
/*
 * Program that writes a table of characters with
 * their correspoding integers values, including
 * uppercase letters and digits.
*/
#include "std_lib_facilities.h"
int main()
{
  for (int i {0}; i < 26; ++i) //print out lowercase a-z
    cout << char('a' + i) << '\t' << 'a' + i << '\n';
  for (int i {0}; i < 26; ++i) //print out uppercase A-Z
    cout << char('A' + i) << '\t' << 'A' + i << '\n';
  for (int i {0}; i < 10; ++i) //print out digits 0-9
    cout << char('0' + i) << '\t' << '0' + i << '\n';
}
