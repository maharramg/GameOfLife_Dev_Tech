#include "./game/game.h"
#include "./console/draw.h"
#include "./sdl/sdl.h"

int main(int argc, char const *argv[])
{
    struct ArrStruct array;
    struct ArrStructCopy arrayCopy;

    playGame(array, arrayCopy);

    return 0;
}