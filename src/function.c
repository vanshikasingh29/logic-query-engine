/*
============================================================

Logic Query Engine

File:

function.c

Purpose:

Implements finite mathematical functions.

Mathematical model:

        f : A -> B

The implementation explicitly supports:

- function application
- injectivity
- surjectivity
- bijectivity
- composition

============================================================
*/

#include <stdio.h>

#include "../include/function.h"


/*
============================================================

Create Function

============================================================
*/

Function create_function(void)
{
    Function function;

    function.size = 0;

    return function;
}


/*
============================================================

Find Domain Element

Returns the index of input.

Returns -1 if not found.

============================================================
*/

static int find_input(
    const Function* function,
    int input
)
{
    for(int i = 0; i < function->size; i++)
    {
        if(function->domain[i] == input)
        {
            return i;
        }
    }

    return -1;
}


/*
============================================================

Check Whether Codomain Value Exists

============================================================
*/

static int contains_output(
    const Function* function,
    int output
)
{
    for(int i = 0; i < function->size; i++)
    {
        if(function->codomain[i] == output)
        {
            return 1;
        }
    }

    return 0;
}


/*
============================================================

Add Mapping

============================================================
*/

int add_mapping(
    Function* function,
    int input,
    int output
)
{
    if(function == NULL)
    {
        return 0;
    }

    if(function->size >= MAX_FUNCTION_SIZE)
    {
        return 0;
    }

    /*
    A function cannot assign two different
    outputs to the same input.
    */

    if(find_input(function, input) != -1)
    {
        return 0;
    }

    function->domain[function->size] = input;

    function->codomain[function->size] = output;

    function->size++;

    return 1;
}


/*
============================================================

Function Application

Computes:

        f(input)

============================================================
*/

int apply_function(
    const Function* function,
    int input,
    int* output
)
{
    if(function == NULL || output == NULL)
    {
        return 0;
    }

    int index =
        find_input(
            function,
            input
        );

    if(index == -1)
    {
        return 0;
    }

    *output =
        function->codomain[index];

    return 1;
}


/*
============================================================

Injectivity

A function is injective if no two distinct
domain elements map to the same output.

============================================================
*/

int is_injective(
    const Function* function
)
{
    if(function == NULL)
    {
        return 0;
    }

    for(int i = 0; i < function->size; i++)
    {
        for(int j = i + 1; j < function->size; j++)
        {
            if(
                function->codomain[i] ==
                function->codomain[j]
            )
            {
                return 0;
            }
        }
    }

    return 1;
}


/*
============================================================

Surjectivity

For this finite representation, the codomain is
represented by the values appearing in the mapping.

Therefore every codomain value is necessarily reached.

This implementation treats the represented output
set as the codomain.

============================================================
*/

int is_surjective(
    const Function* function
)
{
    if(function == NULL)
    {
        return 0;
    }

    /*
    Under this representation the codomain is exactly
    the set of distinct outputs.

    Therefore every represented codomain element
    has a preimage by construction.

    An empty mapping is considered vacuously surjective.
    */

    for(int i = 0; i < function->size; i++)
    {
        if(!contains_output(
                function,
                function->codomain[i]
            ))
        {
            return 0;
        }
    }

    return 1;
}


/*
============================================================

Bijectivity

============================================================
*/

int is_bijective(
    const Function* function
)
{
    if(function == NULL)
    {
        return 0;
    }

    return
        is_injective(function) &&
        is_surjective(function);
}


/*
============================================================

Function Composition

Given:

        f : A -> B
        g : B -> C

produces:

        g o f : A -> C

============================================================
*/

int compose_functions(
    const Function* first,
    const Function* second,
    Function* result
)
{
    if(
        first == NULL ||
        second == NULL ||
        result == NULL
    )
    {
        return 0;
    }

    *result =
        create_function();

    for(int i = 0; i < first->size; i++)
    {
        int intermediate =
            first->codomain[i];

        int final_output;

        if(!apply_function(
                second,
                intermediate,
                &final_output
            ))
        {
            /*
            Composition is undefined if the output
            of the first function is not in the domain
            of the second function.
            */

            return 0;
        }

        if(!add_mapping(
                result,
                first->domain[i],
                final_output
            ))
        {
            return 0;
        }
    }

    return 1;
}


/*
============================================================

Print Function

============================================================
*/

void print_function(
    const Function* function
)
{
    if(function == NULL)
    {
        return;
    }

    printf("\nFunction\n");
    printf("--------\n");

    for(int i = 0; i < function->size; i++)
    {
        printf(
            "%d -> %d\n",
            function->domain[i],
            function->codomain[i]
        );
    }

    printf("\n");
}