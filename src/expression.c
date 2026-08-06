#include <string.h>


#include "../include/expression.h"





int evaluate_expression(
        Tuple tuple,
        ExpressionNode* expression
)
{


    if(
        strcmp(
            expression->column,
            "grade"
        )
        == 0
    )
    {


        switch(expression->operator)
        {


            case '>':

                return tuple.grade >
                       expression->value;



            case '<':

                return tuple.grade <
                       expression->value;



            case '=':

                return tuple.grade ==
                       expression->value;


        }


    }


    return 0;

}