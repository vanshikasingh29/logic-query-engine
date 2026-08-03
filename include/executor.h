/*
============================================================

Logic Query Engine

File:

executor.h


Purpose:

Defines the query execution layer.

The executor transforms:

Query

+

Relation

into:

Result Relation


This represents relational algebra execution.


============================================================
*/


#ifndef EXECUTOR_H
#define EXECUTOR_H


#include "relation.h"

#include "parser.h"





/*
============================================================

Predicate Evaluation


Checks whether a tuple satisfies
a logical condition.


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

Selection Operation


Relational Algebra:


σ condition(Relation)


Filters tuples.


============================================================
*/


Relation selection(
        Relation relation,
        Predicate predicate
);





/*
============================================================

Projection Operation


Relational Algebra:


π attribute(Relation)


Chooses columns.


============================================================
*/


Relation projection(
        Relation relation,
        char* column
);






/*
============================================================

Execute Query


Complete pipeline:

Query

↓

Selection

↓

Projection

↓

Result


============================================================
*/


Relation execute_query(
        Relation relation,
        Query query
);




#endif