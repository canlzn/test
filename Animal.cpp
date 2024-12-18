/****************************************************************
 * Project Name: xinglugu-project
 * File NameAnimal.cpp
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.3
 * License:
 ****************************************************************/
#include "Animal.h"

USING_NS_CC;

Animal::Animal()
    : hunger_(Constants::kDefaultAnimalHunger),
    mood_(Constants::kDefaultAnimalMood),
    health_(Constants::kDefaultAnimalHealth),
    walkingCharacterNode(nullptr)


{
    // 可以在这里进行一些通用的初始化（如果需要）
}

Animal::~Animal()
{
    // 清理资源（如果有）
}

void Animal::feed()
{
    // 实现喂养逻辑
    hunger_ -= 10;
    if (hunger_ < 0) hunger_ = 0;
    mood_ += 5;
    if (mood_ > 100) mood_ = 100;

    // 可以根据需要添加更多逻辑，例如更新显示状态
    CCLOG("Animal has been fed. Hunger: %d, Mood: %d", hunger_, mood_);
}

int Animal::getHunger() const
{
    return hunger_;
}

void Animal::setHunger(int value)
{
    hunger_ = value;
}

int Animal::getMood() const
{
    return mood_;
}

void Animal::setMood(int value)
{
    mood_ = value;
}

int Animal::getHealth() const
{
    return health_;
}

void Animal::setHealth(int value)
{
    health_ = value;
}

void Animal::moveTo(const Vec2& targetPosition) {
    // 计算移动距离
    float distance = this->getPosition().distance(targetPosition);

    // 根据距离和速度计算移动持续时间
    float duration = distance / Constants::kAnimalMoveSpeed;

    // 启动行走动画
    this->startWalkingAnimation();

    // 创建移动动作
    auto moveAction = MoveTo::create(duration, targetPosition);

    // 移动完成后停止动画的回调
    auto stopAnimation = CallFunc::create([this]() {
        this->stopWalkingAnimation();
        });

    // 将移动和停止动画的动作组合成序列
    auto sequence = Sequence::create(moveAction, stopAnimation, nullptr);

    // 运行动作
    this->runAction(sequence);
}

void Animal::moveToSequence(const std::vector<Vec2>& positions) {
    Vector<FiniteTimeAction*> actions;

    for (const auto& position : positions) {
        // 计算每段移动距离
        float distance = this->getPosition().distance(position);

        // 根据距离和速度计算移动持续时间
        float duration = distance / Constants::kAnimalMoveSpeed;

        // 添加移动动作
        actions.pushBack(MoveTo::create(duration, position));
    }

    // 添加停止动画的回调
    actions.pushBack(CallFunc::create([this]() {
        this->stopWalkingAnimation();
        }));

    // 启动行走动画
    this->startWalkingAnimation();

    // 创建动作序列并运行
    this->runAction(Sequence::create(actions));
}

void Animal::startWalkingAnimation() {
    // 默认实现，子类可以重写
    CCLOG("Start walking animation (default)");
}

void Animal::stopWalkingAnimation() {
    // 默认实现，子类可以重写
    CCLOG("Stop walking animation (default)");
}