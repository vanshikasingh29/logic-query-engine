/*
============================================================

Logic Query Engine

File:

parser.c


Purpose:

Converts human-readable queries into
machine-readable query structures.


============================================================
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "../include/parser.h"






/*
============================================================

Parse Operator


Converts:

>

into:

OP_GREATER_THAN


============================================================
*/


Operator parse_operator(
        char symbol
)
{


    switch(symbol)
    {


        case '>':

            return OP_GREATER_THAN;



        case '<':

            return OP_LESS_THAN;



        case '=':

            return OP_EQUAL;



        default:

            return OP_EQUAL;


    }

}








/*
============================================================

Query Parser


Example input:


SELECT name WHERE grade > 80


Output:


Query

projection:

name


condition:

grade > 80


============================================================
*/


Query parse_query(
        char* input
)
{


    Query query;



    char operator_symbol;



    /*
    Extract:

    SELECT column

    WHERE column operator value

    */


    sscanf(
        input,

        "SELECT %s WHERE %s %c %d",

        query.projection,

        query.condition.column,

        &operator_symbol,

        &query.condition.value
    );




    query.condition.operator =
        parse_operator(
            operator_symbol
        );



    return query;

}







/*
============================================================

Print Query


Displays internal representation.


============================================================
*/


void print_query(
        Query query
)
{


    printf(
        "\nParsed Query\n"
    );


    printf(
        "----------------\n"
    );



    printf(
        "Projection: %s\n",
        query.projection
    );



    printf(
        "Condition Column: %s\n",
        query.condition.column
    );



    printf(
        "Condition Value: %d\n",
        query.condition.value
    );



    printf(
        "\n"
    );


}