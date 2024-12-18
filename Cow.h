/****************************************************************
 * Project Name: xinglugu-project
 * File Cow.h
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.5
 * License:
 ****************************************************************/
#ifndef COW_H
#define COW_H

#include "Animal.h"

class Cow : public Animal
{
public:
    // 构造函数
    Cow();

    // 虚析构函数
    virtual ~Cow();

    static Cow* create();
    virtual bool init() override;
    // 实现产出方法
    virtual void produce() override;

    // 牛的特有方法
    void moo();

    //void startWalkingAnimation(); //启动行走动画
    //void stopWalkingAnimation();
    //void moveToSequence(const std::vector<cocos2d::Vec2>& positions, float durationPerMove);
    //void moveTo(const cocos2d::Vec2& targetPosition, float duration);//控制移动
    //void moveBy(const cocos2d::Vec2& offset, float duration);
    
    virtual void startWalkingAnimation() override;
    virtual void stopWalkingAnimation() override;

    // 治疗牛的方法
    void heal(int amount);
    bool isWalking_ = false;
};

#endif // COW_H