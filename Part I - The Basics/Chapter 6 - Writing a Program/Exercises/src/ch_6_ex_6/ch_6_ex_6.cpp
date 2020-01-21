// Copyright (C) 2018 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 18 set 2018
// Chapter 6, Exercise 6. [Reworked]

/*
  Program that checks if a sentence is correct according to the "English"
  grammar in §6.4.1 (that was improved in exercise 5).
  Every sentence is terminated by a full stop (.) surrounded by a whitespace.
  Response would simply be "OK" or "Not OK".
*/

#include "std_lib_facilities.h"

// global
vector<string> article{"the"};
vector<string> noun{"birds", "fish", "C++"};
vector<string> verb{"rules", "fly", "swim"};
vector<string> conjunct{"and", "or", "but"};
vector<string> stop{"."};

inline bool in(string str, vector<string> strings)
/*
  Checks if str is in vector
*/
{
    return find(strings.begin(), strings.end(), str) != strings.end();
}

bool sentence()
{
    string str;
    cin >> str;
    if (in(str, article)) {
        cin >> str;
        if (in(str, noun)) {
            cin >> str;
            if (in(str, verb)) {
                cin >> str;
                if (in(str, stop))
                    return true;
                else if (in(str, conjunct))
                    return sentence();
            }
        }
    }
    else {
        if (in(str, noun)) {
            cin >> str;
            if (in(str, verb)) {
                cin >> str;
                if (in(str, stop))
                    return true;
                else if (in(str, conjunct))
                    return sentence();
            }
        }
    }
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
