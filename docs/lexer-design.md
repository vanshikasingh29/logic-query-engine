# Lexer Design

## Overview

Before a parser can understand a query, it must first divide the input into meaningful units called **tokens**.

Example:

```sql
SELECT name WHERE grade > 80
```

becomes

```
SELECT
IDENTIFIER(name)
WHERE
IDENTIFIER(grade)
GREATER_THAN
NUMBER(80)
END
```

---

## Why Tokenisation Exists

The parser should reason about **symbols**, not individual characters.

Instead of reading:

```
S
E
L
E
C
T
```

it receives one token:

```
TOKEN_SELECT
```

This greatly simplifies parsing and mirrors the architecture used in compilers and database systems.

---

## Connection to Later Modules

This component introduces ideas that will reappear in:

- Compiler construction
- Lexical analysis
- Finite automata
- Formal languages
- Programming language implementation