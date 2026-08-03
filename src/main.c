/*
============================================================

Logic Query Engine

Main Demonstration


Runs:

CSV Data

↓

Relation

↓

Query Parser

↓

Execution Engine

↓

Result


============================================================
*/


#include <stdio.h>


#include "../include/relation.h"

#include "../include/parser.h"

#include "../include/executor.h"





int main()
{


    printf(
        "\nLogic Query Engine\n"
    );


    printf(
        "==================\n\n"
    );




    /*
    Create database relation

    Student(Name, Grade)

    */


    Relation students =
        create_relation(
            "Student"
        );




    /*
    Insert sample data

    */


    add_tuple(
        &students,
        "Alice",
        95
    );


    add_tuple(
        &students,
        "Bob",
        72
    );


    add_tuple(
        &students,
        "Charlie",
        88
    );



    printf(
        "Original Relation:"
    );


    print_relation(
        &students
    );





    /*
    User Query

    */


    char query_text[] =
        "SELECT name WHERE grade > 80";




    Query query =
        parse_query(
            query_text
        );



    print_query(
        query
    );






    /*
    Execute query

    */


    Relation result =
        execute_query(
            students,
            query
        );





    printf(
        "Query Result:"
    );


    print_relation(
        &result
    );




    return 0;

}