# Storage Engine


## Purpose

The storage layer converts persistent data into an in-memory relation.


Architecture:



students.csv

↓

CSV Parser

↓

Relation

↓

Query Engine




---

# Database Concept


A database table:



Student(Name, Grade)



is represented internally as:



Relation

{

Tuple

Tuple

Tuple

}




---

# Current Implementation


Supported:


- CSV reading
- CSV writing
- Relation construction
- Persistent storage


---

# Future Improvements


Real databases add:


- binary storage files
- indexing
- page management
- buffering
- transactions