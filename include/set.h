/*
============================================================

Logic Query Engine

File:

set.h

Purpose:

Defines set operations over relations.

Mathematical foundation:

A database relation can be modelled as a finite set
of tuples.

This module provides operations corresponding to
fundamental set-theoretic operations:

    A ∪ B    Union
    A ∩ B    Intersection
    A - B    Difference

The implementation preserves set semantics by preventing
duplicate tuples from appearing in results.

============================================================
*/

#ifndef SET_H
#define SET_H

#include "relation.h"


/*
============================================================

Tuple Membership

Determines whether a tuple exists within a relation.

Mathematical definition:

t ∈ R

============================================================
*/

int tuple_exists(
        Relation relation,
        Tuple tuple
);


/*
============================================================

Set Union

Mathematical definition:

A ∪ B

Contains every distinct tuple appearing in either
relation.

============================================================
*/

Relation relation_union(
        Relation left,
        Relation right
);


/*
============================================================

Set Intersection

Mathematical definition:

A ∩ B

Contains tuples appearing in both relations.

============================================================
*/

Relation relation_intersection(
        Relation left,
        Relation right
);


/*
============================================================

Set Difference

Mathematical definition:

A - B

Contains tuples appearing in A but not B.

============================================================
*/

Relation relation_difference(
        Relation left,
        Relation right
);


/*
============================================================

Duplicate Removal

Converts a relation into a set-like representation
by removing duplicate tuples.

============================================================
*/

Relation distinct_relation(
        Relation relation
);

#endif