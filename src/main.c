/*
============================================================

Logic Query Engine

File:

main.c


Purpose:

Complete demonstration pipeline.


Architecture:

CSV / Relation Data

↓

SQL Query

↓

Lexer

↓

Tokens

↓

Parser

↓

Abstract Syntax Tree

↓

Query Planner

↓

Relational Algebra

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

#include "../include/planner.h"

#include "../include/ast.h"






int main()
{


    printf(
        "\n=================================\n"
    );

    printf(
        "       Logic Query Engine\n"
    );

    printf(
        "=================================\n\n"
    );





    /*
    ========================================================

    STEP 1

    Create Database Relation


    Mathematical representation:


    Student(Name, Grade)


    ========================================================
    */


    Relation students =
        create_relation(
            "Student"
        );






    /*
    ========================================================

    STEP 2

    Insert Tuples


    Relation:


    Student =

    {
        (Alice,95),
        (Bob,72),
        (Charlie,88)
    }


    ========================================================
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
        "Original Relation\n"
    );


    printf(
        "-----------------\n"
    );


    print_relation(
        &students
    );







    /*
    ========================================================

    STEP 3

    SQL Query


    Example:


    SELECT name WHERE grade > 80


    ========================================================
    */


    char query_text[] =
        "SELECT name WHERE grade > 80";





    printf(
        "\nInput Query\n"
    );


    printf(
        "------------\n"
    );


    printf(
        "%s\n",
        query_text
    );









    /*
    ========================================================

    STEP 4

    Parsing


    SQL

    ↓

    Tokens

    ↓

    Query Structure

    ↓

    AST


    ========================================================
    */


    Query query =
        parse_query(
            query_text
        );




    print_query(
        query
    );







    /*
    ========================================================

    STEP 5

    Display Abstract Syntax Tree


    ========================================================
    */


    printf(
        "\nAbstract Syntax Tree\n"
    );


    printf(
        "--------------------\n"
    );



    print_ast(
        get_latest_ast(),
        0
    );









    /*
    ========================================================

    STEP 6

    Query Planning


    Database systems do not directly execute
    parser output.

    They create an execution plan.


    AST

    ↓

    Logical Plan


    ========================================================
    */


    QueryPlan plan =
        create_plan(
            get_latest_ast()
        );





    print_plan(
        plan
    );








    /*
    ========================================================

    STEP 7

    Execute AST


    Logical Plan

    ↓

    Relational Algebra

    ↓

    Result


    ========================================================
    */


    Relation ast_result =
        execute_ast(
            students,
            plan.root
        );





    printf(
        "\nAST Execution Result\n"
    );


    printf(
        "--------------------\n"
    );


    print_relation(
        &ast_result
    );









    /*
    ========================================================

    STEP 8

    Legacy Execution Test


    Keeps compatibility with
    previous engine.


    ========================================================
    */


    Relation old_result =
        execute_query(
            students,
            query
        );



    printf(
        "\nLegacy Execution Result\n"
    );


    printf(
        "-----------------------\n"
    );


    print_relation(
        &old_result
    );







    printf(
        "\nQuery completed successfully.\n"
    );



    return 0;

}