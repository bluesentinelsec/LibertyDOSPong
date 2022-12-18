#pragma once

#include "../scene.hpp"
#include "../input.hpp"
#include "titleScene.hpp"

#include <allegro.h>

class Credits : public Scene
{
public:
    virtual void Init(SceneManager *sceneManager);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    void ProcessInput(void);
    virtual void Update(double DeltaTime);
    virtual void Draw(BITMAP *backbuffer);
};