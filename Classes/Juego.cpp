

#include "Juego.h"
#include "EscenaVictoria.h"
#include "EscenaDerrota.h"
#include "EscenaEmpate.h"
#include "MenuInicio.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include "AudioEngine.h"

using namespace std;
USING_NS_CC;

Scene* Juego::createScene()
{
    auto scene = Scene::create();
    auto layer = Juego::create();
    scene->addChild(layer);

    return scene;
}

bool Juego::init()
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

    auto portero = Sprite::create("Imagenes/gk.png");
    portero->setAnchorPoint(Vec2(0.5, 0.5));
    portero->setPosition(318, 456);
    addChild(portero, 2);

    auto portero2 = Sprite::create("Imagenes/gk.png");
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

    auto local = Sprite::create("Imagenes/local0.png");
    local->setAnchorPoint(Vec2(0.5, 0.5));
    local->setPosition(75, 660);
    addChild(local, 3);

    auto visita = Sprite::create("Imagenes/visita0.png");
    visita->setAnchorPoint(Vec2(0.5, 0.5));
    visita->setPosition(535, 660);
    addChild(visita, 3);

    auto comandos = Sprite::create("Imagenes/comandos.png");
    comandos->setAnchorPoint(Vec2(0.5, 0.5));
    comandos->setPosition(90, 90);
    comandos->setScaleY(1.2);
    comandos->setScaleX(1.2);
    addChild(comandos, 5);

    auto turno = Sprite::create("Imagenes/tiras.png");
    turno->setAnchorPoint(Vec2(0.5, 0.5));
    turno->setPosition(312, 648);
    addChild(turno, 5);


    srand(time(NULL));

    cocos2d::Vector<cocos2d::FiniteTimeAction*> aux;
    aux.pushBack(cocos2d::Hide::create());
    auto auxx = cocos2d::Sequence::create(aux);
    portero2->runAction(auxx);

    cocos2d::Vector<cocos2d::FiniteTimeAction*> aux1;
    aux1.pushBack(cocos2d::Hide::create());
    auto auxx1 = cocos2d::Sequence::create(aux1);
    balon2->runAction(auxx1);

    //auto backgroundAudioID = AudioEngine::play2d("mymusic.mp3", true);

    // set the music and play it just once.
    auto soundEffectID = cocos2d::AudioEngine::play2d("gritoGol.wav", false);


    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)->void
    {
        int num = 0;
        

        if (contadorPenales <= 10)
        {
           
            switch (contadorPenales)
            {
                
                case 1: case 3: case 5: case 7: case 9:
                    turno->setTexture("Imagenes/tiras.png");
                    portero->setTexture("Imagenes/gk.png");
                    switch (code)
                    {
                        

                        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                        case EventKeyboard::KeyCode::KEY_D:
                        {
                            num = 1 + rand() % (4 - 1);

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
                                contadorUsuario++;
                                balon->setLocalZOrder(1);

                                portero->setTexture("Imagenes/gk2.png");
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

                            }

                            else if (num == 3)
                            {
                                balon->setLocalZOrder(3);
                                portero->setTexture("Imagenes/gk2.png");
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
                            }

                            else
                            {
                                contadorUsuario++;

                                portero->setTexture("Imagenes/gk2.png");
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

                            }
                    
                        }
                        if (contadorUsuario == 1)
                            local->setTexture("Imagenes/local1.png");

                        if (contadorUsuario == 2)
                            local->setTexture("Imagenes/local2.png");

                        if (contadorUsuario == 3)
                            local->setTexture("Imagenes/local3.png");

                        if (contadorUsuario == 4)
                            local->setTexture("Imagenes/local4.png");

                        if (contadorUsuario == 5)
                            local->setTexture("Imagenes/local5.png");
                        break;

                        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                        case EventKeyboard::KeyCode::KEY_A:
                        {
                            num = 1 + rand() % (4 - 1);

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
                                portero->setTexture("Imagenes/gk2.png");
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

                            }

                            else if (num == 3)
                            {
                                contadorUsuario++;
                                balon->setLocalZOrder(1);
                                portero->setTexture("Imagenes/gk2.png");
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
                            }

                            else
                            {
                                contadorUsuario++;
                                portero->setTexture("Imagenes/gk2.png");

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
                            }
                        }
                        if (contadorUsuario == 1)
                            local->setTexture("Imagenes/local1.png");

                        if (contadorUsuario == 2)
                            local->setTexture("Imagenes/local2.png");

                        if (contadorUsuario == 3)
                            local->setTexture("Imagenes/local3.png");

                        if (contadorUsuario == 4)
                            local->setTexture("Imagenes/local4.png");

                        if (contadorUsuario == 5)
                            local->setTexture("Imagenes/local5.png");
                        break;

                        case EventKeyboard::KeyCode::KEY_UP_ARROW:
                        case EventKeyboard::KeyCode::KEY_W:
                        {
                            num = 1 + rand() % (4 - 1);
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
                            actions1.pushBack(cocos2d::MoveBy::create(.7, cocos2d::Vec2(0, -140)));
                            auto sequence1 = cocos2d::Sequence::create(actions1);

                            balon->runAction(sequence1);


                            if (num == 1)
                            {
                                contadorUsuario++;
                                balon->setLocalZOrder(1);
                                portero->setTexture("Imagenes/gk2.png");
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
                            }

                            else if (num == 3)
                            {
                                contadorUsuario++;
                                balon->setLocalZOrder(1);
                                portero->setTexture("Imagenes/gk2.png");
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
                            }

                            else
                            {
                                balon->setLocalZOrder(3);
                                portero->setTexture("Imagenes/gk2.png");

                            }
                        }
                        if (contadorUsuario == 1)
                            local->setTexture("Imagenes/local1.png");

                        if (contadorUsuario == 2)
                            local->setTexture("Imagenes/local2.png");

                        if (contadorUsuario == 3)
                            local->setTexture("Imagenes/local3.png");

                        if (contadorUsuario == 4)
                            local->setTexture("Imagenes/local4.png");

                        if (contadorUsuario == 5)
                            local->setTexture("Imagenes/local5.png");
                        break;

                        case EventKeyboard::KeyCode::KEY_C:
                        {

                            cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
                            actions.pushBack(cocos2d::MoveTo::create(.001, cocos2d::Vec2(314, 84)));
                            actions.pushBack(cocos2d::ScaleTo::create(.001, 1));
                            auto sequence = cocos2d::Sequence::create(actions);
                            balon->runAction(sequence);

                            portero->setRotation(portero2->getRotation());
                            balon->setScale(balon2->getScale());
                            portero->setTexture("Imagenes/gk.png");

                            portero->setPosition(318, 456);


                            cocos2d::Vector<cocos2d::FiniteTimeAction*> actions2;
                            actions2.pushBack(cocos2d::Show::create());
                            auto sequence2 = cocos2d::Sequence::create(actions2);

                            spriteFondo->runAction(sequence2);

                            cocos2d::Vector<cocos2d::FiniteTimeAction*> actions3;
                            actions3.pushBack(cocos2d::Hide::create());
                            auto sequence3 = cocos2d::Sequence::create(actions3);

                            spriteFondo2->runAction(sequence3);
                        }
                        if (contadorUsuario == 1)
                            local->setTexture("Imagenes/local1.png");

                        if (contadorUsuario == 2)
                            local->setTexture("Imagenes/local2.png");

                        if (contadorUsuario == 3)
                            local->setTexture("Imagenes/local3.png");

                        if (contadorUsuario == 4)
                            local->setTexture("Imagenes/local4.png");

                        if (contadorUsuario == 5)
                            local->setTexture("Imagenes/local5.png");
                        break;
                    }
                    break;

                case 2: case 4: case 6: case 8: case 10:
                    turno->setTexture("Imagenes/atajas.png");
                    portero->setTexture("Imagenes/portero.png");
                    switch (code)
                    {
                        
                    
                        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                        case EventKeyboard::KeyCode::KEY_D:
                        {
                            num = 1 + rand() % (4 - 1);
                            contadorPenales++;
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


                            if (num == 1)
                            {
                                contadorRival++;
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

                            }

                            else if (num == 3)
                            {
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
                            }

                            else
                            {
                                contadorRival++;
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
                                actions1.pushBack(cocos2d::MoveBy::create(.7, cocos2d::Vec2(0, -140)));
                                auto sequence1 = cocos2d::Sequence::create(actions1);

                                balon->runAction(sequence1);
                            }
                            if (contadorRival == 1)
                                visita->setTexture("Imagenes/visita1.png");

                            if (contadorRival == 2)
                                visita->setTexture("Imagenes/visita2.png");

                            if (contadorRival == 3)
                                visita->setTexture("Imagenes/visita3.png");

                            if (contadorRival == 4)
                                visita->setTexture("Imagenes/visita4.png");

                            if (contadorRival == 5)
                                visita->setTexture("Imagenes/visita5.png");

                        }
                        break;

                        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                        case EventKeyboard::KeyCode::KEY_A:
                        {
                            num = 1 + rand() % (4 - 1);
                            contadorPenales++;
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


                            if (num == 1)
                            {
                            
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

                            }

                            else if (num == 3)
                            {
                                contadorRival++;
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
                            }

                            else
                            {
                                contadorRival++;
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
                                actions1.pushBack(cocos2d::MoveBy::create(.7, cocos2d::Vec2(0, -140)));
                                auto sequence1 = cocos2d::Sequence::create(actions1);

                                balon->runAction(sequence1);
                            }
                            if (contadorRival == 1)
                                visita->setTexture("Imagenes/visita1.png");

                            if (contadorRival == 2)
                                visita->setTexture("Imagenes/visita2.png");

                            if (contadorRival == 3)
                                visita->setTexture("Imagenes/visita3.png");

                            if (contadorRival == 4)
                                visita->setTexture("Imagenes/visita4.png");

                            if (contadorRival == 5)
                                visita->setTexture("Imagenes/visita5.png");
                        }
                        break;

                        case EventKeyboard::KeyCode::KEY_UP_ARROW:
                        case EventKeyboard::KeyCode::KEY_W:
                        {
                            num = 1 + rand() % (4 - 1);
                            balon->setLocalZOrder(3);
                            portero->setTexture("Imagenes/portero2.png");
                            contadorPenales++;
                        


                            if (num == 1)
                            {
                                contadorRival++;
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
                            }

                            else if (num == 3)
                            {
                                contadorRival++;
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
                            }

                            else
                            {
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
                                actions1.pushBack(cocos2d::MoveBy::create(.7, cocos2d::Vec2(0, -140)));
                                auto sequence1 = cocos2d::Sequence::create(actions1);

                                balon->runAction(sequence1);

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

                            }
                            if (contadorRival == 1)
                                visita->setTexture("Imagenes/visita1.png");

                            if (contadorRival == 2)
                                visita->setTexture("Imagenes/visita2.png");

                            if (contadorRival == 3)
                                visita->setTexture("Imagenes/visita3.png");

                            if (contadorRival == 4)
                                visita->setTexture("Imagenes/visita4.png");

                            if (contadorRival == 5)
                                visita->setTexture("Imagenes/visita5.png");
                        }
                        break;

                        case EventKeyboard::KeyCode::KEY_C:
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
                        }
                        if (contadorRival == 1)
                            visita->setTexture("Imagenes/visita1.png");

                        if (contadorRival == 2)
                            visita->setTexture("Imagenes/visita2.png");

                        if (contadorRival == 3)
                            visita->setTexture("Imagenes/visita3.png");

                        if (contadorRival == 4)
                            visita->setTexture("Imagenes/visita4.png");

                        if (contadorRival == 5)
                            visita->setTexture("Imagenes/visita5.png");
                        break;
                    break;
                    }
            }
        }

        else
        {
            
            if (contadorUsuario > contadorRival)
                WON();
            if (contadorUsuario < contadorRival)
                LOSE();
            if (contadorUsuario == contadorRival)
                TIE();

            contadorUsuario = 0;
            contadorRival = 0;
            contadorPenales = 1;
            update(.2);
        }
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

void Juego::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

}

void Juego::LOSE()
{
    auto scene = EscenaDerrota::createScene();
    auto* director = Director::getInstance();
    director->replaceScene(TransitionFade::create(5.0f, scene));
}
void Juego::WON()
{
    auto scene = EscenaVictoria::createScene();
    auto* director = Director::getInstance();
    director->replaceScene(TransitionFade::create(5.0f, scene));
}

void Juego::TIE()
{
    auto scene = EscenaEmpate::createScene();
    auto* director = Director::getInstance();
    director->replaceScene(TransitionFade::create(5.0f, scene));
}

void Juego::update(float delta)
{ 
    contadorUsuario = 0;
    contadorRival = 0;
    contadorPenales = 1;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
