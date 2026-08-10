/*
============================================================

Logic Query Engine

File:
test_algorithms.c

Purpose:

Automated validation of recursive algorithms.

The tests verify:

1. factorial base and recursive cases
2. Fibonacci recurrence
3. recursive summation
4. binary search correctness
5. binary search failure behaviour

============================================================
*/

#include <stdio.h>

#include "../include/algorithms.h"


static int tests_passed = 0;
static int tests_failed = 0;


/*
============================================================

Test Assertion

============================================================
*/

static void assert_test(
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

Factorial Tests

============================================================
*/

static void test_factorial(void)
{
    assert_test(
        factorial_recursive(0) == 1,
        "Factorial base case"
    );

    assert_test(
        factorial_recursive(5) == 120,
        "Factorial recursive case"
    );

    assert_test(
        factorial_recursive(10) == 3628800,
        "Factorial larger input"
    );
}


/*
============================================================

Fibonacci Tests

============================================================
*/

static void test_fibonacci(void)
{
    assert_test(
        fibonacci_recursive(0) == 0,
        "Fibonacci F(0)"
    );

    assert_test(
        fibonacci_recursive(1) == 1,
        "Fibonacci F(1)"
    );

    assert_test(
        fibonacci_recursive(10) == 55,
        "Fibonacci recurrence"
    );
}


/*
============================================================

Recursive Sum Tests

============================================================
*/

static void test_recursive_sum(void)
{
    int values[] =
    {
        1,
        2,
        3,
        4,
        5
    };


    assert_test(
        recursive_sum(values, 5) == 15,
        "Recursive array sum"
    );


    assert_test(
        recursive_sum(values, 0) == 0,
        "Recursive sum empty input"
    );
}


/*
============================================================

Binary Search Tests

============================================================
*/

static void test_binary_search(void)
{
    int values[] =
    {
        10,
        20,
        30,
        40,
        50,
        60,
        70
    };


    int result =
        binary_search_recursive(
            values,
            0,
            6,
            40
        );


    assert_test(
        result == 3,
        "Binary search successful lookup"
    );


    result =
        binary_search_recursive(
            values,
            0,
            6,
            99
        );


    assert_test(
        result == -1,
        "Binary search unsuccessful lookup"
    );
}


/*
============================================================

Test Runner

============================================================
*/

int main(void)
{
    printf(
        "\nLogic Query Engine - Algorithm Tests\n"
    );

    printf(
        "=====================================\n\n"
    );


    test_factorial();

    test_fibonacci();

    test_recursive_sum();

    test_binary_search();


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
            "\nAll algorithm tests passed.\n"
        );

        return 0;
    }


    printf(
        "\nSome algorithm tests failed.\n"
    );

    return 1;
}