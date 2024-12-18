#include "WalkingCharacter.h"

USING_NS_CC;

// 创建函数，遵循Cocos2d-x的创建对象规范
WalkingCharacter* WalkingCharacter::create() {
    WalkingCharacter* ret = new (std::nothrow) WalkingCharacter();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    else {
        delete ret;
        return nullptr;
    }
}

// 初始化函数
bool WalkingCharacter::init() {
    if (!Node::init()) {
        return false;
    }

    // 创建角色精灵，先不关联具体图片，后面通过加载帧来设置图片
    _characterSprite = Sprite::create();
    if (_characterSprite) {
        this->addChild(_characterSprite);
    }

    // 初始化时不加载图片路径，等待外部调用setImagePath来设置
    _currentFrameIndex = 0;
    return true;
}

// 新增函数用于设置图片路径并加载帧
void WalkingCharacter::setImagePath(const std::string& imagePath) {
    loadWalkFramesFromImage(imagePath);
    playWalkAnimationOnce();
}

// 从给定图片路径加载走路动画帧（处理拼图情况）（一般都是走或跑的动作连成一张拼图）
void WalkingCharacter::loadWalkFramesFromImage(const std::string& imagePath) {
    // 使用TextureCache获取纹理，纹理缓存可以避免重复加载相同纹理，提高性能
    auto texture = Director::getInstance()->getTextureCache()->addImage(imagePath);

    // 假设四张图片连在一起，且每张图片大小相同（可根据实际情况调整下面计算方式）
    Size frameSize = Size(texture->getContentSize().width / 4, texture->getContentSize().height);

    // 循环提取四张图片作为动画帧
    for (int i = 0; i < 4; ++i) {
        Rect rect(i * frameSize.width, 0, frameSize.width, frameSize.height);
        auto spriteFrame = SpriteFrame::createWithTexture(texture, rect);
        _walkFrames.pushBack(spriteFrame);
    }
}

// 播放走路动画，实现只播放一次来模拟走一步
void WalkingCharacter::playWalkAnimationOnce() {
    // 创建一个动画对象，设置一些参数
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.2f);  // 每帧间隔时间，控制走路速度，可根据实际调整

    // 将之前加载好的帧添加到动画对象中
    for (const auto& frame : _walkFrames) {
        animation->addSpriteFrame(frame);
    }

    // 创建一个动画动作，关联前面创建的动画对象
    auto animateAction = Animate::create(animation);

    // 创建一个回调函数动作，在动画播放完后执行
    auto callbackAction = CallFunc::create([this]() {
        
        _characterSprite->stopAllActions();
        // 动画播放完后，将当前帧索引重置为0，以便下次播放动画时从第一帧开始
        _currentFrameIndex = 0;
        });

    // 使用顺序动作组合，先播放动画动作，然后执行回调函数动作
    auto sequenceAction = Sequence::create(animateAction, callbackAction, nullptr);

    // 让角色精灵执行顺序动作组合
    _characterSprite->runAction(sequenceAction);
}

// 实现获取角色精灵的函数，保持不变，因为逻辑就是简单返回成员变量_characterSprite的指针
cocos2d::Sprite* WalkingCharacter::getCharacterSprite() {
    return _characterSprite;
}