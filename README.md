<div align="center">

# Logic Query Engine

### A miniature relational query engine built from first principles in C17.

[![Language](https://img.shields.io/badge/Language-C17-blue)](https://en.wikipedia.org/wiki/C17_(C_standard_revision))
[![Domain](https://img.shields.io/badge/Domain-Database%20Systems-green)](https://en.wikipedia.org/wiki/Database)
[![Foundations](https://img.shields.io/badge/Foundation-Discrete%20Mathematics-purple)](https://en.wikipedia.org/wiki/Discrete_mathematics)
[![Tests](https://img.shields.io/badge/Tests-Passing-brightgreen)](#testing)
[![Status](https://img.shields.io/badge/Status-Completed-orange)](#project-status)

</div>

---

# Project Overview

The Logic Query Engine is a miniature relational query processing system implemented in **C17 from first principles**.

The project explores how a high-level query can be transformed into structured computational operations over relational data.

A query such as:

```sql
SELECT name
WHERE grade > 80
```
---
and receives:

```
Alice
Charlie
```

However, behind this simple command exists a complex chain of mathematical and computational processes.

The database must:

```
User Query

↓

Parse Query

↓

Understand Meaning

↓

Apply Logical Conditions

↓

Perform Relational Operations

↓

Return Result
```

This project explores these foundations by implementing a simplified SQL-style query engine from scratch in C.

---

# Mission Statement

> Understand how the mathematical foundations of discrete mathematics become concrete algorithms and software architecture inside a database system.

This project demonstrates:

- predicate logic,
- relational algebra,
- set operations,
- data modelling,
- query processing,
- software architecture.

The project connects:

```
Logic
  ↓
Sets
  ↓
Relations
  ↓
Relational Algebra
  ↓
Query Processing
  ↓
Database Systems
```
Rather than treating SQL and databases as black boxes, this project reconstructs a simplified version of the underlying pipeline.


# Connection To CS From First Principles


This repository is the Phase 1 engineering portfolio project for my independent Computer Science foundations programme.

Learning repository:
```
https://github.com/vanshikasingh29/CS-from-first-principle.git
```


The corresponding mathematical foundations include:
```
Discrete Mathematics
       ↓
Logic
       ↓
Sets
       ↓
Relations
       ↓
Functions
       ↓
Relational Algebra
       ↓
Query Processing
```
The learning repository contains the individual theoretical and practical laboratories.

This repository acts as the larger engineering application of those foundations.

---

# Database Engineering Features


This project has evolved into a miniature relational database engine.


Implemented components:


✓ CSV storage layer

✓ Relation representation

✓ SQL-style lexer

✓ Query parser

✓ Abstract Syntax Trees

✓ Logical query planning

✓ Relational algebra execution

✓ Predicate evaluation

✓ Query optimisation framework



The architecture follows principles used in:


- PostgreSQL
- SQLite
- MySQL query engines



The purpose is not to recreate a production database,
but to understand the fundamental engineering ideas
behind modern database systems.

---


# Engineering Question

The central question behind this project:

> How does a database transform a human-readable query into mathematical operations over data?


Example:


Human Query:

```
SELECT name
WHERE grade > 80;
```


Mathematical Representation:


Selection:

```
σ grade > 80(Student)
```


Projection:

```
π name(...)
```


Final Result:

```
{name = Alice}

{name = Charlie}
```
The implementation therefore connects a concrete programming system with the mathematical model underneath relational databases.

---

# System Architecture


The engine follows this pipeline:


```
              SQL Query
                  v

             Query Parser
                  v

        Logical Representation
                  v

        Relational Algebra Engine
                  v

              Result Set

```
Supporting components include:

- Storage
- Relations
- Sets
- Binary Relations
- Functions
- Expression Evaluation
- Optimisation
- Testing

The architecture deliberately separates responsibilities so that individual components can be reasoned about, tested and extended independently.

---
# Implemented Components
## Lexical Analysis
The lexer converts query text into a stream of tokens.

Conceptually:
```
SELECT name WHERE grade > 80

        ↓

SELECT
IDENTIFIER
WHERE
IDENTIFIER
GREATER_THAN
NUMBER
```
This establishes the lexical foundation required before syntactic analysis.

## Parser

The parser consumes the token stream and constructs a structured representation of the query.

###### Example:
```
SELECT name WHERE grade > 80

        ↓

Abstract Syntax Tree
Abstract Syntax Tree
```
The AST represents the logical structure of a query independently of its original textual form.

###### Example:
```
SELECT
 ├── PROJECTION: name
 └── WHERE
      └── >
          ├── grade
          └── 80
```

This representation provides the bridge between parsing and execution.

## Logical Query Planner

The planner converts the AST into a logical query plan.

The resulting plan represents the operations required to answer the query before execution begins.

```
AST
 ↓
Logical Plan
 ↓
Execution
Relational Execution
```
The executor implements relational operations over in-memory relations.

Implemented concepts include:

- selection
- projection
- predicate evaluation
- relation processing
- result construction

## Set Operations
The engine also contains a mathematical set layer supporting operations over relations.

Implemented operations include:

- union
- intersection
- difference
- distinctness
- membership reasoning

These operations connect the mathematical definition of sets with database-style relations.

## Binary Relations

The project includes an explicit binary relation implementation supporting analysis of properties such as:

- ordered-pair membership
- reflexivity
- symmetry
- antisymmetry
- transitivity
- equivalence relations
- relation composition

This provides a direct implementation of relation theory studied during the mathematical foundations phase.

## Functions

The mathematical function layer demonstrates:

- function construction
= function application
- injectivity
- surjectivity
- bijectivity
- composition
- invalid composition detection.

## Recursive Algorithms

The project also contains small algorithmic implementations used to connect mathematical reasoning with executable computation.

Implemented examples include:

- factorial
- Fibonacci
- recursive array summation
  - binary search

These are independently tested rather than being mixed into the database execution path.

###### Example Query

Input:
```
SELECT name WHERE grade > 80
```

Example relation:
```
Name      Grade
----------------
Alice     95
Bob       72
Charlie   88
David     91
Emma      65
Frank     100
Grace     84
Henry      76
```
Predicate:
```
grade > 80
```
Result:
```
Name      Grade
----------------
Alice     95
Charlie   88
David     91
Frank     100
Grace     84
```
---

# Features


## Query Processing

The engine supports:

- parsing SQL-style commands,
- interpreting conditions,
- evaluating predicates,
- generating result sets.


---

## Data Representation

Supports:

- relations,
- tuples,
- attributes,
- records.


---

## Mathematical Foundations

Implements ideas from:

- predicate logic,
- set theory,
- relational algebra.


---
# Mathematical Model

A relation can be viewed as a set of tuples.

For the student relation:
```
Student(Name, Grade)
```
each row is a tuple:
```
(Alice, 95)
(Bob, 72)
(Charlie, 88)
```
A predicate defines a condition over tuples:
```
P(x) = x.grade > 80
```
Selection retains only tuples for which the predicate evaluates to true:
```
σ grade > 80 (Student)
```
Projection then selects the requested attribute:
```
π name (...)
```
This is the mathematical foundation behind the query execution implemented by the engine.

# Testing

The project contains automated tests for the major implemented components.

Current test coverage includes:
```
Core Query Engine       5 tests
Set Theory              8 tests
Binary Relations        9 tests
Functions               8 tests
Algorithms             10 tests

Total:

40 automated tests
```
The test suites validate both individual mathematical operations and core query-processing behaviour.

# Technologies


## Language

- C17


## Tools

- GCC
- Make
- GDB
- Linux command line
- Git/GitHub


---

# Project Structure


```
logic-query-engine/

│
├── docs/

│   ├── relational-algebra.md

│   ├── query-processing.md

│   └── architecture.md


├── data/

│   └── students.csv


├── include/

│   ├── parser.h

│   ├── relation.h

│   └── executor.h


├── src/

│   ├── parser.c

│   ├── relation.c

│   ├── executor.c

│   └── main.c


├── tests/

│   └── query_tests.c


└── examples/

    └── example_queries.txt

```

---

# Engineering Goals


This project aims to demonstrate:


## Computer Science Theory

✓ Predicate logic  
✓ Relations  
✓ Sets  
✓ Relational algebra  
✓ Query reasoning  


---

## Database Systems

✓ Data representation  
✓ Query processing  
✓ Filtering operations  
✓ Result generation  


---

## Software Engineering

✓ Modular architecture  
✓ Documentation  
✓ Testing  
✓ Clean interfaces  


---

# Future Improvements


Possible extensions:


## Query Language

- multiple conditions
- AND / OR operators
- JOIN operations
- ORDER BY


## Database Features

- indexing
- query optimisation
- storage engine
- transactions


## Performance

- execution planning
- complexity analysis
- benchmarking


---

# Core References


Concepts inspired by:


## Database Systems

- Database System Concepts  
  Silberschatz, Korth, Sudarshan


- Fundamentals of Database Systems  
  Elmasri & Navathe


## Mathematics

- MIT Mathematics for Computer Science

- Discrete Mathematics and Its Applications


---

# Learning Journey


This project represents the transition:


```
Theory

↓

Mathematics

↓

Implementation

↓

Engineering System

```


The objective is not only to use databases.

The objective is to understand the principles that make databases possible.

---

## Internal Query Pipeline

The project intentionally mirrors the internal architecture used by modern database systems.

```
SQL Query

↓

Lexical Analysis

↓

Token Stream

↓

Parser

↓

Abstract Syntax Tree

↓

Logical Query Plan

↓

Execution Engine

↓

Result Relation
```
Although simplified for educational purposes, this architecture reflects the same conceptual stages used in production database engines.

---
## Limitations

This project is not intended to compete with production database systems.

It currently does not attempt to provide:

- persistent transactional storage
- concurrency control
- crash recovery
- production indexing
- distributed execution
- cost-based query optimisation
- full SQL compatibility

These limitations are intentional. The project focuses on understanding the fundamental abstractions and algorithms that larger systems build upon.

## Portfolio Significance

This project demonstrates the ability to:

✓ translate mathematical definitions into executable code,
✓ design a modular systems architecture,
✓ implement a query-processing pipeline,
✓ reason about relations and sets computationally,
✓ build and test C software,
✓ document engineering decisions,
✓ connect theoretical Computer Science with practical systems engineering.

It serves as the Phase 1 capstone of my independent Computer Science foundations programme.

---

# Future Development


This project represents the first major engineering application after completing Module 1.

Future projects will extend this progression into:


Computer Architecture

↓

Operating Systems

↓

Algorithms

↓

Artificial Intelligence Mathematics
