// Copyright (C) 2017 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 14 Jan 2017
// Chapter 6, Exercise 6

/*
  Program that checks if a sentence is correct according to the "English"
  grammar in 6.4.1. Every sentence is terminated by a full stop (.) surrounded
  by a whitespace. Response would simply be "OK" or "Not OK".
 */

#include "std_lib_facilities.h"

//global
vector<string> article = {"the"};
vector<string> noun = {"birds", "fish", "C++"};
vector<string> verb = {"rules", "fly", "swim++"};
vector<string> stop = {"."};
vector<string> conjunct = {"and", "or", "but"};

bool in(string str, vector<string> strings)
{
   for (auto s : strings)
	if (str == s) return true;
    return false;
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
    return false;
}

int main()
try
{
    cout << "Enter a sentence of the \"English\" grammar in 6.4.1 (terminated "
            "by a dot):\n";
    string res = "not OK";
    if (sentence())
	res = "OK";
    cout << res << '\n';
    return 0;
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}
