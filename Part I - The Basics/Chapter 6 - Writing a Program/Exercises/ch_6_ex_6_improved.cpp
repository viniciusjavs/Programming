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
vector<string> articles = {"the"};
vector<string> nouns = {"birds", "fish", "C++"};
vector<string> verbs = {"rules", "fly", "swim++"};
vector<string> stops = {"."};
vector<string> conjuncts = {"and", "or", "but"};

bool in(string str, vector<string> strings)
/*
  Checks if str is in vector
*/
{
   for (auto s : strings)
	if (str == s) return true;
    return false;
}

bool article()
{
    string str;
    cin >> str;
    if (in(str, articles))
	return true;
    return false;
}

bool noun()
{
    string str;
    cin >> str;
    if (in(str, nouns))
	return true;
    return false;
}

bool verb()
{
    string str;
    cin >> str;
    if (in(str, verbs))
	return true;
    return false;
}

bool conjunct()
{
    string str;
    cin >> str;
    if (in(str, conjuncts))
	return true;
    return false;
}

bool stop()
{
    string str;
    cin >> str;
    if (in(str, stops))
	return true;
    return false;
}

bool sentence()
{
    if (!article()) return false;
    if (!noun()) return false;
    if (!verb()) return false;
    if (stop()) return true;
    if (!conjunct()) return false;
    return sentence();
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
