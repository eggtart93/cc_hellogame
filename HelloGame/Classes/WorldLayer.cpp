#include "WorldLayer.h"
#include "Monster.h"

using namespace cocos2d;

bool WorldLayer::init()
{
    if ( !Layer::init() ) {   return false;   }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    _mGravity = Vec2(0.f, -2.5f * visibleSize.height);

    _pmBg = Sprite::create("rect_540_960.png");
    _pmBg->setPosition(origin.x + visibleSize.width / 2.f,
        origin.y + visibleSize.height / 2.f);

    _pmPlayer = Monster::create("kirby.png");
    _pmPlayer->setPosition(origin.x + _pmPlayer->getBoundingBox().size.width * .5f, 300.f);
    
    _pmCoin = Sprite::create("coin.png");
    _pmCoin->setPosition(visibleSize.width * .5f, visibleSize.height * .5f);

    this->addChild(_pmBg, Bottom);
    this->addChild(_pmPlayer, Middle);
    this->addChild(_pmCoin, Middle);
   
    CCLOG("visibleSize.width: %f, visibleSize.height: %f", visibleSize.width, visibleSize.height);
    CCLOG("origin.x: %f, origin.y: %f", origin.x, origin.y);
    CCLOG("_pmPlayer->getBoundingBox().size.width: %f", _pmPlayer->getBoundingBox().size.width);
 
    addEventListeners();
    return true;
}

void WorldLayer::addEventListeners()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [](Touch* touch, Event* event){
        //CCLOG("OnTouchBegan: (%f,%f)", touch->getLocation().x, touch->getLocation().y);
        return true;
    };
    touchListener->onTouchEnded = [this](Touch* touch, Event* event){
        this->_pmPlayer->jump();
    };
    touchListener->setSwallowTouches(true);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void WorldLayer::update(float dt)
{
    checkBoundaries();
    _pmPlayer->update(dt);
}

void WorldLayer::checkBoundaries()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 pos = _pmPlayer->getPosition();
    Size size = _pmPlayer->getBoundingBox().size;

    CCLOG("player: (%f,%f)", pos.x, pos.y);

    if ((pos.x + size.width * .5f) > (origin.x + visibleSize.width)
        || (pos.x - size.width * .5f) < origin.x)
    {
        _pmPlayer->turnAround();
    }

    if (pos.y >= (origin.y + visibleSize.height - size.height * .5f))
    {
        _pmPlayer->setVeclocityY(-_pmPlayer->getVeclocityY());
    }
    else if (pos.y <= (origin.y + size.height * .5f))
    {
        if (_pmPlayer->getVeclocityY() < 0)
        {
            _pmPlayer->setVeclocityY(0.f);
            _pmPlayer->setAcceleration(Vec2::ZERO);
            _pmPlayer->setPosition(Vec2(pos.x, origin.y + size.height * .5f));
        }
        CCLOG("On Ground");
    }
    else
    {
        _pmPlayer->setAcceleration(_mGravity);
    }
}



bool WorldLayer::isWithinXBoundaries(Sprite* sprite)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 pos = sprite->getPosition();
    Size size = sprite->getBoundingBox().size;

    return (   (pos.x + size.width * .5f) <= (origin.x + visibleSize.width)
            && (pos.x - size.width * .5f) >= origin.x
           );
}