// Copyright (C) 2018 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 17 set 2018
// Chapter 6, Exercise 1, Thy this from page 216. [Reworked]

/*
  Second version of the calculator program.
  File: calculator01.cpp a.k.a calculator02buggy.cpp
 */

//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
        This file is known as calculator02buggy.cpp [former calculator01.cpp]

        I have inserted 5 errors that should cause this not to compile. [v]
        I have inserted 3 logic errors that should cause the program to give [v]
   wrong results

        First try to find an remove the bugs without looking in the book.
        If that gets tedious, compare the code to that in the book (or posted
   source code)

        Happy hunting!

*/

#include "std_lib_facilities.h"
#include "token.h"
#include "token_stream.h"

Token_stream ts; // provides get() and putback()

// Functions prototypes
double expression();
double term();
double primary();

int main() try {
    double val = 0; // Fifth compile error.
    while (cin) {
        switch (Token t = ts.get(); t.kind) {
        case 'q':
            return 0; // 'q' for quit
        case ';':     // ';' for "print now"
            cout << "=" << val << '\n';
	    val=0;
            break;
        default:
            ts.putback(t);
            val = expression(); // Fourth logical error.
        }
    }
}
catch (exception &e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}

// deal with + and -
double expression()
{
    double left = term(); // Fourth compile error. // read and evaluate a Term
    Token t = ts.get();   // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term(); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            // First logical error.
            left -= term(); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t); // put t back into the token stream
            return left;   // finally: no more + or -: return the answer
        }
    }
}

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get(); // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break; // Second logical error.
        case '/': {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t); // put t back into the token stream
            return left;
        }
    }
}

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(': // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected"); // Third compile error.
        return d;
    }
    case '8':           // we use '8' to represent a number
        return t.value; // return the number's value
    default:
        error("primary expected");
        return 0; // This should never be reached, it was putted just to silence
                  // the compiler.
    }
}
