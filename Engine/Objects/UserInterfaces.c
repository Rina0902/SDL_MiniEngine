#include "UserInterfaces.h"
#include "../Libraries/ObjectLibrary.h"

bool initializeUi(Obj_Ui* Object)
{
    printf("Initializing UI object with ID <%s>\n", Object->ObjectData.id);
    if (Object->Type == ButtonOnly || Object->Type == TextAndButton)
    {
        printf("Loading Images for UI object with ID <%s>\n", Object->ObjectData.id);
        Object->SurfaceDefault = loadImage(Object->surfaceDefaultPath);
        Object->SurfaceHovered = loadImage(Object->surfaceHoveredPath);
        Object->SurfacePressed = loadImage(Object->surfacePressedPath);
    }

    if (Object->Type == TextAndButton || Object->Type == TextOnly)
    {
        //If there was an error in loading the font
        if( Object->Font == NULL )
        {
            printf("Erorr font for UI object with ID <%s>\n", Object->ObjectData.id);
            return false;
        }
        printf("Creating Render Text for UI object with ID <%s>\n", Object->ObjectData.id);
        Object->SurfaceText = TTF_RenderText_Solid( Object->Font, Object->text, Object->TextColor );
        if (Object->SurfaceText == NULL)
        {
            printf("Error creating Surface text for UI object with ID <%s>\n", Object->ObjectData.id);
            return false;
        }
    }
    //If everything loaded fine
    return true;  
}


Obj_Ui* createUiObject(UiConstructParams ConstructParams)
{
    // allocate memory
    Obj_Ui* OutUi = malloc (sizeof (OutUi));
    if (OutUi == NULL)
    {
        return NULL;
    }
    OutUi->Font = malloc (sizeof (OutUi->Font));
    if (OutUi->Font == NULL)
    {
        printf("Error Memory Allocation for Front\n");
        return NULL;
    }

    char id[255];
    sprintf(id, "%p", OutUi);
    printf("Creating UI object with ID <%s>\n", id);

    // // set the position
    SDL_Rect Pos;
    Pos.x = ConstructParams.x;
    Pos.y = ConstructParams.y;

    // fill the variables into our structure
    OutUi->ObjectData.id = id;
    OutUi->ObjectData.position = Pos;
    OutUi->ObjectData.renderPriority = ConstructParams.renderPriority;

    OutUi->Type = ConstructParams.Type;

    // fill the variables for the button (if it exists)
    if (ConstructParams.Type == ButtonOnly || ConstructParams.Type == TextAndButton)
    {
        printf("Filling surfaces data for UI object with ID <%s>\n", id);
        OutUi->surfaceDefaultPath = ConstructParams.surfaceDefaultPath;
        OutUi->surfaceHoveredPath = ConstructParams.surfaceHoveredPath;
        OutUi->surfacePressedPath = ConstructParams.surfacePressedPath;
        // sound here
    }
    // fill the variables for the text (if it exists)
    if (ConstructParams.Type == TextOnly || ConstructParams.Type == TextAndButton)
    {
        printf("Filling text data for UI object with ID <%s>\n", id);
        OutUi->text = ConstructParams.text;
        OutUi->Font = ConstructParams.Font;
        OutUi->TextColor = ConstructParams.TextColor;
    }

    initializeUi(OutUi);

    return OutUi;
}

Obj_Ui* createText( char* text, 
                    const uint8_t size, 
                    const char* font,
                    const int x,
                    const int y, 
                    const uint8_t colorR, 
                    const uint8_t colorG, 
                    const uint8_t colorB)
{
    UiConstructParams Button_UiConstructParams;
    Button_UiConstructParams.Type = TextOnly;
    Button_UiConstructParams.text = text;
    Button_UiConstructParams.TextColor = rgbToColor(colorR, colorG, colorB);
    Button_UiConstructParams.Font = TTF_OpenFont(font, size);
    Button_UiConstructParams.x = x;
    Button_UiConstructParams.y = y;
    Button_UiConstructParams.renderPriority = 0;

    Obj_Ui *Text = createUiObject(Button_UiConstructParams);
}
void clearUi(Obj_Ui* Object)
{
    if(Object->SurfaceDefault != NULL)
    {
        SDL_FreeSurface(Object->SurfaceDefault);
    }
    if(Object->SurfaceHovered != NULL)
    {
        SDL_FreeSurface(Object->SurfaceHovered);
    }
    if(Object->SurfacePressed != NULL)
    {
        SDL_FreeSurface(Object->SurfacePressed);
    }
    if(Object->SurfaceText != NULL)
    {
        SDL_FreeSurface(Object->SurfaceText);
    }
    //Close the font that was used
    TTF_CloseFont(Object->Font);
}
