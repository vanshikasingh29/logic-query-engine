/*
============================================================

Logic Query Engine

File:
binary_relation.h

Purpose:
Finite binary relations over a finite integer domain.

Mathematical model:

A binary relation R on a set A is a subset of:

A × A

Example:

A = {1, 2, 3}

R = {
    (1,1),
    (1,2),
    (2,2),
    (3,3)
}

This module provides operations for analysing
the mathematical properties of relations.

Supported properties:

- Reflexive
- Symmetric
- Antisymmetric
- Transitive
- Equivalence relation

============================================================
*/

#ifndef BINARY_RELATION_H
#define BINARY_RELATION_H

#define MAX_RELATION_ELEMENTS 100
#define MAX_RELATION_PAIRS 1000


/*
============================================================

Ordered Pair

Represents:

(a,b)

============================================================
*/

typedef struct
{
    int first;
    int second;

} OrderedPair;


/*
============================================================

Binary Relation

A relation is represented as:

R ⊆ A × A

where:

elements[] represents the finite domain A

pairs[] represents the ordered pairs belonging
to the relation R.

============================================================
*/

typedef struct
{
    int elements[MAX_RELATION_ELEMENTS];

    int element_count;

    OrderedPair pairs[MAX_RELATION_PAIRS];

    int pair_count;

} BinaryRelation;


/*
============================================================

Construction

============================================================
*/

/*
Creates an empty relation over a supplied finite domain.
*/
BinaryRelation create_binary_relation(
    const int* elements,
    int element_count
);


/*
Adds the ordered pair:

(first, second)

to the relation.

Returns:

1 if inserted
0 if invalid or already present
*/
int add_pair(
    BinaryRelation* relation,
    int first,
    int second
);


/*
============================================================

Membership

============================================================
*/

/*
Tests whether:

(first, second) ∈ R
*/
int contains_pair(
    const BinaryRelation* relation,
    int first,
    int second
);


/*
============================================================

Relation Properties

============================================================
*/

/*
R is reflexive iff:

∀a ∈ A, (a,a) ∈ R
*/
int is_reflexive(
    const BinaryRelation* relation
);


/*
R is symmetric iff:

∀a,b ∈ A,

(a,b) ∈ R
    ⇒
(b,a) ∈ R
*/
int is_symmetric(
    const BinaryRelation* relation
);


/*
R is antisymmetric iff:

∀a,b ∈ A,

(a,b) ∈ R ∧ (b,a) ∈ R
    ⇒
a = b
*/
int is_antisymmetric(
    const BinaryRelation* relation
);


/*
R is transitive iff:

∀a,b,c ∈ A,

(a,b) ∈ R ∧ (b,c) ∈ R
    ⇒
(a,c) ∈ R
*/
int is_transitive(
    const BinaryRelation* relation
);


/*
An equivalence relation is:

Reflexive
+
Symmetric
+
Transitive
*/
int is_equivalence_relation(
    const BinaryRelation* relation
);


/*
============================================================

Relation Composition

For relations R and S:

R ∘ S

contains:

(a,c)

whenever there exists b such that:

(a,b) ∈ S

and

(b,c) ∈ R

============================================================
*/

BinaryRelation compose_relations(
    const BinaryRelation* first,
    const BinaryRelation* second
);


/*
============================================================

Output

============================================================
*/

void print_binary_relation(
    const BinaryRelation* relation
);

#endif