//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 1, Try This - pag. 125
/*
 * Program that reads in words and print them on cout
 * and then "bleeps" out words that are undesirable.
*/
#include "std_lib_facilities.h"

//function declarations
bool is_word_listed(string word, vector<string> list);

int main()
{
  vector<string> word_list;
  vector<string> black_list = {"Broccoli", "Tomato", "Onion"};
  for (string word; cin >> word;) // read words
    word_list.push_back(word);
  for (string word : word_list) // print words, checking undesired them
    if ( is_word_listed(word, black_list) )
      cout << "BLEEP" << '\n';
    else
      cout << word << '\n';
}

bool is_word_listed(string word, vector<string> list)
{
  for (string listed_word : list)
    if (listed_word == word)
      return true;
  return false;
}
