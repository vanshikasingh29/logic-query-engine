/*
============================================================

Logic Query Engine

File:

parser.h


Purpose:

Defines the internal representation of queries.

The parser converts human-readable commands into
structured data that the execution engine can understand.


Pipeline:

SQL Text

↓

Parser

↓

Query Structure


============================================================
*/


#ifndef PARSER_H
#define PARSER_H



#define MAX_QUERY_LENGTH 256

#define MAX_COLUMN_LENGTH 50




/*
============================================================

Operators

Represents logical comparison operations.


Example:

grade > 80


Operator:

GREATER_THAN


============================================================
*/


typedef enum
{

    OP_GREATER_THAN,

    OP_LESS_THAN,

    OP_EQUAL


} Operator;







/*
============================================================

Predicate Structure


Represents:

WHERE condition


Example:


grade > 80


becomes:


column = grade

operator = >

value = 80


============================================================
*/


typedef struct
{


    char column[MAX_COLUMN_LENGTH];


    Operator operator;


    int value;



} Predicate;







/*
============================================================

Query Structure


Represents the complete query.


Example:


SELECT name WHERE grade > 80


becomes:


projection:

name


predicate:

grade > 80


============================================================
*/


typedef struct
{


    char projection[MAX_COLUMN_LENGTH];


    Predicate condition;



} Query;






/*
============================================================

Parser Functions


============================================================
*/


/*
Parses SQL-style query text.

Returns a structured Query object.

*/
Query parse_query(
        char* input
);




/*
Displays parsed query.

Useful for debugging.

*/
void print_query(
        Query query
);




#endif