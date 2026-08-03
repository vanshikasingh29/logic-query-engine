# Engineering Report

# Logic Query Engine


## 1. Project Objective


The goal of this project was to implement a miniature database query engine from first principles.


Rather than using an existing database system, the project explores the internal concepts that make databases possible.


---

# 2. Problem


Users interact with databases through simple queries:


```sql
SELECT name WHERE grade > 80;
```


However, internally a database must transform this request into mathematical operations.


---

# 3. Solution


The system implements:


```
Query

↓

Parser

↓

Logical Representation

↓

Relational Operations

↓

Result

```


---

# 4. Computer Science Concepts


## Discrete Mathematics


Implemented concepts:


- predicate logic
- relations
- sets
- relational algebra



## Software Engineering


Implemented:


- modular architecture
- interfaces
- testing
- documentation



## Database Systems


Implemented:


- relation representation
- query processing
- selection
- projection


---

# 5. Design Decisions


## Language Choice


C was selected because it exposes:

- memory representation
- data structures
- execution details


This allows deeper understanding than using a database framework.


---

## Architecture Choice


The project separates:


Parser

↓

Execution

↓

Data Model


This mirrors larger database systems.


---

# 6. Current Limitations


The system currently does not implement:


- joins
- indexes
- query optimisation
- persistence layer


These represent future engineering extensions.


---

# 7. Future Roadmap


Potential improvements:


- JOIN operations
- B-tree indexing
- query planner
- storage engine
- transactions


---

# Final Reflection


This project demonstrates how mathematical concepts become practical software systems.

Database systems are not simply applications.

They are implementations of logic, mathematics, and algorithms.