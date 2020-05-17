#include "sdl.h"
#define WIDTH 700
#define HEIGHT 700

void draw(SDL_Renderer *renderer, struct ArrStruct myStruct)
{
    while (TRUE)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
                if (myStruct.playZone[i][j] == 1)
                {
                    SDL_Rect rpixel;
                    rpixel.x = i * (WIDTH / row);
                    rpixel.y = j * (HEIGHT / column);
                    rpixel.h = (WIDTH / row);
                    rpixel.w = (HEIGHT / column);
                    SDL_RenderFillRect(renderer, &rpixel);
                }
        }
        myStruct = countNeighbours(myStruct);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    // MOUSE INTERACTION
    int x, y;
    if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) // one & it is for bits AND
    {
        // USE COLOR
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

void function(struct ArrStruct myStruct)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Problem can not init SDL2 \n");
        exit(0);
    }

    SDL_Window *window = SDL_CreateWindow("Game of Life",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    assert(renderer != NULL);

    // SIMPLE EVENT & DRAWING LOOP
    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }
        draw(renderer, myStruct);
    }
    SDL_Quit();
}