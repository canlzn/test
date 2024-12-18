/****************************************************************
 * Project Name: xinglugu-project
 * File Chicken.cpp
 * File Function: Implementation of Chicken class
 * Author: Gao wenhao
 * Update Date: 2024.12.6
 * License:
 ****************************************************************/
#include "Chicken.h"

USING_NS_CC;

bool Chicken::init() {
    // 调用父类的 initWithFile 方法加载资源
    if (!Sprite::initWithFile("Chicken.png")) {
        CCLOG("Failed to load Chicken.png");
        return false;
    }

    // 初始化属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

Chicken* Chicken::create() {
    Chicken* chicken = new Chicken();
    if (chicken && chicken->init()) {
        chicken->autorelease();
        return chicken;
    }
    delete chicken;
    return nullptr;
}

Chicken::Chicken() {
    // 初始化鸡的属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
}

Chicken::~Chicken() {
    // 清理资源（如果有）
}

void Chicken::produce() {
    if (health_ > 0) {
        // 实现鸡的产蛋逻辑
        CCLOG("Chicken has laid an egg.");
    }
    else {
        CCLOG("Chicken is not healthy enough to lay eggs.");
    }
}

void Chicken::cluck() {
    CCLOG("Cluck cluck!");
    // 可以添加播放鸡叫声音的逻辑
}

void Chicken::heal(int amount) {
    health_ += amount;
    if (health_ > Constants::kDefaultAnimalHealth) health_ = Constants::kDefaultAnimalHealth;
    CCLOG("Chicken has been healed. Health: %d", health_);
}

void Chicken::startWalkingAnimation() {
    Vector<SpriteFrame*> frames;

    // 假设你有 4 张行走图片：Chicken_walk1.png, Chicken_walk2.png, Chicken_walk3.png, Chicken_walk4.png
    frames.pushBack(SpriteFrame::create("Chicken_walk1.png", Rect(0, 0, 32, 32))); // 假设每张图片的大小为 32x32
    frames.pushBack(SpriteFrame::create("Chicken_walk2.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Chicken_walk3.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Chicken_walk4.png", Rect(0, 0, 32, 32)));

    // 检查是否成功加载每一帧
    for (int i = 0; i < frames.size(); ++i) {
        if (frames.at(i) == nullptr) {
            CCLOG("Failed to load frame %d", i + 1);
        }
    }

    // 创建动画对象
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f); // 每帧 0.2 秒
    Animate* animate = Animate::create(animation);

    // 无限循环动画
    this->runAction(RepeatForever::create(animate));

    isWalking_ = true;
    CCLOG("Chicken walking animation started.");
}

void Chicken::stopWalkingAnimation() {
    // 停止所有动画，并设置为默认静止帧
    this->stopAllActions();
    isWalking_ = false;

    auto idleFrame = SpriteFrame::create("Chicken_walk1.png", Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
    if (idleFrame) {
        this->setSpriteFrame(idleFrame);
    }

    CCLOG("Chicken has stopped walking.");
}