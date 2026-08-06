/*
============================================================

Logic Query Engine

File:

test_engine.c


Purpose:

Basic automated validation tests.

Tests:

1. Relation creation
2. Tuple insertion
3. Predicate evaluation
4. Selection operation
5. Query execution


The purpose of this file is to demonstrate:

- correctness checking
- modular testing
- software engineering practice


============================================================
*/


#include <stdio.h>
#include <string.h>


#include "../include/relation.h"
#include "../include/executor.h"
#include "../include/parser.h"





/*
============================================================

Simple Test Framework


============================================================
*/


int tests_passed = 0;

int tests_failed = 0;




void assert_test(
        int condition,
        char* test_name
)
{


    if(condition)
    {

        printf(
            "[PASS] %s\n",
            test_name
        );


        tests_passed++;

    }

    else
    {

        printf(
            "[FAIL] %s\n",
            test_name
        );


        tests_failed++;

    }


}









/*
============================================================

Test Relation Creation


============================================================
*/


void test_relation_creation()
{


    Relation students =
        create_relation(
            "Student"
        );



    assert_test(
        strcmp(
            students.relation_name,
            "Student"
        ) == 0,

        "Relation creation"
    );


}









/*
============================================================

Test Tuple Insertion


============================================================
*/


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



    assert_test(
        students.row_count == 1,

        "Tuple insertion"
    );



}









/*
============================================================

Test Predicate Evaluation


Example:

grade > 80


============================================================
*/


void test_predicate()
{


    Tuple student;


    strcpy(
        student.name,
        "Alice"
    );


    student.grade = 95;





    Predicate predicate;


    strcpy(
        predicate.column,
        "grade"
    );


    predicate.operator =
        OP_GREATER_THAN;


    predicate.value = 80;






    int result =
        evaluate_predicate(
            student,
            predicate
        );




    assert_test(
        result == 1,

        "Predicate evaluation"
    );


}









/*
============================================================

Test Selection Operation


============================================================
*/


void test_selection()
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




    Predicate predicate;



    strcpy(
        predicate.column,
        "grade"
    );


    predicate.operator =
        OP_GREATER_THAN;


    predicate.value = 80;





    Relation result =
        selection(
            students,
            predicate
        );





    assert_test(

        result.row_count == 1,

        "Selection operation"

    );


}









/*
============================================================

Test Query Execution


============================================================
*/


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






    Query query;



    strcpy(
        query.projection,
        "name"
    );



    strcpy(
        query.condition.column,
        "grade"
    );



    query.condition.operator =
        OP_GREATER_THAN;


    query.condition.value = 80;





    Relation result =
        execute_query(
            students,
            query
        );





    assert_test(

        result.row_count == 1,

        "Query execution"

    );


}









/*
============================================================

Main Test Runner


============================================================
*/


int main()
{


    printf(
        "\nLogic Query Engine Test Suite\n"
    );


    printf(
        "============================\n\n"
    );





    test_relation_creation();


    test_tuple_insertion();


    test_predicate();


    test_selection();


    test_query_execution();





    printf(
        "\nResults\n"
    );


    printf(
        "----------------\n"
    );


    printf(
        "Passed: %d\n",
        tests_passed
    );


    printf(
        "Failed: %d\n",
        tests_failed
    );





    if(tests_failed == 0)
    {

        printf(
            "\nAll tests passed.\n"
        );


        return 0;

    }



    else
    {

        printf(
            "\nSome tests failed.\n"
        );


        return 1;

    }


}