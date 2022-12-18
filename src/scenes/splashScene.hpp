#pragma once

#include "../input.hpp"
#include "../scene.hpp"
#include "titleScene.hpp"

#include <allegro.h>

class SplashScene : public Scene
{
public:
    virtual void Init(SceneManager *sceneManager);
    virtual void OnEnter(void);
    virtual void OnExit(void);
    void ProcessInput(void);
    virtual void Update(double DeltaTime);
    virtual void Draw(BITMAP *backbuffer);
private:
    double elapsedTime;
};