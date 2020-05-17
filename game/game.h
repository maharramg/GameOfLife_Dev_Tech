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

int choiceVersion;

struct ArrStruct
{
    int playZone[row][column];
    int playZoneCopy[row][column];
};

struct ArrStruct array;

void printArray(int arr[row][column]);
struct ArrStruct fillRandArray(struct ArrStruct myStruct);
struct ArrStruct countNeighboursClipped(struct ArrStruct myStruct);
struct ArrStruct countNeighboursCircular(struct ArrStruct myStruct);
int checkForNotExist(struct ArrStruct myStruct);
struct ArrStruct makeCopy(struct ArrStruct myStructCopy, struct ArrStruct myStruct);
int compareArray(struct ArrStruct myStructCopy, struct ArrStruct myStruct);
void playGame(struct ArrStruct myStruct, struct ArrStruct myStructCopy);

#endif
