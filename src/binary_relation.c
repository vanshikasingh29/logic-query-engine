/*
============================================================

Logic Query Engine

File:
binary_relation.c

Purpose:
Implementation of finite binary relations.

Mathematical model:

R ⊆ A × A

The implementation explicitly evaluates the
properties of a finite relation.

============================================================
*/

#include <stdio.h>

#include "../include/binary_relation.h"


/*
============================================================

Internal Helper

Checks whether an element belongs to the domain.

============================================================
*/

static int contains_element(
    const BinaryRelation* relation,
    int value
)
{
    for(int i = 0;
        i < relation->element_count;
        i++)
    {
        if(relation->elements[i] == value)
        {
            return 1;
        }
    }

    return 0;
}


/*
============================================================

Internal Helper

Checks whether an ordered pair already exists.

============================================================
*/

static int pair_index(
    const BinaryRelation* relation,
    int first,
    int second
)
{
    for(int i = 0;
        i < relation->pair_count;
        i++)
    {
        if(
            relation->pairs[i].first == first &&
            relation->pairs[i].second == second
        )
        {
            return i;
        }
    }

    return -1;
}


/*
============================================================

Create Binary Relation

============================================================
*/

BinaryRelation create_binary_relation(
    const int* elements,
    int element_count
)
{
    BinaryRelation relation;

    relation.element_count = 0;
    relation.pair_count = 0;


    if(elements == NULL)
    {
        return relation;
    }


    if(element_count < 0 ||
       element_count > MAX_RELATION_ELEMENTS)
    {
        return relation;
    }


    for(int i = 0;
        i < element_count;
        i++)
    {
        /*
        Prevent duplicate domain elements.
        */

        if(!contains_element(
            &relation,
            elements[i]
        ))
        {
            relation.elements[
                relation.element_count++
            ] = elements[i];
        }
    }


    return relation;
}


/*
============================================================

Add Ordered Pair

============================================================
*/

int add_pair(
    BinaryRelation* relation,
    int first,
    int second
)
{
    if(relation == NULL)
    {
        return 0;
    }


    /*
    Both elements must belong to
    the relation's domain.
    */

    if(!contains_element(
        relation,
        first
    ))
    {
        return 0;
    }


    if(!contains_element(
        relation,
        second
    ))
    {
        return 0;
    }


    /*
    Prevent duplicate ordered pairs.
    */

    if(pair_index(
        relation,
        first,
        second
    ) != -1)
    {
        return 0;
    }


    if(
        relation->pair_count >=
        MAX_RELATION_PAIRS
    )
    {
        return 0;
    }


    relation->pairs[
        relation->pair_count
    ].first = first;


    relation->pairs[
        relation->pair_count
    ].second = second;


    relation->pair_count++;


    return 1;
}


/*
============================================================

Pair Membership

============================================================
*/

int contains_pair(
    const BinaryRelation* relation,
    int first,
    int second
)
{
    if(relation == NULL)
    {
        return 0;
    }


    return pair_index(
        relation,
        first,
        second
    ) != -1;
}


/*
============================================================

Reflexivity

Definition:

∀a ∈ A,

(a,a) ∈ R

============================================================
*/

int is_reflexive(
    const BinaryRelation* relation
)
{
    if(relation == NULL)
    {
        return 0;
    }


    for(int i = 0;
        i < relation->element_count;
        i++)
    {
        int element =
            relation->elements[i];


        if(!contains_pair(
            relation,
            element,
            element
        ))
        {
            return 0;
        }
    }


    return 1;
}


/*
============================================================

Symmetry

Definition:

(a,b) ∈ R

⇒

(b,a) ∈ R

============================================================
*/

int is_symmetric(
    const BinaryRelation* relation
)
{
    if(relation == NULL)
    {
        return 0;
    }


    for(int i = 0;
        i < relation->pair_count;
        i++)
    {
        int first =
            relation->pairs[i].first;


        int second =
            relation->pairs[i].second;


        if(!contains_pair(
            relation,
            second,
            first
        ))
        {
            return 0;
        }
    }


    return 1;
}


