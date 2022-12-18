#include "splashScene.hpp"

#include "../dbg.h"

void SplashScene::Init(SceneManager *sceneManager)
{
    debug("SplashScene::Init");
    this->sceneManager = sceneManager;
    this->elapsedTime = 0.0f;
}

void SplashScene::OnEnter(void)
{
    debug("SplashScene::OnEnter()");
    // load resources needed for this scene
    // create scene objects
}

void SplashScene::OnExit(void)
{
    debug("SplashScene::OnExit()");
    // free resources needed for this scene
    // free scene objects
}

void SplashScene::ProcessInput(void)
{
    debug("SplashScene::ProcessInput");
};

void SplashScene::Update(double DeltaTime)
{
    debug("SplashScene::Update");
    this->elapsedTime += DeltaTime;
    if (this->elapsedTime >= 2.0f)
    {
        TitleScene *titleScene = new TitleScene();
        titleScene->Init(this->sceneManager);
        this->sceneManager->ChangeScene(titleScene);
    }
    // for each object in scene
    // update the object
}

void SplashScene::Draw(BITMAP *backbuffer)
{
    debug("SplashScene::Draw");
    textprintf_ex(backbuffer, font, 2, 40, makecol(255, 255, 255), 0, "Splash Screen");
    textprintf_ex(backbuffer, font, 2, 50, makecol(255, 255, 255), 0, "Elapsed Time: %f", this->elapsedTime);
    // for each object in scene
    // draw the scene
}