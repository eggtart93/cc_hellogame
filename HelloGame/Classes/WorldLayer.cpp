#include "WorldLayer.h"

using namespace cocos2d;

bool WorldLayer::init()
{
    if ( !Layer::init() ) {   return false;   }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    _pmBg = Sprite::create("rect_540_960.png");
    _pmPlayer = Sprite::create("kirby.png");
    _pmCoin = Sprite::create("coin.png");

    _pmBg->setPosition(origin.x + visibleSize.width / 2.f,
                       origin.y + visibleSize.height / 2.f);
    _pmPlayer->setPosition(origin.x + _pmPlayer->getBoundingBox().size.width * .5f, 100.f);
    _pmCoin->setPosition(visibleSize.width * .5f, visibleSize.height * .5f);

    this->addChild(_pmBg, Bottom);
    this->addChild(_pmPlayer, Middle);
    this->addChild(_pmCoin, Middle);

    Vec2 rightPos(.5f * (visibleSize.width - _pmPlayer->getBoundingBox().size.width),
                   _pmPlayer->getPositionY());
    Vec2 leftPos(.5f * _pmPlayer->getBoundingBox().size.width, _pmPlayer->getPositionY());
    
    CCLOG("visibleSize.width: %f, visibleSize.height: %f", visibleSize.width, visibleSize.height);
    //CCLog("origin.x: %f, origin.y: %f", origin.x, origin.y);
    //CCLog("_pmPlayer->getBoundingBox().size.width: %f", _pmPlayer->getBoundingBox().size.width);
    //CCLog("rightPos.x: %f, rightPos.y: %f", rightPos.x, rightPos.y);
    
        
    auto moveToRight = MoveTo::create(1.5f, rightPos);
    //auto moveToLeft = MoveTo::create(1.5f, leftPos);
    auto flipX = FlipX::create(false);
    auto repeatActions = RepeatForever::create(Sequence::create(flipX, moveToRight, flipX->reverse(), moveToRight->reverse(), NULL));
    
    //_pmPlayer->setPosition(rightPos);
    //_pmPlayer->runAction(repeatActions);
    return true;
}

void WorldLayer::update(float dt)
{
    
}