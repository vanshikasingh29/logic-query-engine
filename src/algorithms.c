/*
============================================================

Logic Query Engine

File:
algorithms.c

Purpose:

Implementation of recursive algorithms demonstrating
the connection between mathematical definitions and
executable procedures.

============================================================
*/

#include "../include/algorithms.h"


/*
============================================================

Factorial

Recursive mathematical definition:

f(0) = 1

f(n) = n * f(n - 1)

============================================================
*/

long long factorial_recursive(
        int n
)
{
    if(n < 0)
    {
        return 0;
    }

    if(n == 0)
    {
        return 1;
    }

    return (long long)n *
           factorial_recursive(n - 1);
}


/*
============================================================

Fibonacci

Recursive mathematical definition:

F(0) = 0

F(1) = 1

F(n) = F(n-1) + F(n-2)

============================================================
*/

long long fibonacci_recursive(
        int n
)
{
    if(n < 0)
    {
        return 0;
    }

    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        return 1;
    }

    return fibonacci_recursive(n - 1)
         + fibonacci_recursive(n - 2);
}


/*
============================================================

Recursive Binary Search

Invariant:

If the target exists in the original sorted array,
it must remain within the current search interval.

============================================================
*/

int binary_search_recursive(
        const int array[],
        int left,
        int right,
        int target
)
{
    if(left > right)
    {
        return -1;
    }

    int middle =
        left + (right - left) / 2;


    if(array[middle] == target)
    {
        return middle;
    }


    if(target < array[middle])
    {
        return binary_search_recursive(
            array,
            left,
            middle - 1,
            target
        );
    }


    return binary_search_recursive(
        array,
        middle + 1,
        right,
        target
    );
}


/*
============================================================

Recursive Sum

Mathematical recurrence:

S(0) = 0

S(n) = a[n-1] + S(n-1)

============================================================
*/

long long recursive_sum(
        const int array[],
        int size
)
{
    if(size <= 0)
    {
        return 0;
    }

    return (long long)array[size - 1]
         + recursive_sum(
                array,
                size - 1
           );
}