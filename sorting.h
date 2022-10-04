/*
*   STUDENT : JOHN LUMAGBAS
*   ID      : 20165510
*   Forward declarations for sorting.c
*/


#ifndef SORTING_H
#define SORTING_H
#include "LinkedList.h"
typedef struct
{
    int i;
    int j;

}LogEntry;
void iterLog(linkedList* log, int i,int j);
void swap(int *x,int *y, int *pos);
void sort(int inArray[], int size, double sleepTime);
void displaySorted(int inArray[], int size);
#endif