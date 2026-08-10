/*
============================================================

Logic Query Engine

File:

test_sets.c

Purpose:

Tests the set-theoretic operations implemented by the
relation set module.

Operations tested:

    Membership
    Union
    Intersection
    Difference
    Distinct

============================================================
*/

#include <stdio.h>
#include <string.h>

#include "../include/relation.h"
#include "../include/set.h"


static int passed = 0;
static int failed = 0;


/*
============================================================

Test Assertion

============================================================
*/

void assert_test(
        const char* name,
        int condition
)
{
    if(condition)
    {
        printf(
            "[PASS] %s\n",
            name
        );

        passed++;
    }
    else
    {
        printf(
            "[FAIL] %s\n",
            name
        );

        failed++;
    }
}


/*
============================================================

Create Test Relation

============================================================
*/

Relation create_test_relation(
        const char* name
)
{
    Relation relation =
        create_relation(
            (char*)name
        );

    return relation;
}


/*
============================================================

Main Test Suite

============================================================
*/

int main(void)
{
    printf(
        "\n# Set Theory Test Suite\n\n"
    );


    /*
    --------------------------------------------------------
    Test relations
    --------------------------------------------------------
    */

    Relation A =
        create_test_relation("A");

    add_tuple(
        &A,
        "Alice",
        90
    );

    add_tuple(
        &A,
        "Bob",
        70
    );

    add_tuple(
        &A,
        "Charlie",
        85
    );


    Relation B =
        create_test_relation("B");

    add_tuple(
        &B,
        "Charlie",
        85
    );

    add_tuple(
        &B,
        "David",
        95
    );


    /*
    --------------------------------------------------------
    Membership
    --------------------------------------------------------
    */

    Tuple alice =
    {
        "Alice",
        90
    };


    Tuple david =
    {
        "David",
        95
    };


    assert_test(
        "Tuple membership",
        tuple_exists(A, alice)
    );


    assert_test(
        "Non-member detection",
        !tuple_exists(A, david)
    );


    /*
    --------------------------------------------------------
    Union
    --------------------------------------------------------
    */

    Relation union_result =
        relation_union(
            A,
            B
        );


    assert_test(
        "Union contains all distinct tuples",
        union_result.row_count == 4
    );


    /*
    --------------------------------------------------------
    Intersection
    --------------------------------------------------------
    */

    Relation intersection_result =
        relation_intersection(
            A,
            B
        );


    assert_test(
        "Intersection contains common tuples",
        intersection_result.row_count == 1
    );


    assert_test(
        "Intersection contains Charlie",
        tuple_exists(
            intersection_result,
            (Tuple){"Charlie", 85}
        )
    );


    /*
    --------------------------------------------------------
    Difference
    --------------------------------------------------------
    */

    Relation difference_result =
        relation_difference(
            A,
            B
        );


    assert_test(
        "Difference removes common tuples",
        difference_result.row_count == 2
    );


    assert_test(
        "Difference contains Alice",
        tuple_exists(
            difference_result,
            alice
        )
    );


    /*
    --------------------------------------------------------
    Distinct
    --------------------------------------------------------
    */

    Relation duplicates =
        create_test_relation(
            "Duplicates"
        );


    add_tuple(
        &duplicates,
        "Alice",
        90
    );


    add_tuple(
        &duplicates,
        "Alice",
        90
    );


    add_tuple(
        &duplicates,
        "Bob",
        70
    );


    Relation distinct =
        distinct_relation(
            duplicates
        );


    assert_test(
        "Distinct removes duplicates",
        distinct.row_count == 2
    );


    /*
    --------------------------------------------------------
    Results
    --------------------------------------------------------
    */

    printf(
        "\n## Results\n\n"
    );


    printf(
        "Passed: %d\n",
        passed
    );


    printf(
        "Failed: %d\n",
        failed
    );


    if(failed == 0)
    {
        printf(
            "\nAll set theory tests passed.\n"
        );

        return 0;
    }


    printf(
        "\nSome tests failed.\n"
    );

    return 1;
}