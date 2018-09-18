#include "token_stream.h"

Token Token_stream::get()
/*
  Read characters from cin and compose a Token.
 */
{
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch; // skip whitespace (sapce, newline, tab, etc).
    switch (ch) {
    case print:
    case quit: // sixth error
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case assign:
        return Token(ch);
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
        cin.unget();
        double val;
        cin >> val;
        return Token(number, val);
    }
    default:
        if (isalpha(ch) || "_") {
            string s;
            s += ch;
            while (cin.get(ch) && (isalnum(ch) || ch == '_'))
                s += ch; // fifth error.
            cin.unget();
            if (s == declkey) return Token(let);
            return Token(name, s);  // variable name
        }
        error("Bad token");
        return 0; // This should never be reached!
    }
}

void Token_stream::unget(Token t)
{
    buffer = t;
    full = true;
}

void Token_stream::ignore(char c)
/*
  Skip until we find c.
  c represents the kind of Token.
*/
{
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    char ch;
    cin.clear();    // ninth error.
    cin.putback(c); // tenth error
    while (cin >> ch)
        if (ch == c) return;
}
