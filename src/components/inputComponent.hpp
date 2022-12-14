#pragma once

#include "../entity.hpp"

class InputComponent
{
public:
    InputComponent(){};
    ~InputComponent(){};

    virtual void Update(Entity *) = 0;
};