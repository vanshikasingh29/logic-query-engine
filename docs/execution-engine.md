# Execution Engine

## Overview

The execution engine represents the final stage of the database pipeline.

The system transforms:


Human Query

↓

Lexical Analysis

↓

Parsing

↓

Abstract Syntax Tree

↓

Logical Query Plan

↓

Relational Algebra

↓

Execution

↓

Result Relation


---

# Database Architecture

Modern database systems separate responsibilities.

## Parser

Responsible for understanding syntax.

Example:


SELECT name WHERE grade > 80


becomes:


SELECT

WHERE

grade > 80


---

# Abstract Syntax Tree

The query is represented as a tree structure.

Example:

    SELECT

   /      \

name WHERE

          |

          >

        /   \

    grade    80

The AST provides a mathematical representation of the query.

---

# Query Planner

The planner converts the AST into an execution strategy.

Pipeline:


AST

↓

Logical Plan

↓

Execution Operators


Future database systems use this stage for:

- optimisation
- index selection
- join ordering
- cost estimation

---

# Relational Algebra

The engine currently supports:

## Selection

Symbol:


σ


Meaning:

Filter rows based on a predicate.

Example:


σ grade > 80(Student)


---

## Projection

Symbol:


π


Meaning:

Choose attributes.

Example:


π name(Student)


---

# Example Query

Input:


SELECT name WHERE grade > 80


Mathematical interpretation:


π name
(
σ grade > 80
Student
)


---

# Future Engineering Improvements

## Query Optimisation

Implement:

- execution cost estimation
- query rewriting
- optimisation rules


## Database Indexing

Add:

- B-Trees
- Hash indexes
- Search optimisation


## Join Processing

Implement:

- nested loop joins
- hash joins
- merge joins


## Storage Engine

Future versions may include:

- pages
- disk storage
- buffer manager
- transactions