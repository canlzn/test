/****************************************************************
 * Project Name: xinglugu-project
 * File:Character.h
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.7
 * License:
 ****************************************************************/
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Constants.h"
#include "cocos2d.h"
#include "Walking.h"
class Player;


// 方向的枚举
enum class Direction {
    f,
    b,
    l,
    r
};

enum class AnimationState {
    IDLE,
    WALKING,
    RUNNING,
    INTERACTING
};

class Character : public Node
{
public:

    Character()
        : name("DefaultCharacter"),
        health(Constants::OriginHealth),
        animationState(AnimationState::IDLE) {}

    Character(const std::string& name, int health)
        : name(name),
        health(Constants::OriginHealth),
        animationState(AnimationState::IDLE) {}


    //角色移动
    void Moving(Sprite* sprite, int direction, float t);
    void MovingContenly(Sprite* sprite, int direction, float t);
    //角色停止移动
    void stopMoving(Sprite* sprite);

    //角色停止一切动作
    void stop();

    // 获取角色名称
    std::string getName() { return name; }

    // 设置角色名称
    void setName(int newName) { name = newName; }

    // 获取角色生命值
    int getHealth() const { return health; }

    // 设置角色生命值
    void setHealth(int newHealth) { health = newHealth; }

    // 获取动画状态
    AnimationState getAnimationState() const { return animationState; }

    // 设置动画状态
    void setAnimationState(AnimationState newState) { animationState = newState; }


  

    std::string name;
protected:
    
    int health;
    AnimationState animationState;
};

#endif 