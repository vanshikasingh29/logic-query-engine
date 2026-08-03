/*
============================================================

Logic Query Engine

File:

query_tests.c


Purpose:

Automated validation of query behaviour.


============================================================
*/


#include <stdio.h>
#include <assert.h>


#include "../include/relation.h"
#include "../include/parser.h"
#include "../include/executor.h"





void test_relation_creation()
{


    Relation students =
        create_relation(
            "Student"
        );


    assert(
        students.row_count == 0
    );


    printf(
        "PASS: Relation creation\n"
    );

}





void test_tuple_insertion()
{


    Relation students =
        create_relation(
            "Student"
        );


    add_tuple(
        &students,
        "Alice",
        95
    );


    assert(
        students.row_count == 1
    );


    printf(
        "PASS: Tuple insertion\n"
    );


}





void test_query_execution()
{


    Relation students =
        create_relation(
            "Student"
        );



    add_tuple(
        &students,
        "Alice",
        95
    );


    add_tuple(
        &students,
        "Bob",
        70
    );



    Query query =
        parse_query(
            "SELECT name WHERE grade > 80"
        );



    Relation result =
        execute_query(
            students,
            query
        );



    assert(
        result.row_count == 1
    );


    printf(
        "PASS: Query execution\n"
    );


}





int main()
{


    printf(
        "\nLogic Query Engine Tests\n"
    );


    printf(
        "========================\n\n"
    );



    test_relation_creation();


    test_tuple_insertion();


    test_query_execution();



    printf(
        "\nAll tests passed successfully\n"
    );


    return 0;

}