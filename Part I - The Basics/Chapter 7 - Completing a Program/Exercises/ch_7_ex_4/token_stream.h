#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include "token.h"

class Token_stream {
    bool full;
    Token buffer;

  public:
    static constexpr char quit = 'q';
    static constexpr char print = ';';
    static constexpr char let = 'L';
    static constexpr char cnst = 'C';
    static constexpr char name = 'a';
    static constexpr char number = '8';
    static constexpr char assign = '=';
    const string declkey = "let";
    const string constkey = "const";
    Token_stream() : full(0), buffer(0) {}
    Token get();
    void unget(Token);
    void ignore(char);
};

#endif /* TOKEN_STREAM_H */
