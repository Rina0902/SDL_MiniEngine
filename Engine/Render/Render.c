#include "Render.h"
#include "../Engine.h"

void initializeRender()
{
    WorldStaticQueueSize = 0;
    UiQueueSize = 0;
}

void addWoldStaticToRenderQueue(Obj_World_Static* Object)
{
    // TODO : consider render priority
    WorldStaticQueue[WorldStaticQueueSize] = Object;
    WorldStaticQueueSize ++;
}

void addUiToRenderQueue(Obj_Ui* Object)
{
    // TODO : consider render priority
    UiQueue[UiQueueSize] = Object;
    UiQueueSize ++;
}

void removeWoldStaticFromRenderQueue(const char* objectId)
{

}

void removeUiFromRenderQueue(const char* objectId)
{

}

void renderWorldStatic(Obj_World_Static* Object)
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = Object->ObjectData.position.x;
    offset.y = Object->ObjectData.position.y;
    
    //Blit the surface
    SDL_BlitSurface( Object->Surface, NULL, MainScreen, &offset );
}

void renderUi(Obj_Ui* Object)
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = Object->ObjectData.position.x;
    offset.y = Object->ObjectData.position.y;
    
    if (Object->Type == ButtonOnly || Object->Type == TextAndButton)
    {
        //Blit the surface
        if (Object->isPressed && Object->SurfacePressed != NULL)
        {
            SDL_BlitSurface( Object->SurfacePressed, NULL, MainScreen, &offset);
        }
        else if (Object->isHovered && Object->SurfaceHovered != NULL)
        {
            SDL_BlitSurface( Object->SurfaceHovered, NULL, MainScreen, &offset);
        }
        else if (Object->SurfaceDefault != NULL)
        {
            SDL_BlitSurface( Object->SurfaceDefault, NULL, MainScreen, &offset);
        }
    }
    if (Object->Type == TextAndButton || Object->Type == TextOnly)
    {
        if (Object->SurfaceText != NULL)
            SDL_BlitSurface( Object->SurfaceText, NULL, MainScreen, &offset);
    }
}

void processRenderQueue()
{
    if( SDL_Flip( MainScreen ) == -1 )
    {
        return;   
    }
    
    // Render all world statics
    for (uint16_t i = 0 ; i < WorldStaticQueueSize ; i++)
    {
        renderWorldStatic(WorldStaticQueue[i]);
    }
    // Render all ui
    for (uint16_t i = 0 ; i < UiQueueSize ; i++)
    {
        renderUi(UiQueue[i]);
    }
}