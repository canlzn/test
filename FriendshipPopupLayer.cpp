#include "FriendshipPopupLayer.h"

// 创建FriendshipPopupLayer实例的函数实现
FriendshipPopupLayer* FriendshipPopupLayer::create() {
    FriendshipPopupLayer* layer = new FriendshipPopupLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

// 初始化函数实现，用于设置提示界面的具体内容和样式
bool FriendshipPopupLayer::initWithText(const std::string& text) {
    if (!Layer::init()) {
        return false;
    }

    // 创建背景精灵，这里假设你有一张名为popup_background.png的图片作为提示界面的背景图片，你可根据实际替换
    backgroundSprite = cocos2d::Sprite::create("popup_background.png");
    backgroundSprite->setPosition(this->getContentSize() / 2);
    this->addChild(backgroundSprite);

    // 创建文本标签，设置文本内容、字体和字号等，这里假设字体文件名为your_font.ttf，你需根据实际替换
    textLabel = cocos2d::Label::createWithTTF(text, "fonts/your_font.ttf", 24);
    textLabel->setPosition(backgroundSprite->getContentSize() / 2);
    backgroundSprite->addChild(textLabel);

    // 创建关闭按钮，使用两张不同状态的图片（正常和按下状态），这里假设图片名为close_button_normal.png和close_button_pressed.png，可按需替换
    cocos2d::MenuItemImage* closeButton = cocos2d::MenuItemImage::create(
        "close_button_normal.png",
        "close_button_pressed.png",
        CC_CALLBACK_1(FriendshipPopupLayer::onCloseCallback, this)
    );
    closeButton->setPosition(backgroundSprite->getContentSize().width - closeButton->getContentSize().width / 2,
        closeButton->getContentSize().height / 2);

    // 创建菜单并添加关闭按钮，菜单用于管理按钮等交互元素在界面上的布局和响应逻辑
    cocos2d::Menu* menu = cocos2d::Menu::create(closeButton, nullptr);
    menu->setPosition(cocos2d::Vec2::ZERO);
    backgroundSprite->addChild(menu);

    return true;
}

// 关闭按钮点击的回调函数实现，用于移除提示界面图层
void FriendshipPopupLayer::onCloseCallback(cocos2d::Ref* sender) {
    this->removeFromParent();
}