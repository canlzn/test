/****************************************************************
 * Project Name: xinglugu-project
 * File Name:MainScene.cpp
 * File Function: init the Scene
 * Author:All
 * Update Date:2024.12.3
 * License:
 ****************************************************************/


#include "MainScene.h"
#include "simpleaudioengine.h"
#include "Cow.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "back.h"
#include "backPhoto.h"
#include "SceneTouch.h"
#include "Constants.h"
#include"Fishing.h"


USING_NS_CC;
USING_NS_CC::ui;
using namespace CocosDenshion;
cocos2d::Scene* g_sharedScene = nullptr;

cocos2d::TMXTiledMap* g_sharedTMXone = nullptr;


//背包创建
backPack* pack1 = backPack::create();

Scene* MainScene::createScene() {
    return MainScene::create();
}


bool MainScene::init() {
    auto audio = SimpleAudioEngine::getInstance();
    // set the background music and continuously play it.
    audio->playBackgroundMusic("background.mp3", true);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // 加载 TMX 地图

    auto glview = Director::getInstance()->getOpenGLView();
    glview->setDesignResolutionSize(Constants::kMapWidth, Constants::kMapLength, ResolutionPolicy::SHOW_ALL);

    // 确保内容缩放因子为 1.0
    Director::getInstance()->setContentScaleFactor(1.0f);

    // 创建并添加地图
    //auto map = TMXTiledMap::create("nf.tmx");
    auto map = g_sharedTMXone;
    CCLOG("g_sharedTMXone Anchor Point: %f, %f", map->getAnchorPoint().x, map->getAnchorPoint().y);
    CCLOG("g_sharedTMXone Position: %f, %f", map->getPosition().x, map->getPosition().y);
    CCLOG("g_sharedTMXone Scale: %f", map->getScale());
    CCLOG("g_sharedTMXone Content Size: %f x %f", map->getContentSize().width, map->getContentSize().height);

    map->setAnchorPoint(Vec2(0, 0)); // 左下角对齐
    map->setPosition(Vec2(0, 0));
    map->setScale(Constants::kScale); // 确保地图未被缩放

    this->addChild(map, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE, "map01");
    this->addChild(g_sharedTMXtwo, Constants::MAP_BACKGROUND_LAYER_Z_BASIC, "map02");
    this->addChild(g_sharedTMXthree, Constants::MAP_BACKGROUND_LAYER_Z_MIDDLE, "map03");

    if (g_sharedTMXone) {
        auto mapSize = g_sharedTMXtwo->getMapSize();
        auto tileSize = g_sharedTMXtwo->getTileSize();

        CCLOG("Map Size: %f x %f, Tile Size: %f x %f", mapSize.width, mapSize.height, tileSize.width, tileSize.height);

        auto layer = g_sharedTMXtwo->getLayer("someLayerName");
        if (layer) {
            CCLOG("Successfully accessed layer.");
        }
        else {
            CCLOG("Failed to access layer. Map might not be fully initialized.");
        }
    }

    

    g_sharedScene = this;
    if (!map) {
        CCLOG("Failed to load TMX map.tmx");
        return false;
    }


    inventory(this, pack1, origin);

    auto layerfish = Layer::create();
    map->addChild(layerfish,3);
    // 添加钓鱼按钮
    MainScene::addFishingButtonToScene(layerfish, visibleSize);

    //setupAnimal(this);// 创建动物

    //setupWalkingCharacter(visibleSize, origin);

    auto touchListener = EventListenerTouchOneByOne::create();



    // backPack* localPack = pack1;
    touchListener->onTouchBegan = [map](Touch* touch, Event* event) {
        return onTouchBegan(touch, event, map, pack1);
        };
    //npc1可以用键盘控制，可看作玩家

    auto npc1 = NPC_1::create();
    if (npc1) {

        g_sharedScene->addChild(npc1, Constants::MAP_BACKGROUND_LAYER_Z_ORDER + 10);
        // 通过创建好的npc1Obj对象来调用testAddNPC_1函数
        npc1->testAddNPC_1(visibleSize, origin, map, this);
        CCLOG("NPC_1 position: (%f, %f)", npc1->getPosition().x, npc1->getPosition().y);
    }

  

    auto npc3 = NPC_3::create();
    if (npc3) {
        g_sharedScene->addChild(npc3, Constants::MAP_BACKGROUND_LAYER_Z_ORDER + 10);
        Vec2 pos;
        pos.x = visibleSize.width / 4 - 8;
        pos.y =  visibleSize.height / 2 - 8;
        npc3->testAddNPC_3(visibleSize, origin,"Harvey",pos);
    }
    auto npc2 = NPC_3::create();
    if (npc2) {
        g_sharedScene->addChild(npc2, Constants::MAP_BACKGROUND_LAYER_Z_ORDER + 10);
        Vec2 pos;
        pos.x = 3*visibleSize.width / 4 - 8;
        pos.y =  visibleSize.height/4 -8;
        npc2->testAddNPC_3(visibleSize, origin, "Haley", pos);
    }





    // 将监听器添加到事件分发器中
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    //auto button = ui::Button::create("button_normal.png", "button_pressed.png");
    //button->setTitleText("Switch Map?");
    //button->setTitleFontSize(24);
    //button->setPosition(Vec2(50, 50));
    //this->addChild(button, 100);

    //// 按钮点击事件
    //button->addClickEventListener([=](Ref* sender) {
    //    CCLOG("Press");
    //    button->removeFromParent();
    //    });
    //return true;
}

