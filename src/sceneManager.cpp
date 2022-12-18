#include "sceneManager.hpp"

void SceneManager::PushScene(Scene *scene)
{
    Scenes.push_back(scene);
    Scenes.back()->OnEnter();
}

void SceneManager::ChangeScene(Scene *scene)
{
    this->PopScene();
    this->PushScene(scene);
}

void SceneManager::PopScene(void)
{
    if (Scenes.empty())
    {
        return;
    }
    Scenes.back()->OnExit();
    delete Scenes.back();
    Scenes.pop_back();
}

void SceneManager::ProcessInput(void)
{
    if (Scenes.empty())
    {
        return;
    }
    Scenes.back()->ProcessInput();
}

void SceneManager::UpdateScene(double deltaTime)
{
    if (Scenes.empty())
    {
        return;
    }
    Scenes.back()->Update(deltaTime);
}

void SceneManager::DrawScene(BITMAP *backbuffer)
{
    if (Scenes.empty())
    {
        return;
    }
    Scenes.back()->Draw(backbuffer);
}