#pragma once

#include "../entity.hpp"

#include "playerInput.hpp"

class PlayerPaddle : public Entity
{
public:
    virtual int Init(void);
    virtual void Update(void);
    virtual void Destroy(void);

    PlayerInput *playerInput;
};