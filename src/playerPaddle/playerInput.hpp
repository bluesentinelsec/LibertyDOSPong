#pragma once

#include "../components/inputComponent.hpp"

class PlayerInput : public InputComponent
{
public:
    PlayerInput();
    ~PlayerInput();
    void Update(Entity *);
};