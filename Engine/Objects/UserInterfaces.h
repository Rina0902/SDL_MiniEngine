#pragma once

#include "../Engine.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <stdint.h>

enum UiType{
    TextOnly = 0,
    ButtonOnly = 1,
    TextAndButton = 2
};

TTF_Font *MainFont;

typedef struct Obj_Ui
{
    /**
     * Main Object Data
     */
    Object ObjectData;

    /**
     * Ui specific
     */
    enum UiType Type; 

    /**
     * Surfaces/Images Data
     */

    bool isPressed;
    bool isHovered;
    // File paths 
    char* surfaceDefaultPath;
    char* surfaceHoveredPath;
    char* surfacePressedPath;
    // Surfaces
    SDL_Surface* SurfaceDefault;
    SDL_Surface* SurfaceHovered;
    SDL_Surface* SurfacePressed;
    
    /**
     * Text Data
     */
    char* text;
    TTF_Font *Font;
    SDL_Color TextColor;
    SDL_Surface* SurfaceText;
    
    /**
     * Sound Data
     */

    // OnPressed
    // OnHovered


} Obj_Ui;


typedef struct UiConstructParams
{
    enum UiType Type;  
    
    int x; 
    int y;
    int renderPriority;

    // Surface paths 
    char* surfaceDefaultPath;
    char* surfaceHoveredPath;
    char* surfacePressedPath;
    
    // Text data
    char* text;
    TTF_Font* Font;
    SDL_Color TextColor;

    // Sound data

} UiConstructParams;

bool initializeUi(Obj_Ui* Object);

Obj_Ui* createUiObject(UiConstructParams ConstructParams);

Obj_Ui* createText( char* text, 
                    const uint8_t size, 
                    const char* font,
                    const int x,
                    const int y, 
                    const uint8_t colorR, 
                    const uint8_t colorG, 
                    const uint8_t colorB);

void clearUi(Obj_Ui* Object);