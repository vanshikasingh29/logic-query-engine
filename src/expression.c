/*
============================================================

Logic Query Engine

expression.c


Purpose:

Implementation of Boolean expression trees.


============================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../include/expression.h"







ExpressionNode* create_expression(
        ExpressionType type,
        char* column,
        int value
)
{


    ExpressionNode* node =
        malloc(
            sizeof(ExpressionNode)
        );



    node->type = type;


    node->value = value;



    if(column)
    {

        strcpy(
            node->column,
            column
        );

    }


    node->left = NULL;


    node->right = NULL;



    return node;

}








int evaluate_expression(
        ExpressionNode* expression,
        int tuple_value
)
{


    if(expression == NULL)
        return 1;



    switch(expression->type)
    {


        case EXP_GREATER_THAN:

            return tuple_value >
                   expression->value;



        case EXP_LESS_THAN:

            return tuple_value <
                   expression->value;



        case EXP_EQUAL:

            return tuple_value ==
                   expression->value;






        case EXP_AND:

            return
            evaluate_expression(
                expression->left,
                tuple_value
            )
            &&
            evaluate_expression(
                expression->right,
                tuple_value
            );







        case EXP_OR:

            return
            evaluate_expression(
                expression->left,
                tuple_value
            )
            ||
            evaluate_expression(
                expression->right,
                tuple_value
            );



    }



    return 0;

}









void print_expression(
        ExpressionNode* expression,
        int depth
)
{


    if(expression == NULL)
        return;




    for(int i=0;i<depth;i++)
        printf("   ");




    switch(expression->type)
    {


        case EXP_AND:

            printf("AND\n");

            break;



        case EXP_OR:

            printf("OR\n");

            break;



        case EXP_GREATER_THAN:

            printf(
                "> %d\n",
                expression->value
            );

            break;



        case EXP_LESS_THAN:

            printf(
                "< %d\n",
                expression->value
            );

            break;



        case EXP_EQUAL:

            printf(
                "= %d\n",
                expression->value
            );

            break;


    }




    print_expression(
        expression->left,
        depth+1
    );


    print_expression(
        expression->right,
        depth+1
    );

}