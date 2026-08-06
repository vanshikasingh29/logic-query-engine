/*
============================================================

Logic Query Engine

planner.h


Purpose:

Creates a logical execution plan
from an Abstract Syntax Tree.


Database systems separate:

Parser

↓

Planner

↓

Executor


============================================================
*/


#ifndef PLANNER_H
#define PLANNER_H


#include "ast.h"



typedef struct
{

    ASTNode* root;


} QueryPlan;



QueryPlan create_plan(
        ASTNode* ast
);



void print_plan(
        QueryPlan plan
);



#endif