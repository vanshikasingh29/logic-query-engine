/*
============================================================

Logic Query Engine

File:
token.h

Purpose:

Defines lexical tokens recognised by
the query language.

============================================================
*/

#ifndef TOKEN_H
#define TOKEN_H

#define MAX_TOKEN_TEXT 64

typedef enum
{
    TOKEN_SELECT,
    TOKEN_WHERE,

    TOKEN_IDENTIFIER,

    TOKEN_NUMBER,

    TOKEN_GREATER_THAN,
    TOKEN_LESS_THAN,
    TOKEN_EQUAL,

    TOKEN_END,

    TOKEN_INVALID

} TokenType;

typedef struct
{
    TokenType type;

    char text[MAX_TOKEN_TEXT];

} Token;

const char* token_type_to_string(TokenType type);

#endif