/*
============================================================

Logic Query Engine

File:

function.h

Purpose:

Defines finite mathematical functions.

A function is represented as a mapping:

        f : A -> B

where every element of the finite domain A maps
to exactly one element of the codomain B.

The module supports:

- function creation
- function application
- injectivity
- surjectivity
- bijectivity
- function composition

This provides a direct computational representation
of the mathematical concepts studied in Module 1.

============================================================
*/

#ifndef FUNCTION_H
#define FUNCTION_H


#define MAX_FUNCTION_SIZE 100


/*
============================================================

Finite Function

Represents:

        f : A -> B

domain[i] maps to codomain[i].

Therefore:

        f(domain[i]) = codomain[i]

The domain values must be unique.

============================================================
*/

typedef struct
{
    int domain[MAX_FUNCTION_SIZE];

    int codomain[MAX_FUNCTION_SIZE];

    int size;

} Function;


/*
============================================================

Function Construction

Creates an empty finite function.

============================================================
*/

Function create_function(void);


/*
============================================================

Add Mapping

Adds:

        input -> output

to the function.

Returns:

    1 if successful
    0 if the mapping is invalid

A domain element cannot be mapped twice.

============================================================
*/

int add_mapping(
    Function* function,
    int input,
    int output
);


/*
============================================================

Function Application

Computes:

        f(input)

Returns:

    1 if the input exists
    0 otherwise

The result is written to output.

============================================================
*/

int apply_function(
    const Function* function,
    int input,
    int* output
);


/*
============================================================

Injectivity

A function is injective when:

    f(a) = f(b) => a = b

============================================================
*/

int is_injective(
    const Function* function
);


/*
============================================================

Surjectivity

A function is surjective when every element
of the codomain is reached.

For this finite representation, the codomain
is the set of distinct values appearing
in the mapping.

============================================================
*/

int is_surjective(
    const Function* function
);


/*
============================================================

Bijectivity

A function is bijective when it is both:

    injective
    and
    surjective

============================================================
*/

int is_bijective(
    const Function* function
);


/*
============================================================

Function Composition

Given:

    f : A -> B
    g : B -> C

produces:

    g o f : A -> C

such that:

    (g o f)(x) = g(f(x))

Returns:

    1 if composition succeeds
    0 otherwise

============================================================
*/

int compose_functions(
    const Function* first,
    const Function* second,
    Function* result
);


/*
============================================================

Debug Output

============================================================
*/

void print_function(
    const Function* function
);


#endif