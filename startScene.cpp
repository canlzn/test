#include "startScene.h"
#include "cocos2d.h"
#include"MainScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* startScene::createScene() {
	return startScene::create();
}

// on "init" you need to initialize your instance
bool startScene::init()
{
    auto audio = SimpleAudioEngine::getInstance();

    // set the background music and continuously play it.
    audio->playBackgroundMusic("background.mp3", true);
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
        "load.png",
        "load.png",
        CC_CALLBACK_1(startScene::menuCloseCallback, this));


        float x = origin.x + visibleSize.width/1.65 - closeItem->getContentSize().width / 2;
        float y = origin.y + visibleSize.height/4 + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));


    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    
    auto label = Label::createWithTTF("Stardew Valley", "Comic Sans MS.ttf", 80);

        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 2);

        auto startBoard = Sprite::create("startBoard.png");
        startBoard->setScaleX(visibleSize.width / startBoard->getContentSize().width);
        startBoard->setScaleY(visibleSize.height / startBoard->getContentSize().height);
        startBoard->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        this->addChild(startBoard, 1);

    return true;
}

void startScene::onEnter() {
    Scene::onEnter();
}

void startScene::menuCloseCallback(Ref* pSender)
{
    this->pause();
    auto scene = MainScene::createScene();
    // run
    Director::getInstance()->replaceScene(scene);
}
