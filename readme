<div align="center">

# Logic Query Engine

### A miniature relational database engine built from first principles using C17.

<br>

![Language](https://img.shields.io/badge/Language-C17-blue)
![Focus](https://img.shields.io/badge/Focus-Database%20Systems-green)
![Theory](https://img.shields.io/badge/Foundation-Discrete%20Mathematics-purple)
![Status](https://img.shields.io/badge/Status-Active%20Development-orange)

</div>


---

# Project Overview

Modern database systems hide enormous amounts of complexity behind simple queries.

A user writes:

```sql
SELECT name WHERE grade > 80;
```

However, internally a database must transform that command through multiple stages:

```
SQL Query

↓

Lexical Analysis

↓

Parsing

↓

Abstract Syntax Tree

↓

Logical Query Plan

↓

Relational Operations

↓

Execution

↓

Result Set
```

This project implements a simplified relational database engine from first principles using C17.

The purpose is not to recreate a production database.

The purpose is to understand the computer science concepts that make database systems possible.


---

# Mission Statement

> To transform mathematical foundations such as logic, relations, and sets into a working database execution system.

This project demonstrates the connection between:

```
Mathematical Theory

↓

Algorithms

↓

Systems Programming

↓

Software Engineering
```

---

# Connection To CS From First Principles


This project is an engineering application of concepts studied in:


# CS From First Principles


Repository:

```
[INSERT YOUR CS FROM FIRST PRINCIPLES LINK]
```


Relevant learning:

```
Module 1 — Discrete Mathematics

Logic

↓

Sets

↓

Relations

↓

Graph Thinking

↓

Formal Systems
```


The learning repository focuses on understanding the theoretical foundations.

This project applies those ideas by building a functioning query engine.


---

# Database Engineering Features


Implemented components:


✓ CSV storage layer

✓ Relation and tuple representation

✓ SQL-style lexer

✓ Query parser

✓ Abstract Syntax Tree generation

✓ Logical query planning

✓ Relational algebra execution

✓ Predicate evaluation

✓ Query optimisation framework



Architecture inspired by concepts found in:

- PostgreSQL
- SQLite
- MySQL


---

# Engineering Question


The central engineering question:

> How does a database transform a human query into mathematical operations over data?


Example:


User query:

```sql
SELECT name WHERE grade > 80;
```


Internal representation:


Predicate:

```
grade > 80
```


Relational algebra:


```
σ grade > 80(Student)
```


Projection:


```
π name(Student)
```


Final result:


```
Alice
Charlie
```

---

# System Architecture


The engine follows this pipeline:


```
                 Query

                   |

                   v

                Lexer

                   |

                   v

                Parser

                   |

                   v

          Abstract Syntax Tree

                   |

                   v

            Query Planner

                   |

                   v

        Relational Execution Engine

                   |

                   v

              Result Relation

```


Detailed architecture:

```
docs/architecture.md
```

---

# Core Computer Science Concepts


## Predicate Logic


Database conditions are logical predicates.


Example:

```
grade > 80
```


Represented mathematically:

```
P(student)

where:

P(student) = student.grade > 80
```


The engine evaluates whether each tuple satisfies the condition.


---

# Relations


Database tables are mathematical relations.


Example:


```
Student(Name, Grade)
```


A relation consists of:

```
Relation = Set of Tuples
```


Example:


```
{
(Alice,95),
(Bob,72),
(Charlie,88)
}
```


---

# Sets


Query results represent sets of valid records.


Example:


```
Result =

{
Alice,
Charlie
}
```


Database operations are performed over collections of tuples.


---

# Relational Algebra


The project implements core relational algebra concepts.


## Selection


Filtering tuples:


```
σ condition(Relation)
```


Example:


```
σ grade > 80(Student)
```


---

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

# Internal Query Pipeline


The complete execution flow:


```
User Query

↓

Lexer

↓

Tokens

↓

Parser

↓

AST

↓

Logical Query Plan

↓

Optimizer

↓

Executor

↓

Result Relation
```


This mirrors the conceptual architecture used by professional database engines.


---

# Technologies


## Language

- C17


## Development Tools

- GCC
- Make
- GDB
- Linux command line
- Git/GitHub


---

# Repository Structure


```
logic-query-engine/

│
├── data/

│   └── students.csv


├── docs/

│   ├── architecture.md

│   ├── relational-algebra.md

│   └── query-processing.md


├── include/

│   ├── parser.h

│   ├── relation.h

│   ├── executor.h


├── src/

│   ├── lexer.c

│   ├── parser.c

│   ├── ast.c

│   ├── planner.c

│   ├── executor.c

│   ├── storage.c

│   └── main.c


├── Makefile

└── README.md

```

---

# Running The Project


Clone repository:


```
git clone [repository-link]
```


Build:


```
make
```


Run:


```
make run
```


Example output:


```
Loaded Database:

Alice 95
Bob 72
Charlie 88


Query:

SELECT name WHERE grade > 80


Result:

Alice
Charlie
```

---

# Engineering Principles


## Separation of Concerns


Each component has a specific responsibility.


Lexer:

Converts text into tokens.


Parser:

Builds structured queries.


Planner:

Creates execution strategy.


Executor:

Performs relational operations.


Storage:

Manages data representation.


---

## Build From First Principles


The project follows:


```
Theory

↓

Implementation

↓

Experimentation

↓

Engineering System
```


---

# Future Improvements


Planned extensions:


## Query Language

- AND / OR conditions
- multiple columns
- JOIN operations
- ORDER BY


## Database Systems

- indexing
- B-tree structures
- persistent storage engine
- transaction support


## Optimisation

- query cost estimation
- execution benchmarking
- improved query planning


---

# Core References


Database Systems:

- Database System Concepts  
  Silberschatz, Korth, Sudarshan


- Fundamentals of Database Systems  
  Elmasri & Navathe


Mathematics:

- MIT Mathematics for Computer Science

- Discrete Mathematics and Its Applications


---

# Portfolio Significance


This project demonstrates:


✓ Understanding of database internals

✓ Applying discrete mathematics to software

✓ Designing modular systems

✓ Implementing algorithms from theory

✓ Building software from first principles


The objective is not only to use databases.

The objective is to understand how they work.


---

# Learning Journey


This project represents:


```
CS Theory

↓

Mathematics

↓

Implementation

↓

Engineering System
```


A foundation for future projects involving:

```
Computer Architecture

↓

Operating Systems

↓

Distributed Systems

↓

Artificial Intelligence
```


---

# Engineering Principle


> Great software systems are built by transforming mathematical ideas into practical algorithms.