//The headers
#include "Engine/Engine.h"
#include "Engine/Render/Render.h"
#include "Engine/Libraries/ObjectLibrary.h"
#include "Engine/Objects/Objects.h"

int main( int argc, char* args[] )
{
    SDL_Color textColor = { 255, 255, 255 };
    
    initializeEngine(1300, 720, 32, "NYA", "Resources/Images/icon/grim-reaper.ico");
    initializeRender();

    Obj_World_Static *Background = createWorldStaticObject("Resources/Images/Backgrounds/background.bmp", 0, 0, 5, 0);
    addWoldStaticToRenderQueue(Background);

    Obj_Ui* Text = createText(  "NYA!~~~", 20, "Resources/Fonts/MilkyNice.ttf", 0, 0, 255, 150, 180);
    addUiToRenderQueue(Text);

    while (!shouldQuitEngine)
    {
        handleInputs();
        processRenderQueue();
    }
    
    quitEngine();
    return 0;    
}