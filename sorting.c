/*
*   STUDENT : JOHN LUMAGBAS
*   ID      : 20165510
*   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "newSleep.h"
#include "sorting.h"
#include "LinkedList.h"
#include "fileIO.h"
#include "randArray.h"
#include "colors.h"
/* Selection Sort (Practice-based implementation) */

void iterLog(linkedList* log, int i,int j)
{
    LogEntry* entry = (LogEntry*)malloc(sizeof(LogEntry));
	entry->i = i;
	entry->j = j;
	insertLast(log,entry);

}
/* Generic Swap Functions when needed to swap elements*/
void swap(int *x,int *y, int *pos)
{
    int temp = *x;
    int posTemp = *pos +1;
    *x = *y;
    *y = temp;
    if(x==y)
    {   
        printf("\n\nValue number %d is ", posTemp);
        printf(GRE "%03d ", *y);
        printf(reset);
        printf(" no swap performed, already in correct index position.\n");
    }
    if(x!=y)
    {
        printf("\n\nValue number %d is ", posTemp);
        printf(RED "%03d ", *y);
        printf(reset);
        printf(" after swapping with: ");
        printf(GRE"%d\n", *x);
        printf(reset);
    }
    
}


/* Actual Sorting Method */
void sort(int inArray[], int size, double sleepTime)
{
    int i,j,minIdx;
    linkedList*logs = NULL;
	logs = createLinkedList();
    for(i=0; i < size;i++)
    {
        newSleep(sleepTime);
        displaySorted(inArray,size);
        minIdx = i;
        for(j=i+1;j < size;j++) 
        {
            if(inArray[j] < inArray[minIdx])
            {
                minIdx = j;
            }
        }
        swap(&inArray[minIdx], &inArray[i], &i);
        iterLog(logs,inArray[minIdx],inArray[i]);
        logMaker("logs.txt",logs,inArray[minIdx],inArray[i]);
    }
}

/* Display Method*/
void displaySorted(int inArray[], int size)
{
    int i;
    for(i=0; i<size;i++)
    {
        printf("%03d ", inArray[i]);
        printf("\t");
    }
    printf("\n");
}


