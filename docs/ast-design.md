# Abstract Syntax Tree (AST)

## Purpose

The parser converts SQL text into an Abstract Syntax Tree.

The AST represents the **meaning** of the query rather than the original characters.

---

## Example

Input:

```sql
SELECT name WHERE grade > 80
```

AST:

```
SELECT
├── PROJECTION(name)
└── WHERE
    └── >
        ├── IDENTIFIER(grade)
        └── NUMBER(80)
```

---

## Why Not Execute the Text Directly?

The string:

```
grade > 80
```

is difficult for software to manipulate.

The tree structure makes it possible to:

- optimise queries
- rewrite expressions
- analyse predicates
- support more complex SQL
- generate execution plans

---

## Connection to Compiler Design

Almost every compiler follows this sequence:

```
Characters

↓

Tokens

↓

Abstract Syntax Tree

↓

Semantic Analysis

↓

Optimisation

↓

Code Generation
```

Database systems use a very similar approach before executing a query.

---

## Future Extensions

This AST can naturally support:

- AND
- OR
- NOT
- JOIN
- ORDER BY
- GROUP BY
- Nested queries
- Query optimisation