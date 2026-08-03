/*
============================================================

Logic Query Engine

File:

relation.c


Purpose:

Implementation of relational data structures.


This module represents database relations
inside memory.


============================================================
*/


#include <stdio.h>
#include <string.h>


#include "../include/relation.h"







/*
============================================================

Create Relation


Creates an empty database relation.


Example:


Student


Initially:


Student = {}

============================================================
*/


Relation create_relation(char* name)
{


    Relation relation;


    strcpy(
        relation.relation_name,
        name
    );


    relation.row_count = 0;



    return relation;

}







/*
============================================================

Add Tuple


Adds a row into the relation.


Example:


Before:

Student {}


After:


Student
{
(Alice,95)
}


============================================================
*/


void add_tuple(
        Relation* relation,
        char* name,
        int grade
)
{


    if(relation->row_count >= MAX_ROWS)
    {

        printf(
            "Relation full\n"
        );


        return;

    }





    Tuple new_tuple;



    strcpy(
        new_tuple.name,
        name
    );



    new_tuple.grade = grade;



    relation->rows[
        relation->row_count
    ] = new_tuple;



    relation->row_count++;


}








/*
============================================================

Print Relation


Displays the relation.

Equivalent to viewing a database table.


============================================================
*/


void print_relation(
        Relation* relation
)
{


    printf(
        "\nRelation: %s\n",
        relation->relation_name
    );



    printf(
        "---------------------\n"
    );



    printf(
        "Name\tGrade\n"
    );



    for(
        int i = 0;
        i < relation->row_count;
        i++
    )
    {


        printf(
            "%s\t%d\n",
            relation->rows[i].name,
            relation->rows[i].grade
        );


    }



    printf(
        "\n"
    );


}