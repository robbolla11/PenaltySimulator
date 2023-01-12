

#pragma once

#include "cocos2d.h"

class Juego : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);

    int contadorUsuario = 0;
    int contadorRival = 0;
    int contadorPenales = 1;
  

    CREATE_FUNC(Juego);

    bool lose();
    void LOSE();
    bool tie();
    void TIE();
    bool won();
    void WON();
    void update(float) override;

    void tiroIzq();
    void tiroDer();
    void tiroMed();

    void ataIzq();
    void ataDer();
    void ataMed();

private:
    cocos2d::Sprite* portero;
    cocos2d::Sprite* portero2;
    cocos2d::Sprite* balon;
    cocos2d::Sprite* balon2;
    cocos2d::Sprite* local;
    cocos2d::Sprite* visita;
    cocos2d::Sprite* spriteFondo;
    cocos2d::Sprite* spriteFondo2;
    cocos2d::Sprite* cajainfo;
    cocos2d::Sprite* comandos;
    cocos2d::Sprite* turno;
};




