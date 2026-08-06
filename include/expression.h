/*
============================================================

Logic Query Engine

expression.h


Purpose:

Defines Boolean expression trees.


Database predicates are not stored
as simple conditions.

They are trees.


Example:


grade > 80 AND grade < 95


becomes:


          AND

        /     \

     >80       <95



============================================================
*/


#ifndef EXPRESSION_H
#define EXPRESSION_H



typedef enum
{


    EXP_GREATER_THAN,

    EXP_LESS_THAN,

    EXP_EQUAL,


    EXP_AND,

    EXP_OR



} ExpressionType;





typedef struct ExpressionNode
{


    ExpressionType type;



    char column[50];


    int value;



    struct ExpressionNode* left;


    struct ExpressionNode* right;



} ExpressionNode;







ExpressionNode* create_expression(
        ExpressionType type,
        char* column,
        int value
);




int evaluate_expression(
        ExpressionNode* expression,
        int tuple_value
);




void print_expression(
        ExpressionNode* expression,
        int depth
);



#endif