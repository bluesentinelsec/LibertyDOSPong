#pragma once

#include "sceneManager.hpp"
#include <allegro.h>

// forward declaration
class SceneManager;

class Scene
{
public:
    SceneManager *sceneManager;
    virtual void Init(SceneManager *sceneManager) = 0;
    virtual void OnEnter(void) = 0;
    virtual void OnExit(void) = 0;
    virtual void ProcessInput(void) = 0;
    virtual void Update(double DeltaTime) = 0;
    virtual void Draw(BITMAP *backbuffer) = 0;
};