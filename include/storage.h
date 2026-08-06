/*
============================================================

Logic Query Engine

File:

storage.h


Purpose:

Defines the database storage layer.


The storage layer converts:

CSV File

↓

Relation


Architecture:

Disk Storage

↓

Memory Representation

↓

Query Engine


============================================================
*/


#ifndef STORAGE_H
#define STORAGE_H



#include "relation.h"



/*
============================================================

Load Relation


Reads CSV database file.


Example:


students.csv


becomes:


Student(Name, Grade)


============================================================
*/


Relation load_csv(
        char* filename
);




/*
============================================================

Save Relation


Writes relation back to disk.


============================================================
*/


void save_csv(
        char* filename,
        Relation relation
);



#endif