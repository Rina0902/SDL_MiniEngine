#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string.h>
#include <stdbool.h>
#include "SDL/SDL_ttf.h"

//The surfaces
SDL_Surface *background;
SDL_Surface *screen;
SDL_Surface *message;

//Screen attributes
int SCREEN_WIDTH ;
int SCREEN_HEIGHT;
int SCREEN_BPP ;

//The font that's going to be used
TTF_Font *font;

//The color of the font
SDL_Color textColor;

//The event structure that will be used
SDL_Event event;

//Functions:
SDL_Surface *load_image( char* filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
bool init();
bool load_files();
void clean_up();
SDL_Rect Rect_pos ( int x, int y, int w, int h);