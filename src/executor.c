/*
============================================================

Logic Query Engine

File:

executor.c


Purpose:

Implements relational algebra operations.


Concepts:

- Predicate logic
- Sets
- Relations
- Selection
- Projection


============================================================
*/


#include <stdio.h>
#include <string.h>


#include "../include/executor.h"





/*
============================================================

Evaluate Predicate


Mathematical form:


P(tuple)


Example:


grade > 80


============================================================
*/


int evaluate_predicate(
        Tuple tuple,
        Predicate predicate
)
{


    if(
        strcmp(
            predicate.column,
            "grade"
        ) != 0
    )
    {

        return 0;

    }





    switch(predicate.operator)
    {


        case OP_GREATER_THAN:


            return tuple.grade > predicate.value;




        case OP_LESS_THAN:


            return tuple.grade < predicate.value;




        case OP_EQUAL:


            return tuple.grade == predicate.value;



        default:

            return 0;

    }


}







/*
============================================================

Selection


Relational algebra:


σ predicate(Relation)


Keeps only matching tuples.


============================================================
*/


Relation selection(
        Relation relation,
        Predicate predicate
)
{


    Relation result =
        create_relation(
            relation.relation_name
        );




    for(
        int i = 0;
        i < relation.row_count;
        i++
    )
    {


        Tuple current =
            relation.rows[i];



        if(
            evaluate_predicate(
                current,
                predicate
            )
        )
        {


            add_tuple(
                &result,
                current.name,
                current.grade
            );


        }


    }



    return result;

}








/*
============================================================

Projection


Relational algebra:


π name(Relation)


Returns selected attributes.


============================================================
*/


Relation projection(
        Relation relation,
        char* column
)
{


    Relation result =
        create_relation(
            "Projection Result"
        );



    if(
        strcmp(column,"name") != 0
    )
    {

        return result;

    }




    for(
        int i = 0;
        i < relation.row_count;
        i++
    )
    {


        add_tuple(
            &result,
            relation.rows[i].name,
            relation.rows[i].grade
        );


    }



    return result;

}







/*
============================================================

Execute Query


Complete database pipeline.


Example:


SELECT name WHERE grade > 80


Becomes:


Selection:

σ grade > 80(Student)


then:


Projection:

π name(Result)


============================================================
*/


Relation execute_query(
        Relation relation,
        Query query
)
{


    Relation filtered =
        selection(
            relation,
            query.condition
        );



    Relation result =
        projection(
            filtered,
            query.projection
        );



    return result;

}