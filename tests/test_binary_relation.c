/*
============================================================

Logic Query Engine

File:
test_binary_relation.c

Purpose:
Automated tests for the finite binary relation engine.

Tests:

1. Relation construction
2. Pair membership
3. Reflexivity
4. Symmetry
5. Antisymmetry
6. Transitivity
7. Equivalence relation
8. Relation composition

============================================================
*/

#include <stdio.h>

#include "../include/binary_relation.h"


int tests_passed = 0;
int tests_failed = 0;


/*
============================================================

Test Assertion

============================================================
*/

void assert_test(
    int condition,
    const char* test_name
)
{
    if(condition)
    {
        printf(
            "[PASS] %s\n",
            test_name
        );

        tests_passed++;
    }
    else
    {
        printf(
            "[FAIL] %s\n",
            test_name
        );

        tests_failed++;
    }
}


/*
============================================================

Test Relation Construction

============================================================
*/

void test_relation_creation()
{
    int domain[] =
    {
        1,
        2,
        3
    };


    BinaryRelation relation =
        create_binary_relation(
            domain,
            3
        );


    assert_test(
        relation.element_count == 3,
        "Binary relation creation"
    );
}


/*
============================================================

Test Pair Membership

============================================================
*/

void test_pair_membership()
{
    int domain[] =
    {
        1,
        2,
        3
    };


    BinaryRelation relation =
        create_binary_relation(
            domain,
            3
        );


    add_pair(
        &relation,
        1,
        2
    );


    assert_test(
        contains_pair(
            &relation,
            1,
            2
        ) == 1,
        "Ordered pair membership"
    );


    assert_test(
        contains_pair(
            &relation,
            2,
            1
        ) == 0,
        "Ordered pair direction"
    );
}


/*
============================================================

Test Reflexivity

R = {

(1,1)
(2,2)
(3,3)

}

============================================================
*/

void test_reflexivity()
{
    int domain[] =
    {
        1,
        2,
        3
    };


    BinaryRelation relation =
        create_binary_relation(
            domain,
            3
        );


    add_pair(&relation, 1, 1);
    add_pair(&relation, 2, 2);
    add_pair(&relation, 3, 3);


    assert_test(
        is_reflexive(&relation) == 1,
        "Reflexive relation"
    );
}


/*
============================================================

Test Symmetry

R = {

(1,2)
(2,1)

}

============================================================
*/

void test_symmetry()
{
    int domain[] =
    {
        1,
        2
    };


    BinaryRelation relation =
        create_binary_relation(
            domain,
            2
        );


    add_pair(&relation, 1, 2);
    add_pair(&relation, 2, 1);


    assert_test(
        is_symmetric(&relation) == 1,
        "Symmetric relation"
    );
}


/*
============================================================

Test Antisymmetry

R = {

(1,1)
(2,2)
(1,2)

}

============================================================
*/

void test_antisymmetry()
{
    int domain[] =
    {
        1,
        2
    };


    BinaryRelation relation =
        create_binary_relation(
            domain,
            2
        );


    add_pair(&relation, 1, 1);
    add_pair(&relation, 2, 2);
    add_pair(&relation, 1, 2);


    assert_test(
        is_antisymmetric(&relation) == 1,
        "Antisymmetric relation"
    );
}


/*
============================================================

Test Transitivity

R = {

(1,1)
(2,2)
(1,2)

}

Since:

(1,2) and (2,2)

imply:

(1,2)

the relation is transitive.

============================================================
*/

void test_transitivity()
{
    int domain[] =
    {
        1,
        2
    };


    BinaryRelation relation =
        create_binary_relation(
            domain,
            2
        );


    add_pair(&relation, 1, 1);
    add_pair(&relation, 2, 2);
    add_pair(&relation, 1, 2);


    assert_test(
        is_transitive(&relation) == 1,
        "Transitive relation"
    );
}


/*
============================================================

Test Equivalence Relation

Equality over:

{1,2,3}

============================================================
*/

void test_equivalence_relation()
{
    int domain[] =
    {
        1,
        2,
        3
    };


    BinaryRelation relation =
        create_binary_relation(
            domain,
            3
        );


    add_pair(&relation, 1, 1);
    add_pair(&relation, 2, 2);
    add_pair(&relation, 3, 3);


    assert_test(
        is_equivalence_relation(
            &relation
        ) == 1,
        "Equivalence relation"
    );
}


/*
============================================================

Test Relation Composition

R:

(1,2)

S:

(2,3)

Therefore:

R ∘ S

contains:

(1,3)

============================================================
*/

void test_composition()
{
    int domain[] =
    {
        1,
        2,
        3
    };


    BinaryRelation first =
        create_binary_relation(
            domain,
            3
        );


    BinaryRelation second =
        create_binary_relation(
            domain,
            3
        );


    add_pair(
        &first,
        1,
        2
    );


    add_pair(
        &second,
        2,
        3
    );


    BinaryRelation result =
        compose_relations(
            &first,
            &second
        );


    assert_test(
        contains_pair(
            &result,
            1,
            3
        ) == 1,
        "Relation composition"
    );
}


/*
============================================================

Test Runner

============================================================
*/

int main()
{
    printf(
        "\n"
    );

    printf(
        "Logic Query Engine - Binary Relation Tests\n"
    );

    printf(
        "==========================================\n\n"
    );


    test_relation_creation();

    test_pair_membership();

    test_reflexivity();

    test_symmetry();

    test_antisymmetry();

    test_transitivity();

    test_equivalence_relation();

    test_composition();


    printf(
        "\nResults\n"
    );

    printf(
        "-------\n"
    );

    printf(
        "Passed: %d\n",
        tests_passed
    );

    printf(
        "Failed: %d\n",
        tests_failed
    );


    if(tests_failed == 0)
    {
        printf(
            "\nAll binary relation tests passed.\n"
        );

        return 0;
    }


    printf(
        "\nSome binary relation tests failed.\n"
    );


    return 1;
}