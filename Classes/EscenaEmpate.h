#pragma once
#include "cocos2d.h"

class EscenaEmpate : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    cocos2d::MenuItemImage* startMenu;
    cocos2d::MenuItemImage* exitMenu;
    void quitGame(cocos2d::Ref* pSender);
    void newMenu(cocos2d::Ref* pSender);

    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(EscenaEmpate);
    
};