/*
============================================================

lexer.h

============================================================
*/

#ifndef LEXER_H
#define LEXER_H

#include "token.h"

#define MAX_TOKENS 64

typedef struct
{
    Token tokens[MAX_TOKENS];

    int count;

} TokenStream;

TokenStream tokenize(const char* input);

void print_tokens(TokenStream stream);

#endif