/*
============================================================

Antisymmetry

Definition:

(a,b) ∈ R

and

(b,a) ∈ R

⇒

a = b

============================================================
*/

int is_antisymmetric(
    const BinaryRelation* relation
)
{
    if(relation == NULL)
    {
        return 0;
    }


    for(int i = 0;
        i < relation->pair_count;
        i++)
    {
        int first =
            relation->pairs[i].first;


        int second =
            relation->pairs[i].second;


        if(
            first != second &&
            contains_pair(
                relation,
                second,
                first
            )
        )
        {
            return 0;
        }
    }


    return 1;
}


/*
============================================================

Transitivity

Definition:

(a,b) ∈ R

and

(b,c) ∈ R

⇒

(a,c) ∈ R

============================================================
*/

int is_transitive(
    const BinaryRelation* relation
)
{
    if(relation == NULL)
    {
        return 0;
    }


    for(int i = 0;
        i < relation->pair_count;
        i++)
    {
        int a =
            relation->pairs[i].first;


        int b =
            relation->pairs[i].second;


        for(int j = 0;
            j < relation->pair_count;
            j++)
        {
            int second_first =
                relation->pairs[j].first;


            int c =
                relation->pairs[j].second;


            if(b == second_first)
            {
                if(!contains_pair(
                    relation,
                    a,
                    c
                ))
                {
                    return 0;
                }
            }
        }
    }


    return 1;
}


/*
============================================================

Equivalence Relation

Definition:

Reflexive
+
Symmetric
+
Transitive

============================================================
*/

int is_equivalence_relation(
    const BinaryRelation* relation
)
{
    if(relation == NULL)
    {
        return 0;
    }


    return
        is_reflexive(relation) &&
        is_symmetric(relation) &&
        is_transitive(relation);
}


/*
============================================================

Relation Composition

Given:

R ⊆ A × B

S ⊆ B × C

The composition:

R ∘ S

contains:

(a,c)

when:

(a,b) ∈ R

and

(b,c) ∈ S

============================================================
*/

BinaryRelation compose_relations(
    const BinaryRelation* first,
    const BinaryRelation* second
)
{
    BinaryRelation result;


    /*
    The composition operates over the
    domain of the first relation.
    */

    result =
        create_binary_relation(
            first->elements,
            first->element_count
        );


    if(first == NULL ||
       second == NULL)
    {
        return result;
    }


    for(int i = 0;
        i < first->pair_count;
        i++)
    {
        int a =
            first->pairs[i].first;


        int b =
            first->pairs[i].second;


        for(int j = 0;
            j < second->pair_count;
            j++)
        {
            int second_first =
                second->pairs[j].first;


            int c =
                second->pairs[j].second;


            if(b == second_first)
            {
                add_pair(
                    &result,
                    a,
                    c
                );
            }
        }
    }


    return result;
}


/*
============================================================

Print Relation

============================================================
*/

void print_binary_relation(
    const BinaryRelation* relation
)
{
    if(relation == NULL)
    {
        return;
    }


    printf(
        "\nBinary Relation\n"
    );


    printf(
        "================\n"
    );


    printf(
        "Domain: { "
    );


    for(int i = 0;
        i < relation->element_count;
        i++)
    {
        printf(
            "%d",
            relation->elements[i]
        );


        if(
            i <
            relation->element_count - 1
        )
        {
            printf(", ");
        }
    }


    printf(
        " }\n"
    );


    printf(
        "Pairs: { "
    );


    for(int i = 0;
        i < relation->pair_count;
        i++)
    {
        printf(
            "(%d,%d)",
            relation->pairs[i].first,
            relation->pairs[i].second
        );


        if(
            i <
            relation->pair_count - 1
        )
        {
            printf(", ");
        }
    }


    printf(
        " }\n"
    );
}