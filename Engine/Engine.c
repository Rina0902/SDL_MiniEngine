#include "Engine.h"
#include "SDL/SDL_ttf.h"

bool initializeEngine(  const int screenWidth, 
                        const int screenHeight, 
                        const int screenBpp,
                        const char* windowCaption,
                        const char* iconPath)
{
    // Setting whether the engine should quit or not
    shouldQuitEngine = false;

    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        // logs
        printf("Error SDL_Init\n");
        return false;    
    }
    
    //Set up the screen
    MainScreen = SDL_SetVideoMode( screenWidth, screenHeight, screenBpp, SDL_SWSURFACE );
    
    //If there was an error in setting up the screen
    if( MainScreen == NULL )
    {
        // logs
        printf("Error SDL_SetVideoMode\n");
        return false;    
    }
    
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        // logs
        printf("Error TTF_Init\n");
        return false;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( windowCaption, iconPath);
    
    //If everything initialized fine
    return true;
}

void handleInputs()
{
    //While there's an event to handle
    while(SDL_PollEvent(&event))
    {
        //If the user has Xed out the window
        if( event.type == SDL_QUIT )
        {
            //Quit the program
            shouldQuitEngine = true;
        }    
    }
}
void quitEngine()
{    
    printf("Quitting the engine\n");

    //Quit SDL_ttf
    TTF_Quit();
    
    //Quit SDL
    SDL_Quit();
}
