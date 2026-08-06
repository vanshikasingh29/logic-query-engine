/*
============================================================

Logic Query Engine

File:

parser.c


Version:

2.1


Purpose:

Converts token streams into:

1. Query structure
2. Abstract Syntax Tree


============================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../include/parser.h"



static ASTNode* latest_ast = NULL;



ASTNode* get_latest_ast(void)
{
    return latest_ast;
}



/*
============================================================

Convert token operator

============================================================
*/


Operator token_to_operator(
        TokenType type
)
{

    switch(type)
    {

        case TOKEN_GREATER_THAN:

            return OP_GREATER_THAN;



        case TOKEN_LESS_THAN:

            return OP_LESS_THAN;



        case TOKEN_EQUAL:

            return OP_EQUAL;



        default:

            return OP_EQUAL;

    }

}




/*
============================================================

Create AST

Example:


SELECT name WHERE grade > 80



        SELECT

       /      \

PROJECTION    WHERE

(name)          |

                >

             /     \

          grade     80


============================================================
*/


static ASTNode* create_query_ast(
        Query query
)
{

    ASTNode* root =
        create_node(
            AST_SELECT,
            "SELECT"
        );



    root->left =
        create_node(
            AST_PROJECTION,
            query.projection
        );



    ASTNode* where =
        create_node(
            AST_WHERE,
            "WHERE"
        );



    ASTNode* operation;



    switch(query.condition.operator)
    {

        case OP_GREATER_THAN:

            operation =
                create_node(
                    AST_GREATER_THAN,
                    ">"
                );

            break;



        case OP_LESS_THAN:

            operation =
                create_node(
                    AST_LESS_THAN,
                    "<"
                );

            break;



        default:

            operation =
                create_node(
                    AST_EQUAL,
                    "="
                );

    }




    operation->left =
        create_node(
            AST_IDENTIFIER,
            query.condition.column
        );



    char number[32];


    sprintf(
        number,
        "%d",
        query.condition.value
    );



    operation->right =
        create_node(
            AST_NUMBER,
            number
        );



    where->left =
        operation;



    root->right =
        where;



    return root;

}





/*
============================================================

Token Parser


Expected grammar:


SELECT <column>

WHERE

<column> <operator> <number>


============================================================
*/


Query parse_tokens(
        TokenStream tokens
)
{

    Query query;


    int index = 0;



    if(tokens.tokens[index].type
            == TOKEN_SELECT)
    {
        index++;
    }



    strcpy(
        query.projection,
        tokens.tokens[index].text
    );


    index++;




    if(tokens.tokens[index].type
            == TOKEN_WHERE)
    {
        index++;
    }




    strcpy(
        query.condition.column,
        tokens.tokens[index].text
    );


    index++;




    query.condition.operator =
        token_to_operator(
            tokens.tokens[index].type
        );


    index++;




    query.condition.value =
        atoi(
            tokens.tokens[index].text
        );



    if(latest_ast)
    {
        free_ast(latest_ast);
    }



    latest_ast =
        create_query_ast(query);



    return query;

}





/*
============================================================

Public parser entry point

============================================================
*/


Query parse_query(
        char* input
)
{

    TokenStream tokens =
        tokenize(input);


    return parse_tokens(tokens);

}





void print_query(
        Query query
)
{

    printf("\nParsed Query\n");

    printf("----------------\n");


    printf(
        "Projection: %s\n",
        query.projection
    );


    printf(
        "Condition Column: %s\n",
        query.condition.column
    );


    printf(
        "Condition Value: %d\n",
        query.condition.value
    );


}