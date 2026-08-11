
# Logic Query Engine
Example Queries
================

The current query language intentionally supports a small SQL-style subset.

--------------------------------------------------
1. Selection
--------------------------------------------------

SELECT name WHERE grade > 80


Expected matching records:

Alice
Charlie
David
Frank
Grace


--------------------------------------------------
2. Different comparison
--------------------------------------------------

SELECT name WHERE grade < 80


--------------------------------------------------
3. Equality
--------------------------------------------------

SELECT name WHERE grade = 95


--------------------------------------------------
4. Relational interpretation
--------------------------------------------------

The query:

SELECT name WHERE grade > 80

can be represented as:

π name (
    σ grade > 80 (
        Student
    )
)


--------------------------------------------------
5. Processing pipeline
--------------------------------------------------

Query text
    ↓
Lexer
    ↓
Tokens
    ↓
Parser
    ↓
AST
    ↓
Logical Plan
    ↓
Executor
    ↓
Result Relation