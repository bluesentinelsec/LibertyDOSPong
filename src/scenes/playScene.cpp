#include "playScene.hpp"

#include "../dbg.h"

void PlayScene::Init(SceneManager *sceneManager)
{
    debug("PlayScene::Init");
    this->sceneManager = sceneManager;
}

void PlayScene::OnEnter(void)
{
    debug("PlayScene::OnEnter()");
    // load resources needed for this scene
    // create scene objects
}

void PlayScene::OnExit(void)
{
    debug("PlayScene::OnExit()");
    // free resources needed for this scene
    // free scene objects
}

void PlayScene::ProcessInput(void)
{
    debug("PlayScene::ProcessInput");
};

void PlayScene::Update(double DeltaTime)
{
    debug("PlayScene::Update");
    if (IsKeyPressedOnce(KEY_1))
    {
        WinScene *winScene = new WinScene();
        winScene->Init(this->sceneManager);
        this->sceneManager->ChangeScene(winScene);
    }

    if (IsKeyPressedOnce(KEY_2))
    {
        LoseScene *loseScene = new LoseScene();
        loseScene->Init(this->sceneManager);
        this->sceneManager->ChangeScene(loseScene);
    }
    // for each object in scene
    // update the object
}

void PlayScene::Draw(BITMAP *backbuffer)
{
    debug("PlayScene::Draw");
    textprintf_ex(backbuffer, font, 2, 50, makecol(255, 255, 255), 0, "Play Screen");
    // for each object in scene
    // draw the scene
}