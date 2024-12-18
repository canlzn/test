/****************************************************************
 * Project Name: xinglugu-project
 * File Cow.cpp
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.3
 * License:
 ****************************************************************/
#include "Cow.h"

USING_NS_CC;
bool Cow::init() {
    // 调用父类的 initWithFile 方法加载资源
    if (!Sprite::initWithFile("Cow.png")) 
    {
        CCLOG("Failed to load Cow.png");
        return false;
    }

    // 初始化属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

Cow* Cow::create() {
    Cow* cow = new Cow();
    if (cow && cow->init()) {
        cow->autorelease();
        return cow;
    }
    delete cow;
    return nullptr;
}

Cow::Cow()
{
    // 初始化牛的属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
    
}

Cow::~Cow()
{
    // 清理资源（如果有）
}

void Cow::produce()
{
    if (health_ > 0) {
        // 实现牛的产奶逻辑
        CCLOG("Cow has produced milk.");
        // 例如，增加牛奶库存
    }
    else {
        CCLOG("Cow is not healthy enough to produce milk.");
    }
}

void Cow::moo()
{
    CCLOG("Moo!");
    // 可以添加播放牛叫声音的逻辑
}

void Cow::heal(int amount)
{
    health_ += amount;
    if (health_ > Constants::kDefaultAnimalHealth) health_ = Constants::kDefaultAnimalHealth;
    CCLOG("Cow has been healed. Health: %d", health_);
}

void Cow::startWalkingAnimation() {

    Vector<SpriteFrame*> frames;

    // 假设你有 4 张行走图片：Cow_walk1.png, Cow_walk2.png, Cow_walk3.png, Cow_walk4.png
   
        frames.pushBack(SpriteFrame::create("Cow_walk1.png", Rect(0, 0, 32, 32))); // 假设每张图片的大小为 32x32
        frames.pushBack(SpriteFrame::create("Cow_walk2.png", Rect(0, 0, 32, 32)));
        frames.pushBack(SpriteFrame::create("Cow_walk3.png", Rect(0, 0, 32, 32)));
        frames.pushBack(SpriteFrame::create("Cow_walk1.png", Rect(0, 0, 32, 32)));

        // 检查是否成功加载每一帧
        for (int i = 0; i < frames.size(); ++i) {
            if (frames.at(i) == nullptr) {
                CCLOG("Failed to load frame %d", i + 1);
            }
        }

        

        // 创建动画对象
        Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f); // 每帧 0.2 秒
        Animate* animate = Animate::create(animation);

        //// 无限循环动画
        this->runAction(RepeatForever::create(animate));

        CCLOG("Cow walking animation started.");
    
}

//void Cow::moveTo(const Vec2& targetPosition, float duration) {
//    //// 创建一个 MoveTo 动作
//    //auto moveToAction = MoveTo::create(duration, targetPosition);
//
//    //// 添加一个回调，确保移动完成后可以进行一些操作
//    //auto callback = CallFunc::create([this]() {
//    //    CCLOG("Cow has moved to the target position.");
//    //    });
//
//    //// 运行序列动作（移动 + 回调）
//    //this->runAction(Sequence::create(moveToAction, callback, nullptr));
//    // 
//    //this->startWalkingAnimation();
//
//    //// 创建移动动作
//    //auto moveAction = MoveTo::create(duration, targetPosition);
//
//    //// 移动完成后停止动画的回调
//    //auto stopAnimation = CallFunc::create([this]() {
//    //    this->stopWalkingAnimation();
//    //    });
//
//    //// 将移动和停止动画的动作组合成序列
//    //auto sequence = Sequence::create(moveAction, stopAnimation, nullptr);
//
//    //// 运行动作
//    //this->runAction(sequence);
//    float distance = this->getPosition().distance(targetPosition);
//
//    // 根据距离和速度计算移动持续时间
//    duration = distance / Constants::kAnimalMoveSpeed;
//
//    // 启动行走动画
//    this->startWalkingAnimation();
//
//    // 创建移动动作
//    auto moveAction = MoveTo::create(duration, targetPosition);
//
//    // 移动完成后停止动画的回调
//    auto stopAnimation = CallFunc::create([this]() {
//        this->stopWalkingAnimation();
//        });
//
//    // 将移动和停止动画的动作组合成序列
//    auto sequence = Sequence::create(moveAction, stopAnimation, nullptr);
//
//    // 运行动作
//    this->runAction(sequence);
//}
//
//void Cow::moveBy(const Vec2& offset, float duration) {
//    // 创建一个 MoveBy 动作
//    auto moveByAction = MoveBy::create(duration, offset);
//
//    // 添加一个回调，确保移动完成后可以进行一些操作
//    auto callback = CallFunc::create([this]() {
//        CCLOG("Cow has moved by the offset.");
//        });
//
//    // 运行序列动作（移动 + 回调）
//    this->runAction(Sequence::create(moveByAction, callback, nullptr));
//}

//void Cow::moveToSequence(const std::vector<Vec2>& positions, float durationPerMove) {
//    // 检查输入的目标位置数组是否为空
//    if (positions.empty()) {
//        CCLOG("No positions provided for moveToSequence.");
//        return;
//    }
//
//    // 创建一个数组，用于存储所有的动作
//    Vector<FiniteTimeAction*> actions;
//
//    // 遍历目标位置数组，为每个目标创建一个 MoveTo 动作
//    for (const auto& targetPosition : positions) {
//        auto moveToAction = MoveTo::create(durationPerMove, targetPosition);
//        actions.pushBack(moveToAction);
//    }
//
//    // 添加一个回调动作，最后执行
//    auto callback = CallFunc::create([this]() {
//        CCLOG("Cow has finished all movements.");
//        });
//    actions.pushBack(callback);
//
//    // 创建序列动作
//    auto sequence = Sequence::create(actions);
//
//    // 运行动作序列
//    this->runAction(sequence);
//}

//void Cow::moveToSequence(const std::vector<Vec2>& positions, float durationPerMove) {
//    if (positions.empty()) {
//        CCLOG("No positions provided for moveToSequence.");
//        return;
//    }
//
//    // 创建一个动作数组用于存储所有移动动作
//    Vector<FiniteTimeAction*> actions;
//
//    // 在移动开始时启动行走动画
//    auto startWalking = CallFunc::create([this]() {
//        if (!isWalking_) {
//            this->startWalkingAnimation();
//        }
//        });
//    actions.pushBack(startWalking);
//
//    // 遍历所有目标位置，添加 MoveTo 动作
//    for (const auto& targetPosition : positions) {
//        auto moveToAction = MoveTo::create(durationPerMove, targetPosition);
//        actions.pushBack(moveToAction);
//    }
//
//    // 在移动结束时停止行走动画
//    auto stopWalking = CallFunc::create([this]() {
//        this->stopWalkingAnimation();
//        });
//    actions.pushBack(stopWalking);
//
//    // 创建一个序列动作并运行
//    auto sequence = Sequence::create(actions);
//    this->runAction(sequence);
//}

void Cow::stopWalkingAnimation() {
    // 停止所有动画，并设置为默认静止帧
    this->stopAllActions();
    isWalking_ = false;

    
    auto idleFrame = SpriteFrame::create("Cow_walk1.png", Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
    if (idleFrame) {
        this->setSpriteFrame(idleFrame);
    }

    CCLOG("Cow has stopped walking.");
}