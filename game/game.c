#include "game.h"
#include "../console/draw.h"
#include "../sdl/sdl.h"

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

struct ArrStruct countNeighboursClipped(struct ArrStruct myStruct)
{
    int neighbors;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            neighbors = 0;

            for (int a = -1; a <= 1; a++)
            {
                for (int b = -1; b <= 1; b++)
                {
                    int neigh_row = i + a;
                    int neigh_col = j + b;

                    if (neigh_col < 0 || neigh_row < 0 || neigh_col >= row || neigh_row >= column)
                    {
                        continue;
                    }

                    if (neigh_row == i && neigh_col == j)
                    {
                        continue;
                    }

                    if (myStruct.playZone[neigh_row][neigh_col] == 1)
                    {
                        neighbors++;
                    }
                }
            }

            if (myStruct.playZone[i][j] == 0 && neighbors == 3)
            {
                myStruct.playZone[i][j] = 1;
            }
            else if (myStruct.playZone[i][j] == 1 && (neighbors < 2 || neighbors > 3))
            {
                myStruct.playZone[i][j] = 0;
            }
        }
    }
    return myStruct;
}

struct ArrStruct countNeighboursCircular(struct ArrStruct myStruct)
{
    int neighbors;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            neighbors = 0;

            for (int a = -1; a <= 1; a++)
            {
                for (int b = -1; b <= 1; b++)
                {
                    int neigh_row = i + a;
                    int neigh_col = j + b;

                    if (neigh_col < 0 || neigh_row < 0 || neigh_col >= row || neigh_row >= column)
                    {
                        neigh_row = (i + a + row) % row;
                        neigh_col = (j + b + column) % column;
                    }

                    if (neigh_row == i && neigh_col == j)
                    {
                        continue;
                    }

                    if (myStruct.playZone[neigh_row][neigh_col] == 1)
                    {
                        neighbors++;
                    }
                }
            }

            if (myStruct.playZone[i][j] == 0 && neighbors == 3)
            {
                myStruct.playZone[i][j] = 1;
            }
            else if (myStruct.playZone[i][j] == 1 && (neighbors < 2 || neighbors > 3))
            {
                myStruct.playZone[i][j] = 0;
            }
        }
    }
    return myStruct;
}

int checkForNotExist(struct ArrStruct myStruct)
{
    int creatures = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
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

struct ArrStruct makeCopy(struct ArrStruct myStructCopy, struct ArrStruct myStruct)
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

int compareArray(struct ArrStruct myStructCopy, struct ArrStruct myStruct)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (myStructCopy.playZoneCopy[i][j] != myStruct.playZone[i][j])
                return FALSE;
        }
    }
    return TRUE;
}

void playGame(struct ArrStruct myStructCopy, struct ArrStruct myStruct)
{
    myStruct = fillRandArray(myStruct);

    int choicePrint = 0;

    printf("Enter 1 for clipped version || 2 for circular version:\n");
    scanf("%d", &choiceVersion);

    printf("Enter 1 to visualize in console || 2 to visualize in sdl:\n");
    scanf("%d", &choicePrint);

    if (choicePrint == 1)
    {
        printf("\nFirst Generation:\n");
        printInConsole(myStruct);
        sleep(1);

        while (TRUE)
        {
            if (choiceVersion == 1)
            {
                myStruct = countNeighboursClipped(myStruct);
            }
            else if (choiceVersion == 2)
            {
                myStruct = countNeighboursCircular(myStruct);
            }
            else
            {
                printf("Invalid input! Input should be either 1 or 2 !");
                exit(0);
            }

            if (compareArray(myStructCopy, myStruct))
            {
                printf("\nLast Generation:\n");
                printInConsole(myStruct);
                printf("\nLAST GENERATION REMAINS THE SAME: GAME OVER\n");
                exit(0);
            }

            printf("\nNext generation:\n");
            printInConsole(myStruct);
            sleep(1);

            myStructCopy = makeCopy(myStructCopy, myStruct);

            int check = checkForNotExist(myStruct);
            if (check == TRUE)
            {
                printf("\nALL CREATURES HAVE DIED: GAME OVER\n");
                exit(0);
            }
        }
    }
    else if (choicePrint == 2)
    {
        function(myStruct);
    }
    else
    {
        printf("Invalid input! Input should be either 1 or 2 !");
        exit(0);
    }
}
