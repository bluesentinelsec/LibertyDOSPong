#include "loseScene.hpp"

#include "../dbg.h"

void LoseScene::Init(SceneManager *sceneManager)
{
    debug("LoseScene::Init");
    this->sceneManager = sceneManager;
}

void LoseScene::OnEnter(void)
{
    debug("LoseScene::OnEnter()");
    // load resources needed for this scene
    // create scene objects
}

void LoseScene::OnExit(void)
{
    debug("LoseScene::OnExit()");
    // free resources needed for this scene
    // free scene objects
}

void LoseScene::ProcessInput(void)
{
    debug("LoseScene::ProcessInput");
};

void LoseScene::Update(double DeltaTime)
{
    debug("LoseScene::Update");
    if (IsKeyPressedOnce(KEY_ENTER))
    {
        Credits *creditsScene = new Credits();
        creditsScene->Init(this->sceneManager);
        this->sceneManager->ChangeScene(creditsScene);
    }
    // for each object in scene
    // update the object
}

void LoseScene::Draw(BITMAP *backbuffer)
{
    debug("LoseScene::Draw");
    textprintf_ex(backbuffer, font, 2, 50, makecol(255, 255, 255), 0, "Lose Screen");
    // for each object in scene
    // draw the scene
}