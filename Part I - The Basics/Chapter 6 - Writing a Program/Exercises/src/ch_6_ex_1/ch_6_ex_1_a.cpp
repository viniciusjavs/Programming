// Copyright (C) 2018 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 17 set 2018
// Chapter 6, Exercise 1, Try this from page 204. [Reworked]

/*
  First version of the calculator program.
  File: calculator00.cpp
 */

//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"
#include "token.h"

Token get_token() // read a token from cin
{
    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    // not yet   case ';':    // for "print"
    // not yet   case 'q':    // for "quit"
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
        return Token(ch); // let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': {
        cin.putback(ch); // put digit back into the input stream
        double val;
        cin >> val;             // read a floating-point number
        return Token('8', val); // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}

double expression(); // read and evaluate a Expression

int main() try {
    while (cin)
        cout << "= " << expression() << '\n';
    keep_window_open("~0");
}
catch (exception &e) {
    cerr << e.what() << endl;
    keep_window_open("~1");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~2");
    return 2;
}

double primary()
{
    Token t(get_token());
    switch (t.kind) {
    case '(': // handle '(' expression ')'
    {
        double d = expression();
        t = get_token();
        if (t.kind != ')')
            error("')' expected");
        return d;
    }
    case '8':           // we use '8' to represent a number
        return t.value; // return the number's value
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    Token t = get_token(); // get the next token

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/': {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            t = get_token();
            break;
        }
        default:
            return left;
        }
    }
}

double expression()
{
    double left = term(); // read and evaluate a Term
    Token t(get_token()); // get the next token
    while (true) {
        switch (t.kind) {
        case '+':
            left += term(); // evaluate Term and add
            t = get_token();
            break;
        case '-':
            left -= term(); // evaluate Term and subtract
            t = get_token();
            break;
        default:
            return left; // finally: no more + or -: return the answer
        }
    }
}
