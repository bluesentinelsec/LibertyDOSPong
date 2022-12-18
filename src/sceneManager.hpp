#pragma once

#include "scene.hpp"
#include <vector>

#include <allegro.h>

// forward declaration
class Scene;

class SceneManager
{
public:
    void PushScene(Scene *scene);
    void ChangeScene(Scene *scene);
    void PopScene(void);

    void ProcessInput(void);
    void UpdateScene(double deltaTime);
    void DrawScene(BITMAP *backbuffer);

private:
    std::vector<Scene *> Scenes;
};