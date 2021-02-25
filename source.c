//The headers
#include "SDL/SDL.h"
#include "header.h"
#include "SDL/SDL_image.h"
#include <string.h>

SDL_Surface *load_image( char* filename ) 
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = IMG_Load( filename );
    
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    
    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}


bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;    
    }
    
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "TTF Test", NULL );
    
    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the background image
    background = load_image( "background.jpeg" );
    
    //Open the font
    font = TTF_OpenFont( "MilkyNice.ttf", 28 );
    
    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;    
    }
    
    //If there was an error in loading the font
    if( font == NULL )
    {
        printf("Font loading error");
        return false;
    }
    
    //If everything loaded fine
    return true;    
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( message );
    
    //Close the font that was used
    TTF_CloseFont( font );
    
    //Quit SDL_ttf
    TTF_Quit();
    
    //Quit SDL
    SDL_Quit();
}
