/*
*   STUDENT : JOHN LUMAGBAS
*   ID      : 20165510
*   
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"
#include "randArray.h"

/* Creates a random array and takes in sleeptime */
void genArr(int size, double sleepTime)
{
    int i,*arr;
    arr=(int*)malloc(sizeof(int)*size);
    for(i=0; i<size;i++)
    {
        arr[i] = ((double)rand()/RAND_MAX)*(999-0)+0;
    }
    sort(arr,size,sleepTime);
    displaySorted(arr,size);
    free(arr);
}