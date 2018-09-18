// Copyright (C) 2018 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 19 set 2018
// Chapter 7, Exercise 4. [Reworked]

/*
  calculator08buggy.cpp

  Helpful comments removed.

  We have inserted 3 bugs that the compiler will catch and 3 that it won't.
  Spotted bugs: [10]. Caught by compiler: [2]. Logical errors: [8].
*/

/*
  Allow underscores in the calculator's variable names.
  Provide an assignment operator '='.
  Provide named constants that you really can't change the value of.
   Define a class called Symbol_table.
*/

#include "std_lib_facilities.h"
#include "token_stream.h"
#include "symbol_table.h"

Symbol_table names;

Token_stream ts;

// Functions prototypes
double expression();
double primary();
double term();
double expression();
double declaration();
double statement();
void calculate();

int main() try {
    calculate();
    return 0;
}
catch (exception &e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open(string(1, Token_stream::quit));
    return 1;
}
catch (...) {
    cerr << "exception\n";
    keep_window_open(string(1, Token_stream::quit));
    return 2;
}

void clean_up_mess() { ts.ignore(Token_stream::print); } // eighth error.

void calculate()
// Deal with program control, like print, quit and operations.
{
    const string prompt = "> ";
    const string res = "= ";
    while (true) try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == Token_stream::print) t = ts.get(); // 7th error.
            if (t.kind == Token_stream::quit) return;
            ts.unget(t);
            double result = statement();
            if (t = ts.get(); t.kind == Token_stream::print)
                cout << res << result << endl;
            else
                ts.unget(t);
        }
        catch (runtime_error &e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
}

double statement()
// Deal with declarations or expressions.
{
    switch (Token t = ts.get(); t.kind) {
    case Token_stream::cnst:
    case Token_stream::let:
        ts.unget(t);
        return declaration();
    default:
        ts.unget(t);
        return expression();
    }
}

double declaration()
// Allow to declare and initialize variables or constants.
// let name = expression
// const name = expression
{
    Token t = ts.get();
    Token k = ts.get();
    if (k.kind != Token_stream::name) error("name expected in declaration");
    string name = k.name;
    if (Token t = ts.get(); t.kind != Token_stream::assign)
        error(string(1, Token_stream::assign) + " missing in declaration of ",
              name);
    double d = expression();
    if (t.kind == Token_stream::let)
        names.define_name(name, d);
    else
        names.define_name(name, d, true);
    return d;
}

double expression()
// Deal with + and -
{
    double left = term();
    while (true) {
        switch (Token t = ts.get(); t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

double term()
// Deal with * and /
{
    double left = primary();
    while (true) {
        switch (Token t = ts.get(); t.kind) {
        case '*':
            left *= primary();
            break;
        case '/': {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            break;
        }
        case '%': { // fourth error. (it was missing)
            int i = narrow_cast<int>(primary());
            if (i == 0) error("%: divide by zero");
            left = narrow_cast<int>(left) % i;
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double primary()
// Deal with numbers, variables and parentheses.
{
    switch (Token t = ts.get(); t.kind) {
    case '(': {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("'(' expected");
        return d; // second error (warned by compiler).
    }
    case '-':
        return -primary();
    case '+': // third error (it was missing).
        return primary();
    case Token_stream::number:
        return t.value;
    case Token_stream::name:
        if (Token k = ts.get(); k.kind == Token_stream::assign) {
            double d = expression();
            return names.set_value(t.name, d);
        }
        else {
            ts.unget(k);
            return names.get_value(t.name);
        }
    default:
        error("primary expected");
    }
    return 0; // This should never be reached!
}
