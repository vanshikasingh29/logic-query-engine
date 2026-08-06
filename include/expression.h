#ifndef EXPRESSION_H
#define EXPRESSION_H


#include "relation.h"



/*
============================================================

Expression Node

Represents:

grade > 80


============================================================
*/


typedef struct ExpressionNode
{


    char column[50];


    char operator;


    int value;



} ExpressionNode;





int evaluate_expression(
        Tuple tuple,
        ExpressionNode* expression
);




#endif