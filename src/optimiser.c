/*
============================================================

Logic Query Engine

File:

optimiser.c


Purpose:

Query optimisation implementation.


============================================================
*/


#include <stdio.h>


#include "../include/optimiser.h"







/*
============================================================

Cost Estimation


Future database systems calculate:

- disk reads
- CPU operations
- memory usage


Current educational model:

operation cost counting


============================================================
*/


QueryStatistics estimate_cost(
        QueryPlan plan
)
{


    QueryStatistics stats;



    stats.estimated_rows = 100;


    stats.estimated_cost = 1;



    if(plan.root != NULL)
    {

        stats.estimated_cost += 1;

    }



    return stats;

}









/*
============================================================

Optimizer


Applies optimisation rules.


Current:

- Validate plan
- Estimate cost


Future:

- Predicate pushdown
- Join ordering
- Index selection


============================================================
*/


QueryPlan optimize_plan(
        QueryPlan plan
)
{


    QueryStatistics stats =
        estimate_cost(
            plan
        );




    printf(
        "\nQuery Optimiser\n"
    );


    printf(
        "----------------\n"
    );


    printf(
        "Estimated Rows: %d\n",
        stats.estimated_rows
    );



    printf(
        "Estimated Cost: %d\n",
        stats.estimated_cost
    );



    return plan;

}