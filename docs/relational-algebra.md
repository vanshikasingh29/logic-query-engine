# Relational Algebra Foundations

## Overview

Relational algebra is the mathematical foundation behind relational database systems.

Before a database executes a query, the query is transformed into a sequence of mathematical operations over relations.

This project implements a simplified version of these concepts.

The purpose is to understand the theory underneath SQL.

---

# 1. Relations

A relational database stores information as relations.

A relation can be represented mathematically as a set of tuples.

Example:

Student relation:

```
Student(Name, Grade)
```

Data:

| Name | Grade |
|---|---|
| Alice | 95 |
| Bob | 72 |
| Charlie | 88 |


Mathematically:

```
Student ⊆ Name × Grade
```

Meaning:

A student relation is a subset of all possible combinations of names and grades.

---

# 2. Tuples

Each row is called a tuple.

Example:

```
(Alice,95)
```

is one tuple in the Student relation.


A relation is therefore:

```
Relation = Set of Tuples
```

---

# 3. Selection Operator

Symbol:

```
σ
```

Selection filters tuples based on a condition.


Example SQL:

```sql
SELECT *
FROM Student
WHERE Grade > 80;
```


Relational algebra:

```
σ Grade > 80(Student)
```


The operation checks every tuple and keeps only those satisfying the predicate.


Example:

Input:

```
Alice 95
Bob 72
Charlie 88
```


Predicate:

```
Grade > 80
```


Output:

```
Alice 95
Charlie 88
```

---

# 4. Projection Operator

Symbol:

```
π
```


Projection chooses specific attributes.

Example:


SQL:

```sql
SELECT Name
FROM Student;
```


Relational algebra:


```
π Name(Student)
```


Input:

```
Alice 95
Bob 72
Charlie 88
```


Output:

```
Alice
Bob
Charlie
```

---

# 5. Combining Operations

Real database queries combine operators.


Example:


SQL:

```sql
SELECT Name
WHERE Grade > 80;
```


Step 1:

Selection:


```
σ Grade > 80(Student)

```


Result:


```
Alice 95
Charlie 88

```


Step 2:

Projection:


```
π Name(Result)

```


Final:


```
Alice
Charlie
```

---

# 6. Predicate Logic Connection


A WHERE condition is a logical predicate.


Example:


```
Grade > 80
```


becomes:


```
P(student)

=

student.grade > 80

```


The database evaluates:

```
Is P(student) true?

```

for every tuple.

---

# 7. Set Operations


Relations are sets.

Therefore database operations can use set theory.


Examples:


Union:

```
A ∪ B
```


Intersection:

```
A ∩ B
```


Difference:

```
A - B
```


These ideas form the foundation for operations such as JOIN and filtering.

---

# 8. Connection To Implementation


This project converts these mathematical ideas into software.


Theory:


```
Relation

↓

Set of Tuples

↓

Predicate Evaluation

↓

Result Set

```


Implementation:


```
struct Relation

↓

Array of Records

↓

Condition Function

↓

Filtered Output

```

---

# Engineering Insight


SQL looks like a programming language.

However, underneath it is mathematics.

The database engine is essentially translating:

Human Query

↓

Mathematical Operations

↓

Algorithms

↓

Machine Execution


This project implements that transformation.