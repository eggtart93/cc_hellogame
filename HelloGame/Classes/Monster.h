#pragma once

#include "cocos2d.h"

class Monster : public cocos2d::Sprite
{
    public:
    virtual void                update(float dt);
    void                        setAcceleration(cocos2d::Vec2 acc);
    void                        setVeclocity(cocos2d::Vec2 vec);
    void                        setVeclocityY(float vy);
    float                       getVeclocityY() const;
    void                        jump();
    void                        turnAround();
    
    static Monster* create(std::string fileName)
    {
        Monster* monster = new Monster();
        if (monster && monster->initWithFile(fileName) && monster->init())
        {
            monster->autorelease();
            return monster;
        }
        CC_SAFE_DELETE(monster);
        return nullptr;
    }

    private:
    virtual bool                init();
    void                        move(float dt);
    
    private:
    cocos2d::Vec2               _mAcc;
    cocos2d::Vec2               _mVeclocity;
    float                       _mJumpSpeed;

};