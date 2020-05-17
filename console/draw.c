#include "draw.h"

//Show colorized cells
void printInConsole(struct ArrStruct myStruct)
{
    // clear screen
    printf("\033[2J");

    // hide cursor
    printf("\033[?25l");

    // goto 0,0
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
            // draw 2 space with color 40 or 101 (black or magenta)
        }
        printf("\n");
    }

    //show cursor
    printf("\033[?25h");
}
