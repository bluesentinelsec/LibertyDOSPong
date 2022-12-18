#include "winScene.hpp"

#include "../dbg.h"

void WinScene::Init(SceneManager *sceneManager)
{
    debug("WinScene::Init");
    this->sceneManager = sceneManager;
}

void WinScene::OnEnter(void)
{
    debug("WinScene::OnEnter()");
    // load resources needed for this scene
    // create scene objects
}

void WinScene::OnExit(void)
{
    debug("WinScene::OnExit()");
    // free resources needed for this scene
    // free scene objects
}

void WinScene::ProcessInput(void)
{
    debug("WinScene::ProcessInput");
};

void WinScene::Update(double DeltaTime)
{
    debug("WinScene::Update");
    if (IsKeyPressedOnce(KEY_ENTER))
    {
        Credits *creditsScene = new Credits();
        creditsScene->Init(this->sceneManager);
        this->sceneManager->ChangeScene(creditsScene);
    }
    // for each object in scene
    // update the object
}

void WinScene::Draw(BITMAP *backbuffer)
{
    debug("WinScene::Draw");
    textprintf_ex(backbuffer, font, 2, 50, makecol(255, 255, 255), 0, "Win Screen");
    // for each object in scene
    // draw the scene
}