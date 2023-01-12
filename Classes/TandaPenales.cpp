
#include "TandaPenales.h"
#include "EscenaVictoria.h"
#include "EscenaDerrota.h"
#include "EscenaEmpate.h"
#include "MenuInicio.h"
#include<stdlib.h>
#include<time.h>
using namespace std;
USING_NS_CC;

Scene* TandaPenales::createScene()
{
    auto scene = Scene::create();
    auto layer = TandaPenales::create();
    scene->addChild(layer);

    return scene;
}


bool TandaPenales::init()
{
    if (!Scene::init())
    {
        return false;
    }  



    auto spriteFondo2 = Sprite::create("Imagenes/backgroundgol.png");
    spriteFondo2->setAnchorPoint(Vec2(0.5, 0.5));
    spriteFondo2->setPosition(304, 368);
    addChild(spriteFondo2, 1);

    auto spriteFondo = Sprite::create("Imagenes/background.png");
    spriteFondo->setAnchorPoint(Vec2(0.5, 0.5));
    spriteFondo->setPosition(304, 368);
    addChild(spriteFondo, 1);

    auto portero = Sprite::create("Imagenes/portero.png");
    portero->setAnchorPoint(Vec2(0.5, 0.5));
    portero->setPosition(318, 456);
    addChild(portero, 2);

    auto portero2 = Sprite::create("Imagenes/portero.png");
    portero2->setAnchorPoint(Vec2(0.5, 0.5));
    portero2->setPosition(318, 456);
    addChild(portero2, 2);

    auto balon = Sprite::create("Imagenes/ball.png");
    balon->setAnchorPoint(Vec2(0.5, 0.5));
    balon->setPosition(314, 84);
    addChild(balon, 2);

    auto balon2 = Sprite::create("Imagenes/ball.png");
    balon2->setAnchorPoint(Vec2(0.5, 0.5));
    balon2->setPosition(314, 84);
    addChild(balon2, 2);

    auto gol = Sprite::create("Imagenes/gol.png");
    gol->setAnchorPoint(Vec2(0.5, 0.5));
    gol->setPosition(305, 640);
    addChild(gol, 3);

    auto salvada = Sprite::create("Imagenes/salvada.png");
    salvada->setAnchorPoint(Vec2(0.5, 0.5));
    salvada->setPosition(305, 640);
    addChild(salvada, 3);

    Label* textLabel = Label::createWithTTF("submit score?", "fonts/arial.ttf", 36);
    textLabel->setAnchorPoint(Vec2::ZERO);
    textLabel->setPosition(Vec2(100, 100));
    textLabel->setTextColor(Color4B(0, 0, 0, 255));
    textLabel->setString(std::to_string(contadorUsuario));
    addChild(textLabel,4);

    Label* textLabel2 = Label::createWithTTF("submit score?", "fonts/arial.ttf", 36);
    textLabel2->setAnchorPoint(Vec2::ZERO);
    textLabel2->setPosition(Vec2(400, 100));
    textLabel2->setTextColor(Color4B(0, 0, 0, 255));
    textLabel2->setString(std::to_string(contadorRival));
    addChild(textLabel2, 4);
  
    auto listener = cocos2d::EventListenerKeyboard::create();

    int x = 1;
    srand(time(NULL));

    cocos2d::Vector<cocos2d::FiniteTimeAction*> aux;
    aux.pushBack(cocos2d::Hide::create());
    auto auxx = cocos2d::Sequence::create(aux);
    portero2->runAction(auxx);

    cocos2d::Vector<cocos2d::FiniteTimeAction*> aux1;
    aux1.pushBack(cocos2d::Hide::create());
    auto auxx1 = cocos2d::Sequence::create(aux1);
    balon2->runAction(auxx1);

    cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
    aux2.pushBack(cocos2d::Hide::create());
    auto auxx2 = cocos2d::Sequence::create(aux2);
    gol->runAction(auxx2);

    cocos2d::Vector<cocos2d::FiniteTimeAction*> aux3;
    aux3.pushBack(cocos2d::Hide::create());
    auto auxx3 = cocos2d::Sequence::create(aux3);
    salvada->runAction(auxx3);


    //hacer escenas y hacer que se llame la necesaria 10 veces, luego mostrar si se gano perdio o empato

        listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)->void
        {
            int x = 0;
            int num = 0;
            num = 1 + rand() % (4 - 1);
            textLabel->setString(std::to_string(contadorUsuario));

            if (contadorPenales<10)
            {
                switch (code)
                {

                case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                case EventKeyboard::KeyCode::KEY_D:
                {
                    contadorPenales++;
                    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                    actions.pushBack(cocos2d::MoveBy::create(.8, cocos2d::Vec2(160, 373)));
                    actions.pushBack(cocos2d::ScaleTo::create(.8, .74));
                    actions.pushBack(cocos2d::RotateBy::create(2.1, 120));
                    actions.pushBack(cocos2d::DelayTime::create(2.4));
                    actions.pushBack(cocos2d::MoveBy::create(1, cocos2d::Vec2(0, -30)));
                    auto sequence = cocos2d::Spawn::create(actions);

                    balon->runAction(sequence);

                    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions1;
                    actions1.pushBack(cocos2d::DelayTime::create(.9));
                    actions1.pushBack(cocos2d::MoveBy::create(.7, cocos2d::Vec2(0, -30)));
                    auto sequence1 = cocos2d::Sequence::create(actions1);

                    balon->runAction(sequence1);

                    if (num == 1)
                    {
                        contadorRival = contadorUsuario;
                        contadorUsuario++;
                        balon->setLocalZOrder(1);

                        portero->setTexture("Imagenes/portero2.png");
                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                        actions.pushBack(cocos2d::MoveTo::create(.8, cocos2d::Vec2(210, 426)));
                        actions.pushBack(cocos2d::RotateBy::create(.7, -84));
                        auto sequence = cocos2d::Spawn::create(actions);

                        portero->runAction(sequence);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions1;
                        actions1.pushBack(cocos2d::DelayTime::create(.9));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(210, 416)));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(210, 406)));
                        auto sequence1 = cocos2d::Sequence::create(actions1);

                        portero->runAction(sequence1);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions2;
                        actions2.pushBack(cocos2d::DelayTime::create(.9));
                        actions2.pushBack(cocos2d::Hide::create());
                        auto sequence2 = cocos2d::Sequence::create(actions2);

                        spriteFondo->runAction(sequence2);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions3;
                        actions3.pushBack(cocos2d::DelayTime::create(.9));
                        actions3.pushBack(cocos2d::Show::create());
                        auto sequence3 = cocos2d::Sequence::create(actions3);
                        spriteFondo2->runAction(sequence3);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                        aux2.pushBack(cocos2d::DelayTime::create(3));
                        aux2.pushBack(cocos2d::Show::create());
                        auto auxx2 = cocos2d::Sequence::create(aux2);
                        gol->runAction(auxx2);

                    }

                    else if (num == 3)
                    {
                        balon->setLocalZOrder(3);
                        portero->setTexture("Imagenes/portero2.png");
                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                        actions.pushBack(cocos2d::MoveTo::create(.8, cocos2d::Vec2(398, 426)));
                        actions.pushBack(cocos2d::RotateBy::create(.7, 84));
                        auto sequence = cocos2d::Spawn::create(actions);

                        portero->runAction(sequence);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions1;
                        actions1.pushBack(cocos2d::DelayTime::create(.9));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(398, 416)));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(398, 406)));
                        auto sequence1 = cocos2d::Sequence::create(actions1);

                        portero->runAction(sequence1);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                        aux2.pushBack(cocos2d::DelayTime::create(3));
                        aux2.pushBack(cocos2d::Show::create());
                        auto auxx2 = cocos2d::Sequence::create(aux2);
                        salvada->runAction(auxx2);
                    }

                    else
                    {
                        contadorRival = contadorUsuario;
                        contadorUsuario++;

                        portero->setTexture("Imagenes/portero2.png");
                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions2;
                        actions2.pushBack(cocos2d::DelayTime::create(.9));
                        actions2.pushBack(cocos2d::Hide::create());
                        auto sequence2 = cocos2d::Sequence::create(actions2);

                        spriteFondo->runAction(sequence2);
                        textLabel->setString(std::to_string(contadorUsuario));

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions3;
                        actions3.pushBack(cocos2d::DelayTime::create(.9));
                        actions3.pushBack(cocos2d::Show::create());
                        auto sequence3 = cocos2d::Sequence::create(actions3);
                        spriteFondo2->runAction(sequence3);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                        aux2.pushBack(cocos2d::DelayTime::create(3));
                        aux2.pushBack(cocos2d::Show::create());
                        auto auxx2 = cocos2d::Sequence::create(aux2);
                        gol->runAction(auxx2);
                    }
                    textLabel->setString(std::to_string(contadorUsuario));
                    textLabel2->setString(std::to_string(contadorRival));

                }
                break;

                case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                case EventKeyboard::KeyCode::KEY_A:
                {
                    contadorPenales++;
                    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                    actions.pushBack(cocos2d::MoveBy::create(.8, cocos2d::Vec2(-188, 373)));
                    actions.pushBack(cocos2d::ScaleTo::create(.8, .74));
                    actions.pushBack(cocos2d::RotateBy::create(2.1, 120));
                    actions.pushBack(cocos2d::DelayTime::create(2.4));
                    actions.pushBack(cocos2d::MoveBy::create(1, cocos2d::Vec2(0, -30)));
                    auto sequence = cocos2d::Spawn::create(actions);

                    balon->runAction(sequence);

                    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions1;
                    actions1.pushBack(cocos2d::DelayTime::create(.9));
                    actions1.pushBack(cocos2d::MoveBy::create(.7, cocos2d::Vec2(0, -30)));
                    auto sequence1 = cocos2d::Sequence::create(actions1);

                    balon->runAction(sequence1);


                    if (num == 1)
                    {
                        balon->setLocalZOrder(3);
                        portero->setTexture("Imagenes/portero2.png");
                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                        actions.pushBack(cocos2d::MoveTo::create(.8, cocos2d::Vec2(210, 426)));
                        actions.pushBack(cocos2d::RotateBy::create(.7, -84));
                        auto sequence = cocos2d::Spawn::create(actions);

                        portero->runAction(sequence);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions1;
                        actions1.pushBack(cocos2d::DelayTime::create(.9));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(210, 416)));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(210, 406)));
                        auto sequence1 = cocos2d::Sequence::create(actions1);

                        portero->runAction(sequence1);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                        aux2.pushBack(cocos2d::DelayTime::create(3));
                        aux2.pushBack(cocos2d::Show::create());
                        auto auxx2 = cocos2d::Sequence::create(aux2);
                        salvada->runAction(auxx2);
                    }

                    else if (num == 3)
                    {
                        contadorRival = contadorUsuario;
                        contadorUsuario++;
                        balon->setLocalZOrder(1);
                        portero->setTexture("Imagenes/portero2.png");
                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                        actions.pushBack(cocos2d::MoveTo::create(.8, cocos2d::Vec2(398, 426)));
                        actions.pushBack(cocos2d::RotateBy::create(.7, 84));
                        auto sequence = cocos2d::Spawn::create(actions);

                        portero->runAction(sequence);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions1;
                        actions1.pushBack(cocos2d::DelayTime::create(.9));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(398, 416)));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(398, 406)));
                        auto sequence1 = cocos2d::Sequence::create(actions1);

                        portero->runAction(sequence1);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions2;
                        actions2.pushBack(cocos2d::DelayTime::create(.9));
                        actions2.pushBack(cocos2d::Hide::create());
                        auto sequence2 = cocos2d::Sequence::create(actions2);

                        spriteFondo->runAction(sequence2);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions3;
                        actions3.pushBack(cocos2d::DelayTime::create(.9));
                        actions3.pushBack(cocos2d::Show::create());
                        auto sequence3 = cocos2d::Sequence::create(actions3);
                        spriteFondo2->runAction(sequence3);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                        aux2.pushBack(cocos2d::DelayTime::create(3));
                        aux2.pushBack(cocos2d::Show::create());
                        auto auxx2 = cocos2d::Sequence::create(aux2);
                        gol->runAction(auxx2);
                    }

                    else
                    {
                        contadorRival = contadorUsuario;
                        contadorUsuario++;
                        portero->setTexture("Imagenes/portero2.png");

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions2;
                        actions2.pushBack(cocos2d::DelayTime::create(.9));
                        actions2.pushBack(cocos2d::Hide::create());
                        auto sequence2 = cocos2d::Sequence::create(actions2);

                        spriteFondo->runAction(sequence2);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions3;
                        actions3.pushBack(cocos2d::DelayTime::create(.9));
                        actions3.pushBack(cocos2d::Show::create());
                        auto sequence3 = cocos2d::Sequence::create(actions3);
                        spriteFondo2->runAction(sequence3);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                        aux2.pushBack(cocos2d::DelayTime::create(3));
                        aux2.pushBack(cocos2d::Show::create());
                        auto auxx2 = cocos2d::Sequence::create(aux2);
                        gol->runAction(auxx2);
                    }
                    textLabel->setString(std::to_string(contadorUsuario));
                    textLabel2->setString(std::to_string(contadorRival));
                }
                break;

                case EventKeyboard::KeyCode::KEY_UP_ARROW:
                case EventKeyboard::KeyCode::KEY_W:
                {
                    contadorPenales++;
                    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                    actions.pushBack(cocos2d::MoveTo::create(.93, cocos2d::Vec2(314, 554)));
                    actions.pushBack(cocos2d::ScaleTo::create(.8, .74));
                    actions.pushBack(cocos2d::RotateBy::create(2.1, 120));
                    actions.pushBack(cocos2d::DelayTime::create(2.4));
                    actions.pushBack(cocos2d::MoveBy::create(1, cocos2d::Vec2(0, -30)));
                    auto sequence = cocos2d::Spawn::create(actions);

                    balon->runAction(sequence);

                    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions1;
                    actions1.pushBack(cocos2d::DelayTime::create(.9));
                    actions1.pushBack(cocos2d::MoveBy::create(.7, cocos2d::Vec2(0, -120)));
                    auto sequence1 = cocos2d::Sequence::create(actions1);

                    balon->runAction(sequence1);


                    if (num == 1)
                    {
                        contadorRival = contadorUsuario;
                        contadorUsuario++;
                        balon->setLocalZOrder(1);
                        portero->setTexture("Imagenes/portero2.png");
                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                        actions.pushBack(cocos2d::MoveTo::create(.8, cocos2d::Vec2(200, 426)));
                        actions.pushBack(cocos2d::RotateBy::create(.7, -84));
                        auto sequence = cocos2d::Spawn::create(actions);

                        portero->runAction(sequence);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions1;
                        actions1.pushBack(cocos2d::DelayTime::create(.9));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(200, 416)));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(200, 406)));
                        auto sequence1 = cocos2d::Sequence::create(actions1);

                        portero->runAction(sequence1);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions2;
                        actions2.pushBack(cocos2d::DelayTime::create(.9));
                        actions2.pushBack(cocos2d::Hide::create());
                        auto sequence2 = cocos2d::Sequence::create(actions2);

                        spriteFondo->runAction(sequence2);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions3;
                        actions3.pushBack(cocos2d::DelayTime::create(.9));
                        actions3.pushBack(cocos2d::Show::create());
                        auto sequence3 = cocos2d::Sequence::create(actions3);
                        spriteFondo2->runAction(sequence3);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                        aux2.pushBack(cocos2d::DelayTime::create(3));
                        aux2.pushBack(cocos2d::Show::create());
                        auto auxx2 = cocos2d::Sequence::create(aux2);
                        gol->runAction(auxx2);
                    }

                    else if (num == 3)
                    {
                        contadorRival = contadorUsuario;
                        contadorUsuario++;
                        balon->setLocalZOrder(1);
                        portero->setTexture("Imagenes/portero2.png");
                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                        actions.pushBack(cocos2d::MoveTo::create(.8, cocos2d::Vec2(428, 426)));
                        actions.pushBack(cocos2d::RotateBy::create(.7, 84));
                        auto sequence = cocos2d::Spawn::create(actions);

                        portero->runAction(sequence);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions1;
                        actions1.pushBack(cocos2d::DelayTime::create(.9));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(428, 416)));
                        actions1.pushBack(cocos2d::MoveTo::create(.25, cocos2d::Vec2(428, 406)));
                        auto sequence1 = cocos2d::Sequence::create(actions1);

                        portero->runAction(sequence1);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions2;
                        actions2.pushBack(cocos2d::DelayTime::create(.9));
                        actions2.pushBack(cocos2d::Hide::create());
                        auto sequence2 = cocos2d::Sequence::create(actions2);

                        spriteFondo->runAction(sequence2);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions3;
                        actions3.pushBack(cocos2d::DelayTime::create(.9));
                        actions3.pushBack(cocos2d::Show::create());
                        auto sequence3 = cocos2d::Sequence::create(actions3);
                        spriteFondo2->runAction(sequence3);

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                        aux2.pushBack(cocos2d::DelayTime::create(3));
                        aux2.pushBack(cocos2d::Show::create());
                        auto auxx2 = cocos2d::Sequence::create(aux2);
                        gol->runAction(auxx2);
                    }

                    else
                    {
                        balon->setLocalZOrder(3);
                        portero->setTexture("Imagenes/portero2.png");

                        cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                        aux2.pushBack(cocos2d::DelayTime::create(3));
                        aux2.pushBack(cocos2d::Show::create());
                        auto auxx2 = cocos2d::Sequence::create(aux2);
                        salvada->runAction(auxx2);

                    }
                    textLabel->setString(std::to_string(contadorUsuario));
                    textLabel2->setString(std::to_string(contadorRival));
                }
                break;

                default:
                {

                    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                    actions.pushBack(cocos2d::MoveTo::create(.001, cocos2d::Vec2(314, 84)));
                    actions.pushBack(cocos2d::ScaleTo::create(.001, 1));
                    auto sequence = cocos2d::Sequence::create(actions);
                    balon->runAction(sequence);

                    portero->setRotation(portero2->getRotation());
                    balon->setScale(balon2->getScale());
                    portero->setTexture("Imagenes/portero.png");

                    portero->setPosition(318, 456);


                    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions2;
                    actions2.pushBack(cocos2d::Show::create());
                    auto sequence2 = cocos2d::Sequence::create(actions2);

                    spriteFondo->runAction(sequence2);

                    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions3;
                    actions3.pushBack(cocos2d::Hide::create());
                    auto sequence3 = cocos2d::Sequence::create(actions3);

                    spriteFondo2->runAction(sequence3);

                    cocos2d::Vector<cocos2d::FiniteTimeAction*> aux2;
                    aux2.pushBack(cocos2d::Hide::create());
                    auto auxx2 = cocos2d::Sequence::create(aux2);
                    gol->runAction(auxx2);

                    cocos2d::Vector<cocos2d::FiniteTimeAction*> aux3;
                    aux3.pushBack(cocos2d::Hide::create());
                    auto auxx3 = cocos2d::Sequence::create(aux3);
                    salvada->runAction(auxx3);
                    textLabel->setString(std::to_string(contadorUsuario));
                    textLabel2->setString(std::to_string(contadorRival));
                }
                break;
                }
            }
        };
        this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    return true;
}

void TandaPenales::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

}

bool TandaPenales::lose()
{
    bool t = true;
    return t;
}
bool TandaPenales::won()
{
    bool t = true;
    return t;
}

bool TandaPenales::tie()
{
    bool t = true;
    return t;
}

void TandaPenales::LOSE()
{
    auto* director = Director::getInstance();
    director->replaceScene(EscenaDerrota::createScene());
}
void TandaPenales::WON()
{
    auto* director = Director::getInstance();
    director->replaceScene(EscenaVictoria::createScene());
}

void TandaPenales::TIE()
{
    auto* director = Director::getInstance();
    director->replaceScene(EscenaEmpate::createScene());
}

void TandaPenales::update(float delta)
{
    if (lose()) {
        LOSE();
        return;
    }
    if (won()) {
        WON();
        return;
    }
}


static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in TandaPenales.cpp\n");
}

