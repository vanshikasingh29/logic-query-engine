<div align="center">

# Logic Query Engine

### A miniature relational database engine built from first principles using C.

<br>

![Language](https://img.shields.io/badge/Language-C17-blue)
![Focus](https://img.shields.io/badge/Focus-Database%20Systems-green)
![Theory](https://img.shields.io/badge/Foundation-Discrete%20Mathematics-purple)
![Status](https://img.shields.io/badge/Status-%20Iterating-orange)

</div>


---

# Project Overview

Modern databases appear simple from the outside.

A user writes:

```
SELECT name
WHERE grade > 80;
```

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

> To understand how mathematical concepts such as logic, sets, and relations become the foundation of modern database systems.

This project demonstrates:

- predicate logic,
- relational algebra,
- set operations,
- data modelling,
- query processing,
- software architecture.

---

# Connection To CS From First Principles


This project is an engineering application of concepts studied in:


# CS From First Principles


Learning Repository:

```
https://github.com/vanshikasingh29/CS-from-first-principle.git
```


Relevant topics:

```
Module 1

Discrete Mathematics

        ↓

       Logic

        ↓

       Sets

        ↓

    Relations

        ↓

   Graph Thinking

        ↓

  Automata Concepts

```


The learning repository focuses on understanding the mathematical foundations.

This project applies those ideas by creating a working query processing system.

---

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

---

# System Architecture


The engine follows this pipeline:


```
              SQL Query

                  |
                  v

             Query Parser

                  |
                  v

        Logical Representation

                  |
                  v

        Relational Algebra Engine

                  |
                  v

             Result Set

```


---

# Core Concepts Implemented


## Predicate Logic


A database condition:


```
grade > 80
```


is a logical predicate.


Mathematically:


```
P(student)

where:

P(student) = student.grade > 80

```


The engine evaluates whether each record satisfies the predicate.

---

# Relations


A database table is a mathematical relation.


Example:


Student Relation:


```
Student(Name, Grade)

```


Represented as:


```
(Name × Grade)

```


Each row is a tuple within the relation.

---

# Sets


Query results are sets of valid records.


Example:


```
Result =

{
 Alice,
 Charlie
}

```


The engine performs operations over collections of data.

---

# Relational Algebra


The project implements concepts from relational algebra:


## Selection


Filtering rows:


```
σ condition(Relation)

```


Example:


```
σ grade > 80(Student)

```



## Projection


Selecting attributes:


```
π attribute(Relation)

```


Example:


```
π name(Student)

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

# Engineering Principle


> Great software systems are built from mathematical ideas transformed into practical algorithms.

---

# Connection To CS From First Principles


This project is an engineering application of my independent Computer Science foundation journey.


Learning:


CS From First Principles

↓

Module 1: Discrete Mathematics

↓

Logic

↓

Sets

↓

Relations

↓

Relational Algebra


Applied:


↓

Logic Query Engine


The purpose was to transform mathematical theory into a working software system.


---

# Portfolio Significance


This project demonstrates:


✓ Understanding of database foundations

✓ Applying mathematical reasoning to software

✓ Building systems from first principles

✓ Designing modular software architecture

✓ Connecting theory with engineering


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
