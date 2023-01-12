

#ifndef __MENUINICIO_H__
#define __MENUINICIO_H__

#include "cocos2d.h"

class MenuInicio : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    cocos2d::MenuItemImage *startMenu;
    cocos2d::MenuItemImage *exitMenu;
    cocos2d::MenuItemImage *ayudaMenu;
    void quitGame(cocos2d::Ref* pSender);
    void newGame(cocos2d::Ref* pSender);
    void ayudaGame(cocos2d::Ref* pSender);

    void menuCloseCallback(cocos2d::Ref* pSender);



    CREATE_FUNC(MenuInicio);
    
};

#endif