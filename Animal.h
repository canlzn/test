/****************************************************************
 * Project Name: xinglugu-project
 * FileAnimal.h
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.3
 * License:
 ****************************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H

#include "Constants.h"
#include "cocos2d.h"
#include "WalkingCharacter.h"

class Animal : public cocos2d::Sprite
{
public:
    // 构造函数
    Animal();

    // 虚析构函数，确保子类的析构函数被正确调用
    virtual ~Animal();

    // 喂养动物的方法
    void feed();

    // 产出方法，纯虚函数，需要在子类中实现
    virtual void produce() = 0;

    // 获取饥饿度
    int getHunger() const;

    // 设置饥饿度
    void setHunger(int value);

    // 获取心情
    int getMood() const;

    // 设置心情
    void setMood(int value);

    // 获取血量
    int getHealth() const;

    // 设置血量
    void setHealth(int value);

    // 通用方法
    void moveTo(const cocos2d::Vec2& targetPosition);              // 移动到指定位置
    void moveToSequence(const std::vector<cocos2d::Vec2>& positions); // 连续移动到多个位置
    virtual void startWalkingAnimation();  // 启动行走动画（虚函数，子类可以重写）
    virtual void stopWalkingAnimation();   // 停止行走动画（虚函数，子类可以重写）

    //void toggleMovement(); // 切换移动状态
    //void stopMovement();   // 停止移动
    //void resumeMovement(); // 恢复移动

    //void moveRandomly();

  /*  virtual bool init() override;*/

protected:
    int hunger_ = Constants::kDefaultAnimalHunger;    // 默认饥饿度
    int mood_ = Constants::kDefaultAnimalMood;        // 默认心情
    int health_ = Constants::kDefaultAnimalHealth;    // 默认血量
    WalkingCharacter* walkingCharacterNode = nullptr;

    //bool isMoving_;                      // 当前是否在移动
    //std::vector<cocos2d::Vec2> path_;    // 当前的移动路径
    //size_t currentTargetIndex_;          // 路径中的当前位置索引
};

#endif // ANIMAL_H