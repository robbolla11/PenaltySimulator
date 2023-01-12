#include "EscenaEmpate.h"
#include "Juego.h"
#include "MenuInicio.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
USING_NS_CC;
using namespace std;

Scene* EscenaEmpate::createScene()
{
    return EscenaEmpate::create();
}

bool EscenaEmpate::init()
{
    if (!Scene::init()) {
        return false;
    }
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto spriteFondo = Sprite::create("Imagenes/empate.png");
    spriteFondo->setAnchorPoint(Vec2(0.5, 0.5));
    spriteFondo->setPosition(304, 368);
    addChild(spriteFondo, 0);

    startMenu = MenuItemImage::create("Imagenes/iniciar.png", "Imagenes/iniciar.png", CC_CALLBACK_1(EscenaEmpate::newMenu, this));
    exitMenu = MenuItemImage::create("Imagenes/salir.png", "Imagenes/salir.png", CC_CALLBACK_1(EscenaEmpate::quitGame, this));
    auto menu = Menu::create(startMenu, exitMenu, nullptr);
    menu->setPosition(Point::ZERO);
    startMenu->setPosition(visibleSize.width / 2 - origin.x, visibleSize.height - 200);
    startMenu->setScaleY(.5);
    startMenu->setScaleX(.6);
    exitMenu->setPosition(visibleSize.width / 2 - origin.x, visibleSize.height / 2 - exitMenu->getContentSize().height + 275);
    exitMenu->setScaleX(.6);
    exitMenu->setScaleY(.5);
    this->addChild(menu, 1);

    return true;
}

void EscenaEmpate::newMenu(cocos2d::Ref* pSender)
{
    auto scene = MenuInicio::createScene();
    auto* director = Director::getInstance();
    director->replaceScene(TransitionFade::create(1.0f, scene));
    // nothing yet
}

void EscenaEmpate::quitGame(cocos2d::Ref* pSender)
{
    auto* director = Director::getInstance();
    director->end();
}