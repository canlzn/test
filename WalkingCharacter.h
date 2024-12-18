#ifndef WALKING_CHARACTER_H
#define WALKING_CHARACTER_H

#include "cocos2d.h"

class WalkingCharacter : public cocos2d::Node {
public:
    static WalkingCharacter* create();
    virtual bool init();
    // 用于设置图片路径
    void setImagePath(const std::string& imagePath);
    cocos2d::Sprite* getCharacterSprite();
private:
    cocos2d::Sprite* _characterSprite;  // 代表角色的精灵
    cocos2d::Vector<cocos2d::SpriteFrame*> _walkFrames;  // 用于存储角色走路动画的帧（图片）
    int _currentFrameIndex;  // 当前显示的帧索引
    void loadWalkFramesFromImage(const std::string& imagePath);  // 从给定图片路径加载走路动画帧（处理拼图情况）
    void playWalkAnimationOnce();  // 播放走路动画一次，用于实现角色走一步的功能，与cpp文件中的对应函数匹配
};

#endif