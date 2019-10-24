//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 1, Try This - pag. 111
/*
 * Program that writes a table of characters with
 * their correspoding integers values
*/
#include "std_lib_facilities.h"
int main()
{
  int i {0};

  while ( i < 26 ) {
    cout << char('a' + i) << '\t' << 'a' + i << '\n';
    ++i;
  }
}
