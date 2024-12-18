/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC.cpp
 * File Function: 
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#include "NPC.h"
#include "NPC_1.h"

USING_NS_CC;

//创建 NPC 对象并进行初始化
NPC::NPC(const std::string& name, int health) : Character(name, health) 
{
    dialogueText = "";
    quests = std::vector<QuestInfo>();
}




//初始化以及触摸事件相关的设置
NPC::NPC()
    : isPlayerInRange(false)
{
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        cocos2d::Vec2 touchLocation = this->convertToNodeSpace(touch->getLocation());
        cocos2d::Rect boundingBox = this->getBoundingBox();
        if (boundingBox.containsPoint(touchLocation)) {
            // 假设NPC_1是玩家角色，通过判断实例类型来确定是否为玩家交互
            if (dynamic_cast<NPC_1*>(this) != nullptr) {
                // 这里可以添加玩家角色触摸开始时的具体逻辑，比如打开交互菜单等
                return true;
            }
            else {
                // 对于非玩家角色的NPC（NPC_2、NPC_3等），可以添加相应交互逻辑，比如显示提示信息等
                return false;
            }
        }
        return false;
        };

    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
NPC::~NPC() {
    auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();

    auto listenerToRemove = cocos2d::EventListenerTouchOneByOne::create();

    listenerToRemove->setSwallowTouches(true);

    dispatcher->removeEventListener(listenerToRemove);
}







// NPC提供对话内容的方法实现
std::string NPC::getDialogue() {
    return "欢迎来到这里，希望你过得愉快！";
}

