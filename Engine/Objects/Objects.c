#include "Objects.h"
#include "../Libraries/ObjectLibrary.h"

bool initializeWorldStatic(Obj_World_Static *Object)
{
    // Initlialize surface to our Object
    SDL_Surface* resultImage = loadImage(Object->surfacePath);
    if (resultImage != NULL)
    {
        Object->Surface = resultImage;   
        return true;
    }
    return false;
}

Obj_World_Static* createWorldStaticObject(char* path, const int x, const int y, const float distanceToCamera, const int renderPriority)
{
    // allocate memory
    Obj_World_Static* OutWorldStatic = malloc (sizeof (Obj_World_Static));
    if (OutWorldStatic == NULL)
    {
        return NULL;
    }

    char id[255];
    sprintf(id, "%p", OutWorldStatic);
    printf("Creating world static object with ID <%s>\n", id);

    // // set the position
    SDL_Rect Pos;
    Pos.x = x;
    Pos.y = y;

    // fill the variables into our structure
    OutWorldStatic->ObjectData.id = id;
    OutWorldStatic->ObjectData.position = Pos;
    OutWorldStatic->ObjectData.renderPriority = renderPriority;
    OutWorldStatic->distanceToCamera = distanceToCamera;
    OutWorldStatic->surfacePath = path;
    initializeWorldStatic(OutWorldStatic);

    return OutWorldStatic;
}

void clearWorldStatic(Obj_World_Static *Object)
{
    SDL_FreeSurface(Object->Surface);
}
