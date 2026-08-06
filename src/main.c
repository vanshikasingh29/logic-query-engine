/*
============================================================

Logic Query Engine

File:

main.c


Database Pipeline:


CSV

↓

Storage Engine

↓

Relation

↓

Lexer

↓

Parser

↓

AST

↓

Query Planner

↓

Execution Engine

↓

Result


============================================================
*/


#include <stdio.h>


#include "../include/storage.h"

#include "../include/parser.h"

#include "../include/executor.h"

#include "../include/planner.h"





int main()
{


    printf(
        "\n=================================\n"
    );


    printf(
        "      Logic Query Engine\n"
    );


    printf(
        "=================================\n\n"
    );





    /*
    Load database table

    */


    Relation students =
        load_csv(
            "data/students.csv"
        );




    printf(
        "Loaded Database:\n"
    );


    print_relation(
        &students
    );








    /*
    Parse Query

    */


    char query_text[] =
        "SELECT name WHERE grade > 80";



    parse_query(
        query_text
    );




    ASTNode* ast =
        get_latest_ast();





    printf(
        "\nAbstract Syntax Tree\n"
    );


    printf(
        "--------------------\n"
    );


    print_ast(
        ast,
        0
    );







    /*
    Create Query Plan

    */


    QueryPlan plan =
        create_plan(
            ast
        );



    printf(
        "\nQuery Plan\n"
    );


    printf(
        "----------\n"
    );


    print_plan(
        plan
    );








    /*
    Execute Query

    */


    Relation result =
        execute_ast(
            students,
            plan.root
        );





    printf(
        "\nQuery Result\n"
    );


    printf(
        "------------\n"
    );


    print_relation(
        &result
    );





    return 0;

}