//单选按钮集合

void MainScene::onEnter() {
    Scene::onEnter();
    backPhoto(this, pack1, _eventDispatcher);
    Item* newItem = terial::create("wood");
    pack1->itemAdd(newItem, 1);

}


void MainScene::setupWalkingCharacter(const Size& visibleSize, Vec2 origin) {

    // 创建WalkingCharacter实例并添加到当前场景中
    auto walkingCharacterNode = WalkingCharacter::create();
    walkingCharacterNode->setVisible(true);  // 确保节点可见
    this->addChild(walkingCharacterNode);

    // 通过接口设置WalkingCharacter的图片路径，这里先用一只兔子测试，可根据实际需求修改
    walkingCharacterNode->setImagePath("rabbit_test.png");
    //walkingCharacterNode->setImagePath("Cow_move.png");
    // 直接使用之前已经定义好的visibleSize和origin变量
    // 获取画面中心位置坐标
    Vec2 centerPosition = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

    // 设置WalkingCharacter的位置为画面中心位置
    walkingCharacterNode->setPosition(centerPosition);

    // 获取角色精灵（假设WalkingCharacter类中有获取精灵的方法）
    auto characterSprite = walkingCharacterNode->getCharacterSprite();
    if (characterSprite) {
        // 创建移动动作，让角色先向右移动200像素，用时3秒
        auto moveRightAction = MoveBy::create(3.0f, Vec2(200, 0));
        // 再向下移动100像素，用时2秒
        auto moveDownAction = MoveBy::create(2.0f, Vec2(0, -100));
        // 创建动作序列，先执行向右移动，再执行向下移动
        auto sequenceAction = Sequence::create(moveRightAction, moveDownAction, nullptr);
        // 让角色精灵循环执行该动作序列，实现循环移动
        characterSprite->runAction(RepeatForever::create(sequenceAction));

    }
}

void MainScene::addFishingButtonToScene(Layer* layer, const Size& visibleSize) {
    // 创建钓鱼按钮
    auto fishingButton = MenuItemImage::create("fishing.png", "fishing.png",
        CC_CALLBACK_1(MainScene::onFishingButtonClicked, this));
    fishingButton->setPosition(32, visibleSize.height / 2); // 将按钮放在

    // 创建菜单并将按钮添加到菜单中
    auto menu = Menu::create(fishingButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    layer->addChild(menu);
}

void MainScene::onFishingButtonClicked(Ref* sender) {
    // 创建钓鱼层
    auto fishingLayer = FishingLayer::createLayer();

    // 获取当前场景并将钓鱼层添加到场景中
    auto runningScene = Director::getInstance()->getRunningScene();
    if (runningScene) {
        runningScene->addChild(fishingLayer, 3); // 确保层级为3，使其显示在其他元素上方
    }
    else {
        CCLOG("Failed to get running scene.");
    }
}

