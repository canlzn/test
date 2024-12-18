/****************************************************************
 * Project Name: xinglugu-project
 * File Pig.cpp
 * File Function: Implementation of Pig class
 * Author: Gao wenhao
 * Update Date: 2024.12.6
 * License:
 ****************************************************************/
#include "Pig.h"

USING_NS_CC;

bool Pig::init() {
    // 调用父类的 initWithFile 方法加载资源
    if (!Sprite::initWithFile("Pig_walk1.png")) 
    
    {
        CCLOG("Failed to load Pig.png");
        return false;
    }

    // 初始化属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

Pig* Pig::create() {
    Pig* pig = new Pig();
    if (pig && pig->init()) {
        pig->autorelease();
        return pig;
    }
    delete pig;
    return nullptr;
}

Pig::Pig() {
    // 初始化猪的属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
}

Pig::~Pig() {
    // 清理资源（如果有）
}

void Pig::produce() {
    if (health_ > 0) {
        // 实现猪的产出逻辑（例如猪肉或肥料）
        CCLOG("Pig has produced fertilizer.");
    }
    else {
        CCLOG("Pig is not healthy enough to produce.");
    }
}

void Pig::oink() {
    CCLOG("Oink!");
    // 可以添加播放猪叫声音的逻辑
}

void Pig::heal(int amount) {
    health_ += amount;
    if (health_ > Constants::kDefaultAnimalHealth) health_ = Constants::kDefaultAnimalHealth;
    CCLOG("Pig has been healed. Health: %d", health_);
}

void Pig::startWalkingAnimation() {
    Vector<SpriteFrame*> frames;

    //// 假设你有 4 张行走图片：Pig_walk1.png, Pig_walk2.png, Pig_walk3.png, Pig_walk4.png
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));

    //// 检查是否成功加载每一帧
    //for (int i = 0; i < frames.size(); ++i) {
    //    if (frames.at(i) == nullptr) {
    //        CCLOG("Failed to load frame %d", i + 1);
    //    }
    //}
    auto spriteSheet = "PigWalk.png"; // 假设大图名为 Pig_walks.png，包含 Pig_walk1 ~ Pig_walk4
    auto spriteWidth = 32;  // 每张子图的宽度
    auto spriteHeight = 32; // 每张子图的高度

    // 加载精灵表
    auto texture = Director::getInstance()->getTextureCache()->addImage(spriteSheet);
    if (!texture) {
        CCLOG("Failed to load sprite sheet: %s", spriteSheet);
    }
    else {
        for (int i = 0; i < 4; ++i) { // 遍历子图
            Rect rect(i * spriteWidth, 0, spriteWidth, spriteHeight); // 计算子图的位置
            auto frame = SpriteFrame::createWithTexture(texture, rect);
            if (frame) {
                frames.pushBack(frame); // 将子图帧加入 frames
            }
            else {
                CCLOG("Failed to create frame for index: %d", i);
            }
        }
    }

    // 检查是否成功加载每一帧
    for (int i = 0; i < frames.size(); ++i) {
        if (frames.at(i) == nullptr) {
            CCLOG("Failed to load frame %d", i + 1);
        }
        else {
            CCLOG("Loaded frame %d successfully", i + 1);
        }
    }
    // 创建动画对象
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f); // 每帧 0.2 秒
    Animate* animate = Animate::create(animation);

    // 无限循环动画
    this->runAction(RepeatForever::create(animate));

    isWalking_ = true;
    CCLOG("Pig walking animation started.");
}

void Pig::stopWalkingAnimation() {
    // 停止所有动画，并设置为默认静止帧
    this->stopAllActions();
    isWalking_ = false;

    auto idleFrame = SpriteFrame::create("Pig_walk4.png", Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
    if (idleFrame) {
        this->setSpriteFrame(idleFrame);
    }

    CCLOG("Pig has stopped walking.");
}