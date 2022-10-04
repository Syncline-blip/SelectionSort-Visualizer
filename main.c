/*
*   STUDENT : JOHN LUMAGBAS
*   ID      : 20165510
*   main.c
*/



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>


/*------------------------------*/

#include "fileIO.h"
#include "sorting.h"
#include "randArray.h"
int main(int argc, char *argv[])
{

    int input=0;
    if(argc != 3 && argc !=2)
    {
        printf("-----------------------------------------------------------");
        printf("\nCorrect usage: \n");
        printf("For Random sorting -> ./main <animation speed>\n");
        printf("For specific file -> ./main <animation speed> <file name>\n");
        printf("-----------------------------------------------------------\n");
    }
    else if(argc<=2)
    {
        double timerRand = atof(argv[1]);
        printf("-----------------------------------------------------------");
        printf("\nPlease enter an array of size from 3-10: ");
        scanf("%d",&input);
        if(input <= 10 && input >=3)
        {
            genArr(input,timerRand);
            printf("\nLog File:");
            fileViewer("logs.txt");
        }
        else
        {
            printf("ARRAY SIZE NOT IN RANGE");
        }
    }
    else if (argc>=2)
    {

        double time = atof(argv[1]);
        fileReader(time,argv[2]);
        printf("\nLog File:");
        fileViewer("logs.txt");
    }
    
    return 0;
}