/****************************************************************
 * Project Name: xinglugu-project
 * File Chicken.h
 * File Function: Class representing a chicken on the farm
 * Author: Gao wenhao
 * Update Date: 2024.12.6
 * License:
 ****************************************************************/
#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"

class Chicken : public Animal
{
public:
    // 构造函数
    Chicken();

    // 虚析构函数
    virtual ~Chicken();

    static Chicken* create();
    virtual bool init() override;

    // 实现产出方法
    virtual void produce() override;

    // 鸡的特有方法
    void cluck(); // 鸡叫声

    // 动画控制
    virtual void startWalkingAnimation() override;
    virtual void stopWalkingAnimation() override;

    // 治疗方法
    void heal(int amount);

    bool isWalking_ = false; // 是否在移动状态
};

#endif // CHICKEN_H