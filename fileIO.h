/*
*   STUDENT : JOHN LUMAGBAS
*   ID      : 20165510
*   Forward declarations for fileIO.h
*/


#ifndef FILEIO_H
#define FILEIO_H
#include "LinkedList.h"
int procLine(char* filename);
void fileReader(double sleepTime,char* filename);
char* logMaker(char* filename, linkedList* log, int j, int i);
void fileViewer(char* file);
#endif