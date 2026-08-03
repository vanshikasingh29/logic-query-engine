# Query Parser Design

## Overview

A database query begins as human-readable text.

The system must transform this text into a structured representation.

This process is similar to compiler design.

---

# Query Processing Pipeline


```
SQL Query

↓

Tokens

↓

Parser

↓

Query Object

↓

Execution Engine

```


---

# Example


Input:


```sql
SELECT name WHERE grade > 80
```


---

Parser Output:


```
Projection:

name


Predicate:


Column:

grade


Operator:

>


Value:

80

```

---

# Why Use Internal Representations?


A database does not execute text directly.


Instead:


Human Language

↓

Mathematical Meaning

↓

Data Operations


The Query structure acts as the bridge.

---

# Connection To Computer Science


This design connects:


## Discrete Mathematics

Predicates:

```
grade > 80
```


## Compiler Design

Parsing:

```
Text

↓

Structure

```


## Database Systems

Query execution:

```
Relation

↓

Operation

↓

Result

```

---

# Future Improvements


Possible extensions:


## Lexer


Separate input into tokens:


```
SELECT

name

WHERE

grade

>

80

```


---

## Expression Trees


Support:


```
grade > 80 AND grade < 100

```


represented as:


```
          AND

        /     \

       >

             <

```


---

## Query Optimisation


Allow the engine to choose efficient execution strategies.