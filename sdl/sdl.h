#ifndef _SDL_
#define _SDL_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "../game/game.h"

void function(struct ArrStruct myStruct);
void draw(SDL_Renderer *renderer, struct ArrStruct myStruct);

#endif