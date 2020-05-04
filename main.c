#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define row 10
#define column 10

const int TRUE = 1;
const int FALSE = 0;

//Struct that keeps our main 2D array which we are working with
struct ArrStruct
{
    int playZone[row][column];
};

//Copy of the struct above
struct ArrStructCopy
{
    int playZoneCopy[row][column];
};

void printArray(int arr[row][column]);
struct ArrStruct fillArray(struct ArrStruct myStruct);
struct ArrStruct fillRandArray(struct ArrStruct myStruct);
struct ArrStruct countNeighbours(struct ArrStruct myStruct);
struct ArrStruct checkNewborns(struct ArrStruct myStruct);
int checkForExistence(struct ArrStruct myStruct);
struct ArrStructCopy makeCopy(struct ArrStructCopy myStructCopy, struct ArrStruct myStruct);
int compareArray(struct ArrStructCopy myStructCopy, struct ArrStruct myStruct);
void playGame(struct ArrStruct myStruct, struct ArrStructCopy myStructCopy);

//Main function
int main(int argc, char const *argv[])
{
    struct ArrStruct array;
    struct ArrStructCopy arrayCopy;

    playGame(array, arrayCopy);

    return 0;
}

//Prints array
void printArray(int arr[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//Fills array with randomly generated cells
struct ArrStruct fillRandArray(struct ArrStruct myStruct)
{
    int cell = 0;
    srand((unsigned)time(NULL));
    // Set Random Alive Cells in an Array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cell = rand() % 2;
            if (cell == 1)
            {
                myStruct.playZone[i][j] = 1;
            }
            else
            {
                myStruct.playZone[i][j] = 0;
            }
        }
    }
    return myStruct;
}

//Counts 8 neighbours of each cell and decides either it dies or remains alive
struct ArrStruct countNeighbours(struct ArrStruct myStruct)
{
    int neighbors;

    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < column - 1; j++)
        {
            neighbors = 0;

            if (myStruct.playZone[i][j] == 1)
            {
                if (myStruct.playZone[i][j + 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i + 1][j + 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i + 1][j] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i + 1][j - 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i][j - 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i - 1][j - 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i - 1][j] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i - 1][j + 1] == 1)
                {
                    neighbors++;
                }

                if ((neighbors == 2) || (neighbors == 3))
                {
                    myStruct.playZone[i][j] = 1; /*live*/
                }
                else if ((neighbors < 2) || (neighbors >= 4))
                {
                    myStruct.playZone[i][j] = 0; /*die*/
                }
            }
        }
    }
    return myStruct;
}

//Checks if dead cells are going to reborn or not
struct ArrStruct checkNewborns(struct ArrStruct myStruct)
{
    int neighbors;
    int a, b;

    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < column - 1; j++)
        {
            neighbors = 0;

            if (myStruct.playZone[i][j] == 0)
            {
                if (myStruct.playZone[i][j + 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i + 1][j + 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i + 1][j] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i + 1][j - 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i][j - 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i - 1][j - 1] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i - 1][j] == 1)
                {
                    neighbors++;
                }
                if (myStruct.playZone[i - 1][j + 1] == 1)
                {
                    neighbors++;
                }
                if ((neighbors == 3))
                {
                    myStruct.playZone[i][j] = 1; /*newborn*/
                }
            }
        }
    }
    return myStruct;
}

//Checks the board if there is any creatures in order to know if terminate the game or not
int checkForExistence(struct ArrStruct myStruct)
{
    int creatures = 0;
    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < column - 1; j++)
        {
            if (myStruct.playZone[i][j] == 1)
                creatures++;
        }
    }
    if (creatures == 0)
        return TRUE; /*all creatures died*/
    else
        return FALSE; /*there are still living creatures*/
}

//Makes copy of the current array
struct ArrStructCopy makeCopy(struct ArrStructCopy myStructCopy, struct ArrStruct myStruct)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            myStructCopy.playZoneCopy[i][j] = myStruct.playZone[i][j];
        }
    }
    return myStructCopy;
}

//Compares 2 arrays
int compareArray(struct ArrStructCopy myStructCopy, struct ArrStruct myStruct)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (myStructCopy.playZoneCopy[i][j] != myStruct.playZone[i][j])
                return 0;
        }
    }
    return 1;
}

//Game itself with all the functions that implemented
void playGame(struct ArrStruct myStruct, struct ArrStructCopy myStructCopy)
{
    myStruct = fillRandArray(myStruct);
    printf("\nFirst Generation:\n");
    printArray(myStruct.playZone);
    sleep(1);

    while (TRUE)
    {
        myStruct = countNeighbours(myStruct);
        myStruct = checkNewborns(myStruct);

        if (compareArray(myStructCopy, myStruct))
        {
            printf("\nLast Generation:\n");
            printArray(myStruct.playZone);
            printf("\nLAST GENERATION REMAINS THE SAME: GAME OVER\n");
            exit(0);
        }

        printf("\nNext generation:\n");
        printArray(myStruct.playZone);
        sleep(1);

        myStructCopy = makeCopy(myStructCopy, myStruct);

        int check = checkForExistence(myStruct);
        if (check == TRUE)
        {
            printf("\nALL CREATURES HAVE DIED: GAME OVER");
            exit(0);
        }
    }
}