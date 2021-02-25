#pragma once

#include "SDL/SDL.h"
#include "../Objects/Objects.h"
#include "../Objects/UserInterfaces.h"

Obj_World_Static* WorldStaticQueue[50];
Obj_Ui* UiQueue[50];

uint32_t WorldStaticQueueSize;
uint32_t UiQueueSize;

// Initialize Render
void initializeRender();

// Manage queues
void addWoldStaticToRenderQueue(Obj_World_Static* Object);
void addUiToRenderQueue(Obj_Ui* Object);
void removeWoldStaticFromRenderQueue(const char* objectId);
void removeUiFromRenderQueue(const char* objectId);

// Rendering
void renderWorldStatic(Obj_World_Static* Object);
void renderUi(Obj_Ui* Object);
void processRenderQueue();