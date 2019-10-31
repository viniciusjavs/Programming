// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Oct. 04
// Chapter 4, Exercise 21

/*
  Program that reads a set of name-and-value pairs then checks that each name is
  unique. It writes out all (name, value) pairs or a error message if a name is
  entered twice. Entering a score, will be outputted the names with that score
  or 'score not found'.
*/

#include "std_lib_facilities.h"

bool has_twice(vector<string> names)
{
    sort(names); // adjacent names
    for (unsigned int i = 1; i < names.size(); ++i)
        if (names[i] == names[i - 1]) return true;
    return false;
}

vector<unsigned int> idxs_by_value(int score, vector<int> scores)
{
    vector<unsigned int> idxs;
    for (unsigned int i = 0; i < scores.size(); ++i)
        if (score == scores[i]) idxs.push_back(i);
    return idxs;
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
        for (int score; cin >> score;) {
            auto idxs = idxs_by_value(score, scores);
            if (!idxs.empty())
                for (auto idx : idxs) cout << names[idx] << '\n';
            else
                cout << "Score not found!\n";
        }
    else
        cout << "Error: twice words detected!" << '\n';
}
