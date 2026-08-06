/*
============================================================

Logic Query Engine

File:

executor.c


Purpose:

Executes relational algebra operations.


============================================================
*/


#include <stdio.h>

#include <string.h>

#include <stdlib.h>



#include "../include/executor.h"







int evaluate_predicate(
        Tuple tuple,
        Predicate predicate
)
{


    switch(predicate.operator)
    {


        case OP_GREATER_THAN:

            return tuple.grade >
                   predicate.value;



        case OP_LESS_THAN:

            return tuple.grade <
                   predicate.value;



        case OP_EQUAL:

            return tuple.grade ==
                   predicate.value;


    }


    return 0;

}







Relation selection(
        Relation relation,
        Predicate predicate
)
{


    Relation result =
        create_relation(
            "Selection Result"
        );



    for(int i = 0;
        i < relation.row_count;
        i++)
    {


        if(
            evaluate_predicate(
                relation.rows[i],
                predicate
            )
        )
        {


            add_tuple(
                &result,
                relation.rows[i].name,
                relation.rows[i].grade
            );


        }

    }



    return result;

}








Relation projection(
        Relation relation,
        char* column
)
{


    /*
    Currently the engine supports
    full tuple projection.

    Future versions will support
    dynamic column selection.

    */


    (void)column;



    Relation result =
        create_relation(
            "Projection Result"
        );



    for(int i = 0;
        i < relation.row_count;
        i++)
    {


        add_tuple(
            &result,
            relation.rows[i].name,
            relation.rows[i].grade
        );


    }



    return result;

}








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



    return projection(
        filtered,
        query.projection
    );

}









Relation execute_ast(
        Relation relation,
        ASTNode* root
)
{


    if(root == NULL)
    {
        return relation;
    }





    if(root->type == AST_SELECT)
    {


        ASTNode* where =
            root->right;



        ASTNode* comparison =
            where->left;



        Predicate predicate;



        strcpy(
            predicate.column,
            comparison->left->value
        );



        predicate.value =
            atoi(
                comparison->right->value
            );





        switch(comparison->type)
        {


            case AST_GREATER_THAN:


                predicate.operator =
                    OP_GREATER_THAN;


                break;



            case AST_LESS_THAN:


                predicate.operator =
                    OP_LESS_THAN;


                break;



            default:


                predicate.operator =
                    OP_EQUAL;


        }





        Relation result =
            selection(
                relation,
                predicate
            );



        return projection(
            result,
            root->left->value
        );


    }





    return relation;

}