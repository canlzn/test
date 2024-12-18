#ifndef _STARTSCENE_H__
#define _STARTSCENE_H__
#include "cocos2d.h"

class startScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void onEnter();
    //bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);// ´¥ÃþÊÂ¼þ¼àÌýÆ÷
    CREATE_FUNC(startScene);
    cocos2d::EventListenerCustom* interactListener;
    void startScene::menuCloseCallback(Ref* pSender);
};
#endif // !_STARTSCENE_H__

