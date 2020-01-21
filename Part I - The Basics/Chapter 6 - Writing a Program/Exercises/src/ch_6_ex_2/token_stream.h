#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include "token.h"

class Token_stream {
  public:
    Token_stream();        // make a Token_stream that reads from cin
    Token get();           // get a Token (get() is defined elsewhere)
    void putback(Token t); // put a Token back
  private:
    bool full;    // is there a Token in the buffer?
    Token buffer; // here is where we keep a Token put back using putback()
};

#endif /* TOKEN_STREAM_H */
