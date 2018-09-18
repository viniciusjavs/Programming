// Copyright (C) 2018 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 19 set 2018
// Chapter 7, Exercise 1. [Reworked]

/*
  calculator08buggy.cpp

  Helpful comments removed.

  We have inserted 3 bugs that the compiler will catch and 3 that it won't.
  Spotted bugs: [10]. Caught by compiler: [2]. Logical errors: [8].
*/

/*
  Allow underscores in the calculator's variable names.
*/

#include "std_lib_facilities.h"
#include "token_stream.h"
#include "variable.h"

vector<Variable> names;

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
    case Token_stream::let:
        return declaration();
    default:
        ts.unget(t);
        return expression();
    }
}

void set_value(string s, double d)
{
    for (auto &var : names)
        if (var.name == s) {
            var.value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool is_declared(string s)
{
    return find(names.begin(), names.end(), s) != names.end();
}

double define_name(string name, double val)
// Add {name, val} to var_table.
{
    if (is_declared(name)) error(name, " declared twice");
    names.push_back(Variable(name, val));
    return val;
}

double declaration()
// Allow to declare and initialize variables.
{
    Token t = ts.get();
    if (t.kind != Token_stream::name) error("name expected in declaration");
    string name = t.name;
    Token t2 = ts.get();
    if (t2.kind != Token_stream::assign)
        error(string(1, Token_stream::assign) + " missing in declaration of ",
              name);
    double d = expression();
    define_name(name, d);
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

double get_value(string s)
{
    for (const auto &var : names)
        if (var.name == s) return var.value;
    error("get: undefined name ", s);
    return 0; // This should never be reached!
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
        return get_value(t.name);
    default:
        error("primary expected");
    }
    return 0; // This should never be reached!
}
