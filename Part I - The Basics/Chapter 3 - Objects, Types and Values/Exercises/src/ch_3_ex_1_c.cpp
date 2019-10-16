//Chapter 3, Exercise 1
//Try this from page 73
/*
 * Program repeted word detection from page 71.
*/
#include "std_lib_facilities.h"
int main()
{
  string previous = "";   //previous word initialized to "not a word"
  string current;   //current word
  while (cin >> current) {   //read a stream of words
    if (previous == current)   //check if the word is the same as last
      cout << "repeted word: " << current << '\n';
    previous = current;
  }
}
