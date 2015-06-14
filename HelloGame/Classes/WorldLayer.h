#pragma once

#include "cocos2d.h"

class WorldLayer : public cocos2d::Layer
{
    public:
    virtual bool                init();
    virtual void                update(float dt);
    // need to implement the "static create()" method manually
    CREATE_FUNC(WorldLayer);

    enum LayerLevels
    {
        Bottom = 10,
        Middle = 11,
        Top = 12,
    };

    private:
    cocos2d::Sprite*            _pmBg;
    cocos2d::Sprite*            _pmPlayer;
    //cocos2d::Sprite*            _pmObstacle;
    cocos2d::Sprite*            _pmCoin;
};