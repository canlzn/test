#ifndef FRIENDSHIP_POPUP_LAYER_H
#define FRIENDSHIP_POPUP_LAYER_H

#include "cocos2d.h"

class FriendshipPopupLayer : public cocos2d::Layer {
public:
    static FriendshipPopupLayer* create();  // 用于创建该图层实例的静态函数声明
    bool initWithText(const std::string& text);  // 初始化函数声明，用于传入并设置提示文本内容
    void onCloseCallback(cocos2d::Ref* sender);  // 关闭按钮点击的回调函数声明

private:
    cocos2d::Sprite* backgroundSprite;  // 用于显示背景的精灵指针，作为提示界面的背景
    cocos2d::Label* textLabel;  // 用于显示提示文本的标签指针
};

#endif // FRIENDSHIP_POPUP_LAYER_H
