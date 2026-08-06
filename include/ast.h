/*
============================================================

Logic Query Engine

File:
ast.h

Purpose:

Defines the Abstract Syntax Tree used
to represent parsed SQL queries.

============================================================
*/

#ifndef AST_H
#define AST_H

#define MAX_NODE_TEXT 64

/*
--------------------------------------------
Node Types
--------------------------------------------
*/

typedef enum
{
    AST_SELECT,

    AST_PROJECTION,

    AST_WHERE,

    AST_IDENTIFIER,

    AST_NUMBER,

    AST_GREATER_THAN,

    AST_LESS_THAN,

    AST_EQUAL

} ASTNodeType;


/*
--------------------------------------------
AST Node
--------------------------------------------
*/

typedef struct ASTNode
{

    ASTNodeType type;

    char value[MAX_NODE_TEXT];

    struct ASTNode* left;

    struct ASTNode* right;

} ASTNode;


/*
--------------------------------------------
Functions
--------------------------------------------
*/

ASTNode* create_node(
        ASTNodeType type,
        const char* value
);

void print_ast(
        ASTNode* root,
        int depth
);

void free_ast(
        ASTNode* root
);

#endif