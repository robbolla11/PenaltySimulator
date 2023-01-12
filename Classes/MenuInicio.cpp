#include "MenuInicio.h"
#include "Juego.h"
#include "EscenaVictoria.h"
#include "EscenaDerrota.h"
#include "EscenaEmpate.h"
#include "comoJugar.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
USING_NS_CC;

cocos2d::Scene* MenuInicio::createScene() {
    return MenuInicio::create();
}

bool MenuInicio::init() {

    if (!Scene::init()) {
        return false;
    }

    auto* audio_engine = CocosDenshion::SimpleAudioEngine::getInstance();
    if (!audio_engine->isBackgroundMusicPlaying()) {
        std::string music_file = "musica/musicaback.mp3";
        audio_engine->preloadBackgroundMusic(music_file.c_str());
        audio_engine->playBackgroundMusic(music_file.c_str(), true);
        audio_engine->setBackgroundMusicVolume(0.3f);
    }

    auto* audio_engine2 = CocosDenshion::SimpleAudioEngine::getInstance();
    if (!audio_engine2->isBackgroundMusicPlaying()) {
        std::string music_file = "musica/gritoGol.wav";
        audio_engine2->preloadEffect(music_file.c_str());
        audio_engine2->playEffect(music_file.c_str(), true);
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto spriteFondo = Sprite::create("Imagenes/portada.png");
    spriteFondo->setAnchorPoint(Vec2(0.5, 0.5));
    spriteFondo->setPosition(304, 368);
    addChild(spriteFondo, 0);
    
    startMenu = MenuItemImage::create("Imagenes/jugar.png", "Imagenes/jugar.png", CC_CALLBACK_1(MenuInicio::newGame, this));
    exitMenu = MenuItemImage::create("Imagenes/salir.png", "Imagenes/salir.png", CC_CALLBACK_1(MenuInicio::quitGame, this));
    ayudaMenu = MenuItemImage::create("Imagenes/comojugar.png", "Imagenes/comojugar.png", CC_CALLBACK_1(MenuInicio::ayudaGame, this));
    auto menu = Menu::create(startMenu, exitMenu,ayudaMenu, nullptr);
    menu->setPosition(Point::ZERO);
    startMenu->setPosition(visibleSize.width / 2 - origin.x, visibleSize.height -275);
    startMenu->setScaleX(1.2);
    startMenu->setScaleY(.8);
    exitMenu->setPosition(visibleSize.width / 2 - origin.x, visibleSize.height / 2 - exitMenu->getContentSize().height+230);
    exitMenu->setScaleX(.6);
    exitMenu->setScaleY(.4);
    ayudaMenu->setPosition(visibleSize.width / 2 - origin.x, visibleSize.height / 2 - ayudaMenu->getContentSize().height);
    ayudaMenu->setScaleX(1.2);
    ayudaMenu->setScaleY(.8);
    this->addChild(menu,1);

    return true;
}

void MenuInicio::newGame(cocos2d::Ref* pSender)
{
    auto scene = Juego::createScene();
    auto* director = Director::getInstance();
    director->replaceScene(TransitionFade::create(1.0f,scene));

    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    // nothing yet
}


void MenuInicio::ayudaGame(cocos2d::Ref* pSender)
{
    auto scene = comoJugar::createScene();
    auto* director = Director::getInstance();
    director->replaceScene(TransitionFade::create(1.0f, scene));

    // nothing yet
}

void MenuInicio::quitGame(cocos2d::Ref* pSender)
{
    auto* director = Director::getInstance();
    director->end();
}


