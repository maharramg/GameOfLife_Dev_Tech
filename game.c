#include "game.h"

//! Prints array
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

//! Fills array with randomly generated cells
struct ArrStruct fillRandArray(struct ArrStruct myStruct)
{
    int cell = 0;
    srand((unsigned)time(NULL));

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

//! Counts 8 neighbours of each cell and decides its destiny
struct ArrStruct countNeighbours(struct ArrStruct myStruct)
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
                    else if (neigh_row == i && neigh_col == j)
                    {
                        continue;
                    }
                    else if (myStruct.playZone[neigh_row][neigh_col] == 1)
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

//! Checks the board. Either terminate the game or not
int checkForExistence(struct ArrStruct myStruct)
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

//! Makes copy of the current array
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

//! Compares 2 arrays
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

//! Show colorized cells
void printInConsole(struct ArrStruct myStruct)
{
    //! clear screen
    printf("\033[2J");

    //! hide cursor
    printf("\033[?25l");

    //! goto 0,0
    for (int i = 0; i < row; ++i)
    {
        printf("\033[%d;4H", i + 2);
        for (int j = 0; j < column; ++j)
        {
            if (myStruct.playZone[i][j] == 1)
            {
                myStruct.playZone[i][j] = 104;
            }
            else
            {
                myStruct.playZone[i][j] = 40;
            }

            printf("\033[%dm  ", myStruct.playZone[i][j]);
            //! draw 2 space with color 40 or 101 (black or magenta)
        }
        printf("\n");
    }

    //! show cursor
    printf("\033[?25h");
}

//! Game itself with all the functions that implemented
void playGame(struct ArrStruct myStruct, struct ArrStructCopy myStructCopy)
{
    myStruct = fillRandArray(myStruct);
    myStructCopy = makeCopy(myStructCopy, myStruct);
    printInConsole(myStruct);
    sleep(1);

    while (TRUE)
    {
        myStruct = countNeighbours(myStruct);

        if (compareArray(myStructCopy, myStruct))
        {
            printf("\nLast Generation:\n");
            printInConsole(myStruct);
            printf("\nLAST GENERATION REMAINS THE SAME: GAME OVER\n");
            exit(0);
        }

        printInConsole(myStruct);
        sleep(1);

        myStructCopy = makeCopy(myStructCopy, myStruct);

        int check = checkForExistence(myStruct);
        if (check == TRUE)
        {
            printf("\nALL CREATURES HAVE DIED: GAME OVER\n");
            exit(0);
        }
    }
}
