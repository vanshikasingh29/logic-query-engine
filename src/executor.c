/*
============================================================

Logic Query Engine

File:

executor.c


Version:

2.2


Purpose:

Executes relational algebra operations.


============================================================
*/


#include <stdio.h>
#include <string.h>


#include "../include/executor.h"






/*
============================================================

Evaluate Predicate

============================================================
*/

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








/*
============================================================

Selection

σ condition(Relation)


============================================================
*/


Relation selection(
        Relation relation,
        Predicate predicate
)
{


    Relation result =
        create_relation(
            "Selection Result"
        );



    for(int i=0;
        i<relation.row_count;
        i++)
    {


        if(
        evaluate_predicate(
            relation.rows[i],
            predicate
        ))
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








/*
============================================================

Projection

π attribute(Relation)


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



    for(int i=0;
        i<relation.row_count;
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








/*
============================================================

Legacy Query Execution


Query

↓

Selection

↓

Projection


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



    Relation projected =
        projection(
            filtered,
            query.projection
        );



    return projected;

}










/*
============================================================

AST Execution


Currently supports:


SELECT name WHERE grade > value


AST:

SELECT

 |

WHERE

 |

comparison


============================================================
*/


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



        switch(
        comparison->type)
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