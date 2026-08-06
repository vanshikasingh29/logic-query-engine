/*
============================================================

Logic Query Engine

File:

optimiser.h


Purpose:

Defines query optimisation layer.


Pipeline:


Query

↓

Parser

↓

Planner

↓

Optimiser

↓

Executor


============================================================
*/


#ifndef OPTIMISER_H
#define OPTIMISER_H



#include "planner.h"





typedef struct
{

    int estimated_rows;


    int estimated_cost;


} QueryStatistics;







QueryPlan optimize_plan(
        QueryPlan plan
);





QueryStatistics estimate_cost(
        QueryPlan plan
);





#endif