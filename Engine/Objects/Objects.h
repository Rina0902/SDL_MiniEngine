#pragma once

#include "../Engine.h"
#include "SDL/SDL_image.h"
#include <stdbool.h>

#define SURFACE_SIZE 20

typedef struct Obj_World_Static
{
    Object ObjectData;
    char *surfacePath;
    SDL_Surface* Surface;
    float distanceToCamera;
    
} Obj_World_Static;

bool initializeWorldStatic(Obj_World_Static *Object);
Obj_World_Static* createWorldStaticObject(char* path, const int x, const int y, const float distanceToCamera, const int renderPriority);
void clearWorldStatic(Obj_World_Static *Object);
