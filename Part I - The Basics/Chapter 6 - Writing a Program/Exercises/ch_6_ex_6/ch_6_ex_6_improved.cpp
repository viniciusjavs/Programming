// Copyright (C) 2018 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 18 set 2018
// Chapter 6, Exercise 6. [Improved] [Reworked]

/*
  Program that checks if a sentence is correct according to the "English"
  grammar in §6.4.1 (that was improved in exercise 5).
  Every sentence is terminated by a full stop (.) surrounded by a whitespace.
  Response would simply be "OK" or "Not OK".
 */

#include "std_lib_facilities.h"

// global
vector<string> articles{"the"};
vector<string> nouns{"birds", "fish", "C++"};
vector<string> verbs{"rules", "fly", "swim"};
vector<string> conjuncts{"and", "or", "but"};
vector<string> stops{"."};

inline bool in(string str, vector<string> strings)
/*
  Checks if str is in vector
*/
{
    return find(strings.begin(), strings.end(), str) != strings.end();
}

bool sentence()
{
    string str1;
    cin >> str1;
    if (!in(str1, nouns) && !in(str1, articles)) return false;
    string str2;
    cin >> str2;
    if (in(str1, nouns) && !in(str2, verbs)) return false;
    if (in(str1, articles) && !in(str2, nouns)) return false;
    if (string str3; in(str1, articles)) { // deal with article
        cin >> str3;
        if (!in(str3, verbs)) return false;
    }
    string str3;
    cin >> str3;
    if (in(str3, stops)) return true; // full stop
    if (in(str3, conjuncts)) return sentence();
    return false;
}

int main() try {
    cout << "Enter a sentence based on the \"English\" grammar in §6.4.1,\n"
            "terminated by a space followed by a dot:\n";
    string res = "not OK";
    if (sentence()) res = "OK";
    cout << res << '\n';
    return 0;
}
catch (exception &e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}
