#ifndef _GAME_
#define _GAME_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define row 10
#define column 10
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
int playGame(struct ArrStruct myStruct, struct ArrStructCopy myStructCopy);

#endif
