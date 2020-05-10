#ifndef _INCLUDES_
#define _INCLUDES_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define row 20
#define column 20
#define TRUE 1
#define FALSE 0

struct ArrStruct
{
    int playZone[row][column];
};

struct ArrStructCopy
{
    int playZoneCopy[row][column];
};

void printArray(int arr[row][column]);
struct ArrStruct fillRandArray(struct ArrStruct myStruct);
struct ArrStruct countNeighbours(struct ArrStruct myStruct);
int checkForExistence(struct ArrStruct myStruct);
struct ArrStructCopy makeCopy(struct ArrStructCopy myStructCopy, struct ArrStruct myStruct);
int compareArray(struct ArrStructCopy myStructCopy, struct ArrStruct myStruct);
void playGame(struct ArrStruct myStruct, struct ArrStructCopy myStructCopy);
void ansiFunc(struct ArrStruct myStruct);

#endif