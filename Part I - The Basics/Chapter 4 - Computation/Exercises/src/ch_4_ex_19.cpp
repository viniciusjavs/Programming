//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Execise 19
/*
 * Program that reads a set of name-and-value pairs
 * then checks that each name is unique. Writes out
 * all (name, value) pairs or a error message if a
 * name is entered twice.
*/
#include "std_lib_facilities.h"

bool has_twice(vector<string> names)
{
  sort(names); //adjacent names
  for(unsigned int i = 1; i < names.size(); ++i)
    if (names[i] == names[i-1])
      return true;
  return false;
}

int main()
{
  vector<string> names;
  vector<int> scores;
  cout << "Enter a set of name-and-value pairs: \n";
  string name;
  int score;
  cin >> name >> score;
  while (name != "NoName" || score != 0) {
    names.push_back(name);
    scores.push_back(score);
    cin >> name >> score;
  }
  if (!has_twice(names))
    for(unsigned int i = 0; i < names.size(); ++i)
      cout << names[i] << ' ' << scores[i] << '\n';
  else
    cout << "Error: twice words detected!" << '\n';
}
