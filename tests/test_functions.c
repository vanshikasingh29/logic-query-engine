/*
============================================================

Logic Query Engine

File:

test_functions.c

Purpose:

Automated tests for the mathematical function module.

Tests:

1. Function construction
2. Function application
3. Injectivity
4. Non-injectivity
5. Surjectivity
6. Bijectivity
7. Function composition
8. Invalid composition

============================================================
*/

#include <stdio.h>

#include "../include/function.h"


int tests_passed = 0;
int tests_failed = 0;


/*
============================================================

Simple Test Framework

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

Test Function Construction

============================================================
*/

void test_function_creation(void)
{
    Function function =
        create_function();

    assert_test(
        function.size == 0,
        "Function creation"
    );
}


/*
============================================================

Test Function Application

Example:

    f(1) = 10
    f(2) = 20

============================================================
*/

void test_function_application(void)
{
    Function function =
        create_function();

    add_mapping(
        &function,
        1,
        10
    );

    add_mapping(
        &function,
        2,
        20
    );

    int output = 0;

    int found =
        apply_function(
            &function,
            2,
            &output
        );

    assert_test(
        found == 1 && output == 20,
        "Function application"
    );
}


/*
============================================================

Test Injectivity

f:

1 -> 10
2 -> 20
3 -> 30

============================================================
*/

void test_injective(void)
{
    Function function =
        create_function();

    add_mapping(&function, 1, 10);
    add_mapping(&function, 2, 20);
    add_mapping(&function, 3, 30);

    assert_test(
        is_injective(&function) == 1,
        "Injective function"
    );
}


/*
============================================================

Test Non-Injectivity

f:

1 -> 10
2 -> 10

Two distinct inputs produce the same output.

============================================================
*/

void test_non_injective(void)
{
    Function function =
        create_function();

    add_mapping(&function, 1, 10);
    add_mapping(&function, 2, 10);

    assert_test(
        is_injective(&function) == 0,
        "Non-injective function"
    );
}


/*
============================================================

Test Surjectivity

For the finite representation used here,
the codomain is the represented output set.

============================================================
*/

void test_surjective(void)
{
    Function function =
        create_function();

    add_mapping(&function, 1, 10);
    add_mapping(&function, 2, 20);
    add_mapping(&function, 3, 30);

    assert_test(
        is_surjective(&function) == 1,
        "Surjective function"
    );
}


/*
============================================================

Test Bijectivity

A function that is both injective and surjective.

============================================================
*/

void test_bijective(void)
{
    Function function =
        create_function();

    add_mapping(&function, 1, 10);
    add_mapping(&function, 2, 20);
    add_mapping(&function, 3, 30);

    assert_test(
        is_bijective(&function) == 1,
        "Bijective function"
    );
}


/*
============================================================

Test Composition

f:

1 -> 2
2 -> 3
3 -> 4

g:

2 -> 20
3 -> 30
4 -> 40

Therefore:

g o f:

1 -> 20
2 -> 30
3 -> 40

============================================================
*/

void test_composition(void)
{
    Function first =
        create_function();

    add_mapping(&first, 1, 2);
    add_mapping(&first, 2, 3);
    add_mapping(&first, 3, 4);


    Function second =
        create_function();

    add_mapping(&second, 2, 20);
    add_mapping(&second, 3, 30);
    add_mapping(&second, 4, 40);


    Function result;


    int success =
        compose_functions(
            &first,
            &second,
            &result
        );


    int output = 0;

    int found =
        apply_function(
            &result,
            2,
            &output
        );


    assert_test(
        success == 1 &&
        found == 1 &&
        output == 30 &&
        result.size == 3,
        "Function composition"
    );
}


/*
============================================================

Test Invalid Composition

f:

1 -> 2

g:

3 -> 30

The value 2 is not in the domain of g.

Therefore g o f is undefined.

============================================================
*/

void test_invalid_composition(void)
{
    Function first =
        create_function();

    add_mapping(
        &first,
        1,
        2
    );


    Function second =
        create_function();

    add_mapping(
        &second,
        3,
        30
    );


    Function result;


    int success =
        compose_functions(
            &first,
            &second,
            &result
        );


    assert_test(
        success == 0,
        "Invalid composition detection"
    );
}


/*
============================================================

Main Test Runner

============================================================
*/

int main(void)
{
    printf(
        "\nLogic Query Engine - Function Tests\n"
    );

    printf(
        "===================================\n\n"
    );


    test_function_creation();

    test_function_application();

    test_injective();

    test_non_injective();

    test_surjective();

    test_bijective();

    test_composition();

    test_invalid_composition();


    printf(
        "\nResults\n"
    );

    printf(
        "----------------\n"
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
            "\nAll function tests passed.\n"
        );

        return 0;
    }


    printf(
        "\nSome function tests failed.\n"
    );

    return 1;
}