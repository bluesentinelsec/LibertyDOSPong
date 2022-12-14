#include "playerPaddle.hpp"

#include "../dbg.h"

int PlayerPaddle::Init(void)
{
    log_info("PlayerPaddle::Init");

    // create the player input object
    this->playerInput = new PlayerInput();

    return 0;
};

void PlayerPaddle::Update(void)
{
    log_info("PlayerPaddle::Update");

    // update the playerInput object
    this->playerInput->Update(this);
};

void PlayerPaddle::Destroy(void)
{
    log_info("PlayerPaddle::Destroy");

    // destroy the input component
    delete (this->playerInput);
};