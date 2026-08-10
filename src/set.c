/*
============================================================

Logic Query Engine

File:

set.c

Purpose:

Implements mathematical set operations over database
relations.

Supported operations:

    Union
    Intersection
    Difference
    Distinct

Mathematical model:

Relation = finite set of tuples

Therefore:

    A ∪ B
    A ∩ B
    A - B

can be implemented as operations over tuples.

============================================================
*/

#include <string.h>

#include "../include/set.h"


/*
============================================================

Tuple Membership

Checks whether an identical tuple exists in a relation.

Two tuples are considered equal when both:

    name
    grade

are equal.

============================================================
*/

int tuple_exists(
        Relation relation,
        Tuple tuple
)
{
    for(int i = 0;
        i < relation.row_count;
        i++)
    {
        if(
            strcmp(
                relation.rows[i].name,
                tuple.name
            ) == 0
            &&
            relation.rows[i].grade == tuple.grade
        )
        {
            return 1;
        }
    }

    return 0;
}


/*
============================================================

Set Union

A ∪ B

Algorithm:

1. Add every distinct tuple from A.
2. Add every tuple from B that is not already present.

This guarantees that duplicates are removed.

============================================================
*/

Relation relation_union(
        Relation left,
        Relation right
)
{
    Relation result =
        create_relation(
            "Union Result"
        );


    /*
    Add tuples from the left relation.
    */

    for(int i = 0;
        i < left.row_count;
        i++)
    {
        if(
            !tuple_exists(
                result,
                left.rows[i]
            )
        )
        {
            add_tuple(
                &result,
                left.rows[i].name,
                left.rows[i].grade
            );
        }
    }


    /*
    Add tuples from the right relation.

    Duplicate tuples are ignored.
    */

    for(int i = 0;
        i < right.row_count;
        i++)
    {
        if(
            !tuple_exists(
                result,
                right.rows[i]
            )
        )
        {
            add_tuple(
                &result,
                right.rows[i].name,
                right.rows[i].grade
            );
        }
    }


    return result;
}


/*
============================================================

Set Intersection

A ∩ B

Only tuples appearing in BOTH relations are returned.

============================================================
*/

Relation relation_intersection(
        Relation left,
        Relation right
)
{
    Relation result =
        create_relation(
            "Intersection Result"
        );


    for(int i = 0;
        i < left.row_count;
        i++)
    {
        if(
            tuple_exists(
                right,
                left.rows[i]
            )
        )
        {
            if(
                !tuple_exists(
                    result,
                    left.rows[i]
                )
            )
            {
                add_tuple(
                    &result,
                    left.rows[i].name,
                    left.rows[i].grade
                );
            }
        }
    }


    return result;
}


/*
============================================================

Set Difference

A - B

Returns tuples that exist in A but not in B.

============================================================
*/

Relation relation_difference(
        Relation left,
        Relation right
)
{
    Relation result =
        create_relation(
            "Difference Result"
        );


    for(int i = 0;
        i < left.row_count;
        i++)
    {
        if(
            !tuple_exists(
                right,
                left.rows[i]
            )
        )
        {
            if(
                !tuple_exists(
                    result,
                    left.rows[i]
                )
            )
            {
                add_tuple(
                    &result,
                    left.rows[i].name,
                    left.rows[i].grade
                );
            }
        }
    }


    return result;
}


/*
============================================================

Distinct

Removes duplicate tuples from a relation.

Mathematical interpretation:

Convert a multiset-like collection into a set.

============================================================
*/

Relation distinct_relation(
        Relation relation
)
{
    Relation result =
        create_relation(
            "Distinct Result"
        );


    for(int i = 0;
        i < relation.row_count;
        i++)
    {
        if(
            !tuple_exists(
                result,
                relation.rows[i]
            )
        )
        {
            add_tuple(
                &result,
                relation.rows[i].name,
                relation.rows[i].grade
            );
        }
    }


    return result;
}