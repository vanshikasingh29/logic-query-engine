/*
============================================================

Logic Query Engine

File:

parser.h


Purpose:

Defines query parsing structures.

Version 2.1

Pipeline:

SQL Text

↓

Lexer

↓

Tokens

↓

Parser

↓

Query Structure

+

Abstract Syntax Tree


============================================================
*/


#ifndef PARSER_H
#define PARSER_H


#include "lexer.h"
#include "ast.h"


#define MAX_COLUMN_LENGTH 50



/*
============================================================

Operators

============================================================
*/

typedef enum
{

    OP_GREATER_THAN,

    OP_LESS_THAN,

    OP_EQUAL


} Operator;




/*
============================================================

Predicate

Example:

grade > 80


============================================================
*/


typedef struct
{

    char column[MAX_COLUMN_LENGTH];

    Operator operator;

    int value;


} Predicate;




/*
============================================================

Query

Compatibility layer.

The execution engine currently
uses this representation.

Future versions execute AST directly.

============================================================
*/


typedef struct
{

    char projection[MAX_COLUMN_LENGTH];

    Predicate condition;


} Query;




/*
============================================================

Parser API

============================================================
*/


Query parse_query(
        char* input
);



Query parse_tokens(
        TokenStream tokens
);



void print_query(
        Query query
);



ASTNode* get_latest_ast(void);



#endif