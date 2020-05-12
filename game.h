#ifndef _GAME_
#define _GAME_

#include <stdio.h>  
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define row 20
#define column 20
#define TRUE 1
#define FALSE 0

// Struct that keeps our main 2D array which we are working with
struct ArrStruct
{
    int playZone[row][column];
};

// Copy of the struct above
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
void printInConsole(struct ArrStruct myStruct);

#endif
