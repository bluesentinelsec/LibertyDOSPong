#include "titleScene.hpp"

#include "../dbg.h"

void TitleScene::Init(SceneManager *sceneManager)
{
    debug("TitleScene::Init");
    this->sceneManager = sceneManager;
}

void TitleScene::OnEnter(void)
{
    debug("TitleScene::OnEnter()");
    // load resources needed for this scene
    // create scene objects
}

void TitleScene::OnExit(void)
{
    debug("TitleScene::OnExit()");
    // free resources needed for this scene
    // free scene objects
}

void TitleScene::ProcessInput(void)
{
    debug("TitleScene::ProcessInput");
};

void TitleScene::Update(double DeltaTime)
{
    debug("TitleScene::Update");
    if (IsKeyPressedOnce(KEY_ENTER))
    {
        PlayScene *playScene = new PlayScene();
        playScene->Init(this->sceneManager);
        this->sceneManager->ChangeScene(playScene);
    }
    // for each object in scene
    // update the object
}

void TitleScene::Draw(BITMAP *backbuffer)
{
    debug("TitleScene::Draw");
    textprintf_ex(backbuffer, font, 2, 50, makecol(255, 255, 255), 0, "Title Screen");
    // for each object in scene
    // draw the scene
}