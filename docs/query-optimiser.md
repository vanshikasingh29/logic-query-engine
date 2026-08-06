# Query Optimizer


## Overview


A database does not immediately execute a query after parsing it.


Instead, it creates an execution strategy.


The pipeline becomes:



SQL Query

↓

Parser

↓

Logical Query Plan

↓

Query Optimizer

↓

Execution Engine

↓

Result




---

# Why Optimization Exists


Different execution strategies can produce the same answer.


Example:


Strategy A:


Scan entire table

↓

Filter rows



Strategy B:


Use index

↓

Retrieve matching rows



Both produce the same result.

However:


Strategy A:


100000 operations



Strategy B:


100 operations



The optimizer chooses the cheaper strategy.



---

# Current Implementation


The current optimizer provides:


## Logical Plan Analysis


The optimizer receives:



AST

↓

QueryPlan



and analyses the structure.



## Cost Estimation


Currently:



estimated_cost = operation count



Future versions will include:


- disk access cost
- memory usage
- CPU operations
- relation size



---

# Database Concepts Demonstrated


This module demonstrates:


- Query planning
- Cost models
- Execution strategies
- Relational algebra optimisation



---

# Future Improvements


## Predicate Pushdown


Move filtering closer to storage.


Before:



Read Table

↓

Filter

↓

Return Result



After:



Filter During Reading

↓

Return Smaller Dataset




Benefits:

- Less memory usage
- Faster execution



---

# Join Optimisation


Future support:



Student

JOIN

Course



The optimizer will decide:



Student → Course

or

Course → Student



based on cost.



---

# Index Selection


Future databases use:


- B Trees
- Hash indexes
- Bitmap indexes


instead of scanning every row.



Full Scan

↓

Index Lookup


---

# Real Database Inspiration


Architecture inspired by concepts from:


- PostgreSQL query planner
- SQLite execution engine
- Relational database theory