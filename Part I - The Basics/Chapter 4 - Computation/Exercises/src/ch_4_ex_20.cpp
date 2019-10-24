//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Execise 20
/*
 * Program that reads a set of name-and-value pairs
 * then checks that each name is unique. Writes out
 * all (name, value) pairs or a error message if a
 * name is entered twice.
 * Entering a name, will be outputted the score
 * or 'name not found'.
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

int idx_by_value(string name, vector<string> names)
{
  for(unsigned int i = 0; i < names.size(); ++i)
    if (name == names[i])
      return i;
  return -1;
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
    for(string name; cin >> name;) {
      auto idx = idx_by_value(name, names);
      if (idx >= 0)
	cout << scores[idx] << '\n';
      else
	cout << "Name not found!\n";
    }
  else
    cout << "Error: twice words detected!" << '\n';
}
