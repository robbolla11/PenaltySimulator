

#pragma once

#include "cocos2d.h"

class TandaPenales : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);
    
    int contadorUsuario = 0;
    int contadorRival = 0;
    int contadorPenales = 0;


    CREATE_FUNC(TandaPenales);

    bool lose();
    void LOSE();
    bool tie();
    void TIE();
    bool won();
    void WON();
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    void update(float) override;
private:
    cocos2d::Sprite* portero;
    cocos2d::Sprite* portero2;
    cocos2d::Sprite* balon;
    cocos2d::Sprite* balon2;
    cocos2d::Sprite* gol;
    cocos2d::Sprite* salvada;
    cocos2d::Label* labelTouchInfo;
};

