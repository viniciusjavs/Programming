// Copyright (C) 2017 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 24 Jan 2017
// Chapter 7, Exercise 1

/*
  calculator08buggy.cpp

  Helpful comments removed.

  We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

/*
  Allow underscores in the calculator's variable names
 */

#include "std_lib_facilities.h"

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) : kind{ch}, value{0} {} // initialize kind with ch
    Token(char ch, double val) : kind{ch}, value{val} {} // initialize kind and value
    Token(char ch, string n) : kind{ch}, name{n} {} // initialize kind and name
};

class Token_stream {
    bool full;
    Token buffer;

  public:
    Token_stream() : full{0}, buffer{0} {}

    Token get();
    void putback(Token t) { buffer = t; full = true; }

    void ignore(char);
};

constexpr char let = 'L';   // declaration token
constexpr char root = 'S';  // sqrt token
constexpr char power = 'P'; // pow token
constexpr char quit = 'Q';  // quit token
constexpr char print = ';';
constexpr char number = '8';
constexpr char name = 'a';     // name token
const string declkey = "let";  // declaration keyword
const string sqrtkey = "sqrt"; // sqrt keyword
const string powerkey = "pow"; // pow keyword
const string quit_s = "exit";  // quit keyword

Token Token_stream::get()
/*
  read characters from cin and compose a Token
 */
{
    if (full) { // check if we already have a Token ready
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch; // note that >> skips whitespace (sapce, newline, tab, etc)
    switch (ch) {
    case quit:
    case print:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '=':             // assignment
    case ',':             // used in pow(x,i);
        return Token(ch); // let each character represent itself
    case '.':             // a floating-point-literal can start with a dot
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9': // numeric literal
    {
        cin.putback(ch); // put digit back into the input stream
        double val;
        cin >> val; // read a floating-point number
        return Token(number, val);
    }
    default:
        if (isalpha(ch) || ch == '_') {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || ch == '_' || isdigit(ch))) s += ch;
            cin.putback(ch);
            if (s == declkey) return Token{let}; // declaration keyword
            if (s == sqrtkey) return Token{root}; // sqrt keyword
            if (s == powerkey) return Token{power}; // pow keyword
            if (s == quit_s) return Token{quit}; // another way to quit
            return Token{name, s}; // variable name
        }
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
/*
  Skip until we find c.
  c represents the kind of Token.
 */
{
    // first look in buffer
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    
    // now search input
    char ch = 0;
    while (cin >> ch)
        if (ch == c)
            return;
}

class Variable {
  public:
    string name;
    double value;
    Variable(string n, double v) : name{n}, value{v} {}
};

vector<Variable> var_table;

double get_value(string s)
/*
  return the value of the Variable named "s"
 */
{
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    error("get: undefined variable ", s);
}

void set_value(string s, double d)
/*
  set the Variable named "s" to "d"
 */
{
    for (Variable &v : var_table)
        if (v.name == s) {
            v.value = d;
            return;
        }
    error("set: undefined variable ", s);
}

bool is_declared(string s)
/*
  is var already in var_table?
 */
{
    for (const Variable& v : var_table)
        if (v.name == s) return true;
    return false;
}

double define_name(string var, double val)
/*
  add {var,val} to var_table
 */
{
    if (is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable{var,val});
    return val;
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(': // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("'(' expected");
	return d;
    }
    case '-':
        return -primary();
    case root:
    {
        t = ts.get();
        if (t.kind != '(') error("'(' expected");
	double d = primary();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
	if (d<0) error("Attempt to sqrt of negative number");
	return sqrt(d);
    }
    case power:
    {
        t = ts.get();
        if (t.kind != '(') error("'(' expected");
        double d = primary();
	t = ts.get();
        if (t.kind != ',') error("',' expected");
        double i = primary();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        narrow_cast<int>(i); // require i to be an integer
        return pow(d,i);
    }
    case number:
        return t.value; // returns the number's value
    case name:
        return get_value(t.name);
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '*':
            left *= primary();
            break;
        case '/':
	{
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            break;
        }
	case '%':
	{
	    int i1 = narrow_cast<int>(left);
	    int i2 = narrow_cast<int>(primary());
	    if (i2 == 0) error("%: divide by zero");
	    left = i1%i2;
	    break;
	}
        default:
            ts.putback(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

double declaration()
/*
  assume we have seen "let".
  handle: name = expression.
  declare a variable called "name" with the initial value "expression"
 */
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;
    
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);
    
    double d = expression();
    define_name(var_name, d);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

void clean_up_mess() { ts.ignore(print); }

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while (cin)
	try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get(); // first discard all prints
            if (t.kind == quit) return;
            ts.putback(t);
            cout << result << statement() << '\n';
        }
        catch (runtime_error &e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
}

int main()
try {
    define_name("k", 1000);
    calculate();
    return 0;
}
catch (exception &e) {
    cerr << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "exception \n";
    return 2;
}
