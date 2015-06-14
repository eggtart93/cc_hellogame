#include "LayerController.h"

using namespace cocos2d;

Scene* LayerController::createScene()
{
    auto scene = Scene::create();
    auto layer = LayerController::create();
    scene->addChild(layer);
    return scene;
}

bool LayerController::init()
{
    if (!Layer::init())
    {
        return false;
    }

    _pmWorld = WorldLayer::create();
    this->addChild(_pmWorld);

    this->scheduleUpdate();

    return true;
}

void LayerController::update(float dt)
{
    _pmWorld->update(dt);
}

