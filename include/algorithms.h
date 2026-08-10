/*
============================================================

Logic Query Engine

File:
algorithms.h

Purpose:

Defines reusable algorithmic primitives used to
demonstrate the relationship between:

- mathematical functions
- recursion
- recursive data processing
- algorithm correctness
- complexity analysis

These algorithms are intentionally independent
of the database execution engine.

============================================================
*/

#ifndef ALGORITHMS_H
#define ALGORITHMS_H


/*
============================================================

Factorial

Mathematical definition:

0! = 1

n! = n * (n - 1)!     for n > 0

Complexity:

Time:  O(n)
Space: O(n) recursive stack

Returns:

- factorial result for n >= 0
- 0 for invalid negative input

============================================================
*/

long long factorial_recursive(
        int n
);


/*
============================================================

Fibonacci

Mathematical definition:

F(0) = 0
F(1) = 1

F(n) = F(n-1) + F(n-2)

This implementation is intentionally recursive
to demonstrate the direct correspondence between
a mathematical recurrence and an algorithm.

Complexity:

Time:  O(2^n) approximately
Space: O(n)

============================================================
*/

long long fibonacci_recursive(
        int n
);


/*
============================================================

Binary Search

Recursively searches a sorted integer array.

Returns:

- index of target if found
- -1 otherwise

Complexity:

Time:  O(log n)
Space: O(log n) due to recursion

============================================================
*/

int binary_search_recursive(
        const int array[],
        int left,
        int right,
        int target
);


/*
============================================================

Array Sum

Recursively computes:

a[0] + a[1] + ... + a[n-1]

Complexity:

Time:  O(n)
Space: O(n)

============================================================
*/

long long recursive_sum(
        const int array[],
        int size
);


#endif
