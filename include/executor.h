/*
============================================================

Logic Query Engine

File:

executor.h


Purpose:

Execution layer.

Version 2.2

The executor now supports:

Query Structure

and

Abstract Syntax Tree


Architecture:

AST

↓

Planner

↓

Relational Algebra

↓

Result Relation


============================================================
*/


#ifndef EXECUTOR_H
#define EXECUTOR_H



#include "relation.h"
#include "parser.h"
#include "ast.h"





/*
============================================================

Predicate Evaluation


Example:

grade > 80


============================================================
*/

int evaluate_predicate(
        Tuple tuple,
        Predicate predicate
);





/*
============================================================

Selection


Relational Algebra:

σ condition(Relation)


============================================================
*/

Relation selection(
        Relation relation,
        Predicate predicate
);





/*
============================================================

Projection


Relational Algebra:

π attribute(Relation)


============================================================
*/

Relation projection(
        Relation relation,
        char* column
);






/*
============================================================

Execute Query

Legacy interface.

============================================================
*/

Relation execute_query(
        Relation relation,
        Query query
);



/*
============================================================

NEW

Execute AST


The future database engine
will use this.

============================================================
*/

Relation execute_ast(
        Relation relation,
        ASTNode* root
);
#ifndef EXECUTOR_H
#define EXECUTOR_H


#include "relation.h"
#include "parser.h"
#include "ast.h"
#include "expression.h"




Relation execute_query(
        Relation relation,
        Query query
);




Relation execute_ast(
        Relation relation,
        ASTNode* root
);




Relation execute_expression(
        Relation relation,
        ExpressionNode* expression
);




#endif


#endif