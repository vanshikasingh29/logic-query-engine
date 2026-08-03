/*
============================================================

Logic Query Engine

File:

relation.h


Purpose:

Defines the mathematical relation model.

A database table is represented as a relation:

Relation = Set of Tuples


This file defines:

- attributes
- tuples
- relations


============================================================
*/


#ifndef RELATION_H
#define RELATION_H


#define MAX_NAME_LENGTH 50

#define MAX_ROWS 100



/*
============================================================

Attribute Representation


Database theory:

A relation has attributes.


Example:

Student(Name, Grade)


Name and Grade are attributes.


============================================================
*/


typedef struct
{

    char name[MAX_NAME_LENGTH];


} Attribute;





/*
============================================================

Tuple Representation


A tuple represents one row.


Example:

(Alice,95)


============================================================
*/


typedef struct
{

    char name[MAX_NAME_LENGTH];

    int grade;


} Tuple;







/*
============================================================

Relation Representation


Mathematical model:


R = {t1,t2,t3,...tn}


Implementation:

Array of tuples.


============================================================
*/


typedef struct
{

    char relation_name[MAX_NAME_LENGTH];


    Tuple rows[MAX_ROWS];


    int row_count;



} Relation;







/*
============================================================

Function Prototypes


============================================================
*/


/*
Creates an empty relation.
*/
Relation create_relation(char* name);




/*
Adds a tuple into a relation.
*/
void add_tuple(
        Relation* relation,
        char* name,
        int grade
);




/*
Displays relation contents.
*/
void print_relation(
        Relation* relation
);




#endif