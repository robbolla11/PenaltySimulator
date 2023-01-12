#pragma once
#include "cocos2d.h"

class comoJugar : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    cocos2d::MenuItemImage* regresar;
    void newMenu(cocos2d::Ref* pSender);

    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(comoJugar);

private:

    cocos2d::Sprite* comoPortero;
    cocos2d::Sprite* comoTirador;
};