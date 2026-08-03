# Data Model Design

## Overview

Before executing queries, the database engine requires a representation of data.

This project models database tables using mathematical relations.

---

# Mathematical Representation

A relation:

```
R
```

is a set of tuples.


Example:


```
Student(Name, Grade)

```


contains tuples:


```
(Alice,95)

(Bob,72)

(Charlie,88)

```

---

# Mapping Mathematics To C


Mathematics:

```
Relation

↓

Set of Tuples

```


C Implementation:


```
struct Relation

↓

Array of Tuple structures

```


---

# Tuple Representation


A tuple:


```
(Alice,95)

```


becomes:


```c
typedef struct
{

char name[];

int grade;

} Tuple;

```


---

# Design Decision


The first implementation uses fixed-size arrays.


Advantages:

- simple memory model,
- predictable allocation,
- easy debugging.


Limitations:

- maximum number of rows,
- no dynamic resizing.


Future improvement:


```
Dynamic memory allocation

↓

Linked storage

↓

Database buffer management

```

---

# Connection To Database Systems


Real systems such as PostgreSQL and SQLite also require internal representations of:

- relations,
- tuples,
- attributes.


This project implements a simplified version of that foundation.