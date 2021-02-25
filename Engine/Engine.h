#pragma once

#include "SDL/SDL.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct Object
{
    char* id;
    SDL_Rect position;
    int16_t renderPriority;

} Object;

SDL_Surface *MainScreen;

//The event structure that will be used
SDL_Event event;

// Whether quit the engine or not
bool shouldQuitEngine;


bool initializeEngine(  const int screenWidth, 
                        const int screenHeight, 
                        const int screenBpp,
                        const char* windowCaption,
                        const char* iconPath);

void handleInputs();
void quitEngine();