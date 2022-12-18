#include "creditsScene.hpp"

#include "../dbg.h"

void Credits::Init(SceneManager *sceneManager)
{
    debug("Credits::Init");
    this->sceneManager = sceneManager;
}

void Credits::OnEnter(void)
{
    debug("Credits::OnEnter()");
    // load resources needed for this scene
    // create scene objects
}

void Credits::OnExit(void)
{
    debug("Credits::OnExit()");
    // free resources needed for this scene
    // free scene objects
}

void Credits::ProcessInput(void)
{
    debug("Credits::ProcessInput");
};

void Credits::Update(double DeltaTime)
{
    debug("Credits::Update");
    if (IsKeyPressedOnce(KEY_ENTER))
    {
        TitleScene *titleScene = new TitleScene();
        titleScene->Init(this->sceneManager);
        this->sceneManager->ChangeScene(titleScene);
    }
    // for each object in scene
    // update the object
}

void Credits::Draw(BITMAP *backbuffer)
{
    debug("Credits::Draw");
    textprintf_ex(backbuffer, font, 2, 50, makecol(255, 255, 255), 0, "Credits Screen");
    // for each object in scene
    // draw the scene
}