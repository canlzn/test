/****************************************************************
 * Project Name: xinglugu-project
 * File Pig.h
 * File Function: Class representing a pig on the farm
 * Author: Gao wenhao
 * Update Date: 2024.12.6
 * License:
 ****************************************************************/
#ifndef PIG_H
#define PIG_H

#include "Animal.h"

class Pig : public Animal
{
public:
    // 构造函数
    Pig();

    // 虚析构函数
    virtual ~Pig();

    static Pig* create();
    virtual bool init() override;

    // 实现产出方法
    virtual void produce() override;

    // 猪的特有方法
    void oink(); // 猪叫声

    // 动画控制
    virtual void startWalkingAnimation() override;
    virtual void stopWalkingAnimation() override;

    // 治疗方法
    void heal(int amount);

    bool isWalking_ = false; // 是否在移动状态
};

#endif // PIG_H