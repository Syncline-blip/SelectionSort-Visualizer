/*
*   STUDENT : JOHN LUMAGBAS
*   ID      : 20165510
*   
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "sorting.h"
#include "LinkedList.h"

/* Counts how many lines in the array file*/
int procLine(char* filename)
{
    int lines = 1,ch;
    FILE *myFile;
    myFile = fopen(filename, "r");
    for (ch = getc(myFile); ch != EOF; ch = getc(myFile))
    {
         if (ch == '\n') 
         {
            lines++;
         }
     
    }
    fclose(myFile);
    return lines;
}

/* Reads the files */
void fileReader(double sleepTime,char* filename)
{
    char *error;
    int i,*arr,lines = 1;
	double time = sleepTime;
	FILE *myFile;
    myFile = fopen(filename, "r");
    lines = procLine(filename);
       
	for(i = 0; i< lines;i++)
	{
		arr = (int*)malloc(sizeof(int)*lines);
	}
    
    error = (char*)malloc( 128 * sizeof(char) );
    *error = '\0';
    if(myFile == NULL )
    {

        strncpy( error, "Error in opening file: ", 25 );
        strncat( error, strerror( errno ), 50 );
 
    }
    else if( ferror(myFile) )
    {

        strncpy( error, "Error in file reading: ", 25 );
        strncat( error, strerror( errno ), 50 );
        fclose(myFile);       

    }

    for (i = 0; i < lines; i++){
        fscanf(myFile, "%d ", &arr[i] );
    }

    sort(arr,lines,time);
    displaySorted(arr,lines);
    fclose(myFile);
    free(arr);
}


/* Creates log files */
char* logMaker(char* filename, linkedList* log, int j, int i)
{
    FILE* file;
    listNode* currNd;
    LogEntry* entry;

    char* error;
    file = fopen(filename, "w"); 
    error = (char*)malloc( 128 * sizeof(char) );
    *error = '\0';
    if( file == NULL )
    {

        strncpy( error, "Error in opening file: ", 25 );
        strncat( error, strerror( errno ), 50 );
 
    }
    else if( ferror( file ) )
    {

        strncpy( error, "Error in file reading: ", 25 );
        strncat( error, strerror( errno ), 50 );
        fclose( file );       

    }
    else
    {   
        currNd = log->head;
        while(currNd != NULL)
        {
            entry = (LogEntry*)currNd->value;
            if(entry->i != entry->j)
            {
                fprintf(file, "\nSwapped: %d and %d\n",entry->i,entry->j);
                currNd = currNd->next;
            }
            if(entry->i ==  entry->j)
            {
                fprintf(file, "\n%d is in the correct index position no swaps performed\n", entry->j);
                currNd = currNd->next;
            }
               
        }
        
        fclose( file );

    }
    if( *error == '\0' )
    {
        free( error );
        error = NULL;
    }

    return error;
}

/* Outputs file after the sorting */
void fileViewer(char* filename)
{
    char* error;
    char ch;
    FILE* file;
    file = fopen(filename, "r");
    error = (char*)malloc( 128 * sizeof(char));
    if( file == NULL )
    {
        strncpy( error, "Error in opening file: ", 25 );
        strncat( error, strerror( errno ), 50 );
 
    }

    do
    {
        ch = fgetc(file);
        putchar(ch);
    }while (ch !=EOF);
}
