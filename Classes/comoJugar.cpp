#include "comoJugar.h"
#include "Juego.h"
#include "MenuInicio.h"
USING_NS_CC;
using namespace std;

Scene* comoJugar::createScene()
{
    return comoJugar::create();
}

bool comoJugar::init()
{
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto comoPortero = Sprite::create("Imagenes/comoPortero.png");
    comoPortero->setAnchorPoint(Vec2(0.5, 0.5));
    comoPortero->setPosition(450, 460);
    comoPortero->setScaleY(.6);
    comoPortero->setScaleX(.4);
    addChild(comoPortero, 1);

    auto comoTirador = Sprite::create("Imagenes/comoTirador.png");
    comoTirador->setAnchorPoint(Vec2(0.5, 0.5));
    comoTirador->setPosition(150, 460);
    comoTirador->setScaleY(.6);
    comoTirador->setScaleX(.4);
    addChild(comoTirador, 1);

    regresar = MenuItemImage::create("Imagenes/regresar.png", "Imagenes/regresar.png", CC_CALLBACK_1(comoJugar::newMenu, this));
    auto menu = Menu::create(regresar, nullptr);
    menu->setPosition(Point::ZERO);
    regresar->setPosition(visibleSize.width / 2 - origin.x, visibleSize.height -630);
    this->addChild(menu, 1);

    return true;
}

void comoJugar::newMenu(cocos2d::Ref* pSender)
{
    auto scene = MenuInicio::createScene();
    auto* director = Director::getInstance();
    director->replaceScene(TransitionFade::create(1.0f, scene));
    // nothing yet
}
