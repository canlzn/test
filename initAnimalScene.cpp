/****************************************************************
 * Project Name: xinglugu-project
 * File initAnimalScene.cpp
 * File Function: init Animal on Scene
 * Author:Gao wenhao
 * Update Date:2024.12.5
 * License:
 ****************************************************************/

#include"initAnimalScene.h"

USING_NS_CC;


void setupAnimal(Scene* scene) {
    auto cow = Cow::create();
    auto pig = Pig::create();
    if (!pig) {
        CCLOG("Fail to creat pig");
        return;
    }
   
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    cow->setPosition(Vec2(
        origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height / 2
    ));
    pig->setPosition(Vec2(
        origin.x + visibleSize.width / 2 +10,
        origin.y + visibleSize.height / 2+ 10
    ));

    scene->addChild(cow, Constants::kAnimalLayerZOrder);
    // 启动随机移动逻辑
    cow->schedule([cow, visibleSize, origin](float) {
        if (!cow->getNumberOfRunningActions()) { // 如果当前没有正在执行的移动动作
            // 随机生成目标位置
            float targetX = origin.x + CCRANDOM_0_1() * visibleSize.width;
            float targetY = origin.y + CCRANDOM_0_1() * visibleSize.height;
            Vec2 targetPosition(targetX, targetY);// 移动到目标位置                      
            cow->moveTo(targetPosition);

        }
        }, 0.1f, "cow_random_move"); // 每 0.1 秒检查一次

    // 为 Cow 添加触摸监听器

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [cow](Touch* touch, Event* event) -> bool {
        Vec2 touchLocation = touch->getLocation(); // 获取触摸位置
        if (cow->getBoundingBox().containsPoint(cow->getParent()->convertToNodeSpace(touchLocation))) {
            CCLOG("This is a cow"); // 打印点击信息
            cow->moo();
            cow->stopWalkingAnimation();
            
            return true; // 消耗事件，停止传播
        }
        return false; // 未点击到牛，继续传播事件
        };

    // 将触摸监听器绑定到事件分发器
    scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, cow);

    scene->addChild(pig, Constants::kAnimalLayerZOrder);

    // 启动随机移动逻辑
    pig->schedule([pig, visibleSize, origin](float) {
        if (!pig->getNumberOfRunningActions()) { // 如果当前没有正在执行的移动动作
            // 随机生成目标位置
            float targetX = origin.x + CCRANDOM_0_1() * visibleSize.width;
            float targetY = origin.y + CCRANDOM_0_1() * visibleSize.height;
            Vec2 targetPosition(targetX, targetY);// 移动到目标位置                      
            pig->moveTo(targetPosition);

        }
        }, 0.1f, "cow_random_move"); // 每 0.1 秒检查一次

    // 为 Cow 添加触摸监听器
    
    auto touchListener_pig = EventListenerTouchOneByOne::create();
    touchListener_pig->onTouchBegan = [pig](Touch* touch, Event* event) -> bool {
        Vec2 touchLocation = touch->getLocation(); // 获取触摸位置
        if (pig->getBoundingBox().containsPoint(pig->getParent()->convertToNodeSpace(touchLocation))) {
            CCLOG("This is a pig"); // 打印点击信息
            pig->oink();
            pig->stopWalkingAnimation();
          
            return true; // 消耗事件，停止传播
        }
        return false; // 未点击到牛，继续传播事件
        };

    // 将触摸监听器绑定到事件分发器
    scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener_pig, pig);
}

