# Query Processing Architecture

## Overview

A database query engine transforms a high-level human request into low-level operations.

This project models that process.

The execution pipeline:

```
SQL Query

↓

Parser

↓

Logical Representation

↓

Relational Algebra

↓

Execution Engine

↓

Result

```

---

# 1. Query Input

Example:

```sql
SELECT name WHERE grade > 80;
```


The user expresses intent.

At this stage:

- no computation has happened,
- the query is only text.

The system must understand its meaning.

---

# 2. Parsing

The parser converts text into structured information.


Input:

```
SELECT name WHERE grade > 80
```


Output:


```
Operation:
SELECT


Column:
name


Condition:

grade > 80

```

This removes ambiguity.

---

# 3. Logical Representation


The query becomes an internal representation.

Example:


```
Query

|

├── Projection

|       |

|       └── name

|

└── Predicate

        |

        └── grade > 80

```

This is similar to how compilers transform source code into intermediate representations.

---

# 4. Predicate Evaluation


The executor evaluates the condition.


For each student:


```
grade > 80

```


Example:


Alice:

```
95 > 80

TRUE

```


Bob:

```
72 > 80

FALSE

```


Charlie:

```
88 > 80

TRUE

```

Only valid tuples continue.

---

# 5. Result Generation


After evaluation:


Input:

```
Alice 95
Charlie 88

```


Projection:


```
name

```


Output:

```
Alice
Charlie

```

---

# 6. Database Architecture Connection


Real database systems perform additional steps:


```
Query

↓

Parser

↓

Query Optimiser

↓

Execution Planner

↓

Storage Engine

↓

Disk

```


This project focuses on the logical processing layer.

---

# 7. Future Improvements


Possible extensions:


## Query Optimisation


Choose the fastest execution strategy.


Example:

Instead of:

```
Read everything

↓

Filter

```

Use:

```
Index

↓

Find matching rows

```


---

## Join Processing


Combine relations:


Example:


Student:

```
Student_ID
Name

```


Grades:

```
Student_ID
Grade

```


JOIN creates:


```
Name + Grade

```


---

## Execution Plans


Represent queries as trees:


Example:


```
        Projection

             |

        Selection

             |

          Student

```

---

# Engineering Principle


A database is not simply storing information.

It is a mathematical machine that transforms queries into efficient computations.