// Copyright (C) 2017 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 14 Jan 2017
// Chapter 6, Exercise 4

/*
  Rework of the exercise 19 in Chapter 4, using a class Name_value and a vector
  <Name_value> instead of two vectors.
  Chapter 4, Exercise 19:
  Program that reads a set of name-and-value pairs
  then checks that each name is unique. Writes out
  all (name, value) pairs or a error message if a
  name is entered twice.
 */

#include "std_lib_facilities.h"

class Name_value {
  public:
    string name;
    int score{0};
};

bool has_twice(vector<Name_value>);

int main() try {
    vector<Name_value> pairs;
    cout << "Enter a set of name-and-value pairs: \n";
    Name_value pair;
    cin >> pair.name >> pair.score;
    while (pair.name != "NoName" || pair.score != 0) {
        pairs.push_back(pair);
        cin >> pair.name >> pair.score;
    }
    if (!has_twice(pairs))
        for (auto pair : pairs)
            cout << pair.name << ' ' << pair.score << '\n';
    else
        error("twice words detected!");
    return 0;
}
catch (runtime_error &e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}

bool has_twice(vector<Name_value> pairs)
{
    for (unsigned int i = 0; i < pairs.size() - 1; ++i)
        for (unsigned int j = i + 1; j < pairs.size(); ++j)
            if (pairs[i].name == pairs[j].name)
                return true;
    return false;
}
