/*
============================================================

Logic Query Engine

planner.c


Logical Query Planner


============================================================
*/


#include <stdio.h>

#include "../include/planner.h"



QueryPlan create_plan(
        ASTNode* ast
)
{


    QueryPlan plan;


    plan.root = ast;


    return plan;

}





void print_plan(
        QueryPlan plan
)
{


    printf("\nLogical Query Plan\n");

    printf("-------------------\n");



    print_ast(
        plan.root,
        0
    );

}