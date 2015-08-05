#include "Monster.h"

using namespace cocos2d;

#define HORIZONTAL_SPEED 350.f

bool Monster::init()
{
    Size worldSize = Director::getInstance()->getVisibleSize();
    _mAcc = Vec2::ZERO;
    _mVeclocity = Vec2(worldSize.width * .75f, 0.f);
    _mJumpSpeed = worldSize.height * .5f;
    return true;
}

void Monster::jump()
{
    _mVeclocity.y = _mJumpSpeed;
    CCLOG("Jump!");
}

void Monster::move(float dt)
{
    _mVeclocity += _mAcc * dt;
    //CCLOG("_mAcc = (%f,%f)", _mAcc.x, _mAcc.y);
    //CCLOG("_mVeclocity = (%f,%f)", _mVeclocity.x, _mVeclocity.y);
    Vec2 movement = _mVeclocity * dt;
    //CCLOG("movement = (%f,%f)", movement.x, movement.y);
    setPosition(getPosition() + movement);
 }

void Monster::setAcceleration(Vec2 acc)
{
    _mAcc = acc;
}

void Monster::setVeclocity(cocos2d::Vec2 vec)
{
    _mVeclocity = vec;
}

void Monster::setVeclocityY(float vy)
{
    _mVeclocity.y = vy;
}

float Monster::getVeclocityY() const
{
    return _mVeclocity.y;
}

void Monster::turnAround()
{
    runAction(FlipX::create(!isFlippedX()));
    _mVeclocity.x = -_mVeclocity.x;
}

void Monster::update(float dt)
{
    move(dt);
}