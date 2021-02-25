#pragma once

#include "SDL/SDL.h"

SDL_Surface *loadImage( char* filePath );

SDL_Color rgbToColor(uint8_t r, uint8_t g, uint8_t b);