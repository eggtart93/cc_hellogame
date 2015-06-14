#pragma once

#include "cocos2d.h"
#include "WorldLayer.h"

class LayerController : public cocos2d::Layer
{
    public:
    virtual bool                init();
    virtual void                update(float dt);
    static cocos2d::Scene*      createScene();
    CREATE_FUNC(LayerController);

    public:
    enum LayerZOrder
    {
        WorldZOrder = 1,
        UIZOrder = 2,
    };

    private:
    WorldLayer*                 _pmWorld;
};