# Version 2 Migration

This version introduces the first stage of a compiler-style architecture.

The original parser still returns a `Query` structure so that the execution engine remains unchanged.

However, every parsed query now also produces an **Abstract Syntax Tree (AST)**.

Current execution pipeline:

```
SQL Text

↓

Lexer

↓

Parser

↓

Query Structure
      │
      └──────────────┐
                     ▼

            Abstract Syntax Tree

↓

Execution Engine
```

The AST is currently used for visualisation and debugging.

Future versions will execute directly from the AST, enabling:

- logical optimisation
- query planning
- support for additional SQL operators
- JOINs
- expression trees
- compiler-style transformations

This staged migration mirrors how production systems evolve while maintaining working software between releases.