#include "ObjectLibrary.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

SDL_Surface *loadImage( char* filePath ) 
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = IMG_Load( filePath );
    
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    else 
    {
        printf("Failed to load image <%s>\n", filePath);
    }
    
    //Return the optimized image
    return optimizedImage;
}

SDL_Color rgbToColor(uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color Color;
    Color.r = r;
    Color.g = g;
    Color.b = b;
    return Color;
}