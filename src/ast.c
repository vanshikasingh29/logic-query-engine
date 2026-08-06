/*
============================================================

Logic Query Engine

File:
ast.c

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/ast.h"

ASTNode* create_node(
        ASTNodeType type,
        const char* value
)
{

    ASTNode* node =
        malloc(sizeof(ASTNode));

    node->type = type;

    strcpy(node->value,value);

    node->left = NULL;

    node->right = NULL;

    return node;

}


static const char* node_name(
        ASTNodeType type
)
{

    switch(type)
    {

        case AST_SELECT:
            return "SELECT";

        case AST_PROJECTION:
            return "PROJECTION";

        case AST_WHERE:
            return "WHERE";

        case AST_IDENTIFIER:
            return "IDENTIFIER";

        case AST_NUMBER:
            return "NUMBER";

        case AST_GREATER_THAN:
            return ">";

        case AST_LESS_THAN:
            return "<";

        case AST_EQUAL:
            return "=";

        default:
            return "UNKNOWN";

    }

}


void print_ast(
        ASTNode* root,
        int depth
)
{

    if(root == NULL)
        return;

    for(int i=0;i<depth;i++)
        printf("    ");

    printf(
        "%s (%s)\n",
        node_name(root->type),
        root->value
    );

    print_ast(
        root->left,
        depth+1
    );

    print_ast(
        root->right,
        depth+1
    );

}


void free_ast(
        ASTNode* root
)
{

    if(root == NULL)
        return;

    free_ast(root->left);

    free_ast(root->right);

    free(root);

}