/*
============================================================

Logic Query Engine

File:

storage.c


Purpose:

CSV storage engine implementation.


Responsible for:

- Reading files
- Parsing rows
- Creating relations


============================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../include/storage.h"






/*
============================================================

Load CSV


CSV format:


name,grade

Alice,95


============================================================
*/


Relation load_csv(
        char* filename
)
{


    FILE* file =
        fopen(
            filename,
            "r"
        );



    if(file == NULL)
    {

        printf(
            "Unable to open file\n"
        );


        return create_relation(
            "Empty"
        );

    }




    Relation relation =
        create_relation(
            "Student"
        );





    char line[256];



    /*
    Remove header

    name,grade

    */

    fgets(
        line,
        sizeof(line),
        file
    );







    while(
        fgets(
            line,
            sizeof(line),
            file
        )
    )
    {


        char name[50];


        int grade;



        sscanf(
            line,
            "%[^,],%d",
            name,
            &grade
        );



        add_tuple(
            &relation,
            name,
            grade
        );



    }




    fclose(file);



    return relation;

}








/*
============================================================

Save CSV


Relation

↓

CSV


============================================================
*/


void save_csv(
        char* filename,
        Relation relation
)
{


    FILE* file =
        fopen(
            filename,
            "w"
        );



    if(file == NULL)
        return;



    fprintf(
        file,
        "name,grade\n"
    );



    for(
        int i=0;
        i<relation.row_count;
        i++
    )
    {


        fprintf(
            file,
            "%s,%d\n",
            relation.rows[i].name,
            relation.rows[i].grade
        );


    }



    fclose(file);

}