#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define row 5
#define column 5

const int TRUE = 1;
const int FALSE = 0;

//Struct that keeps our main 2D array which we are working with
struct ArrStruct
{
    int playZone[row][column];
};

void printArray(int arr[row][column]);
struct ArrStruct fillArray(struct ArrStruct myStruct);
struct ArrStruct fillRandArray(struct ArrStruct myStruct);

//Main function
int main(int argc, char const *argv[])
{
    struct ArrStruct array;

    array = fillRandArray(array);
    printf("First generation: (1's are living cells | 0's are dead cells)\n");
    printArray(array.playZone);

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
