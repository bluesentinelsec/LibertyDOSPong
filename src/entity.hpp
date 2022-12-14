#pragma once

class Entity
{
public:
    Entity(){};
    ~Entity(){};

    virtual int Init(void) = 0;
    virtual void Update(void) = 0;
    virtual void Destroy(void) = 0;
};