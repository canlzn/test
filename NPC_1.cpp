/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC_1.cpp
 * File Function:
 * Author: Sun Yining Gao Wenhao
 * Update Date: 2024.12.15
 * License:
 ****************************************************************/
#include "NPC_1.h"
#include "Walking.h"
#include"string"
#include "Constants.h"
#include "MapControl.h"
#include "ui/CocosGUI.h"
#include "GlobalVariables.h"

Vec2 convertToScreenOrigin(const Vec2& position, const Size& visibleSize) {
    // 原点转换公式
    float x = position.x + (visibleSize.width / 2 - 8);
    float y = -position.y + (visibleSize.height / 2 - 8) - 16;

    return Vec2(x, y);
}


void NPC_1::moveUp(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize) {
    Vec2 currentPosition = Endposition;
    CCLOG("NPC Current screen position: (%f, %f)", currentPosition.x, currentPosition.y);
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
    CCLOG("NPC Screen coordinate: (%f, %f)", screenCoord.x, screenCoord.y);
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, map);

    if (tileCoord == Vec2(-1, -1)) {
        CCLOG("Current position is outside the map bounds.");
        return;
    }
    CCLOG("Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);

    Vec2 targetTileCoord = Vec2(tileCoord.x, tileCoord.y - 1); // 向上移动 y-1
    CCLOG("Target tile coordinate: (%f, %f)", targetTileCoord.x, targetTileCoord.y);

    TMXLayer* pathLayer = map->getLayer("path");
    if (!pathLayer) {
        CCLOG("Path layer not found!");
        return;
    }

    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    if (gid <= 0) {
        CCLOG("GID is invalid or no tile at (%f, %f). Moving anyway.", targetTileCoord.x, targetTileCoord.y);
        Character::Moving(sprite, 1,0.5f);
        Endposition.y -= movelength;
        npc_1_d = 'b';
        return;
    }

    Value properties = map->getPropertiesForGID(gid);
    if (properties.getType() == Value::Type::MAP) {
        ValueMap propertiesMap = properties.asValueMap();
        auto walkableIter = propertiesMap.find("walkable");

        if (walkableIter != propertiesMap.end()) {
            std::string walkableStr = walkableIter->second.asString();
            bool walkable = (walkableStr == "true");
            if (walkable) {
                Character::Moving(sprite, 1, 0.5f);
                Endposition.y -= movelength;
                npc_1_d = 'b';
            }
            else {
                CCLOG("Cannot move: Target tile at (%f, %f) is not walkable.", targetTileCoord.x, targetTileCoord.y);
            }
        }
        else {
            CCLOG("No 'walkable' property. Moving anyway.");
            Character::Moving(sprite, 1, 0.5f);
            Endposition.y -= movelength;
            npc_1_d = 'b';
        }
    }
    else {
        CCLOG("No properties for GID %d. Moving anyway.", gid);
        Character::Moving(sprite, 1, 0.5f);
        Endposition.y -= movelength;
        npc_1_d = 'b';
    }
}
void NPC_1::moveDown(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize) {
    Vec2 currentPosition = Endposition;
    CCLOG("NPC Current screen position: (%f, %f)", currentPosition.x, currentPosition.y);
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
    CCLOG("NPC Screen coordinate: (%f, %f)", screenCoord.x, screenCoord.y);
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, map);

    if (tileCoord == Vec2(-1, -1)) {
        CCLOG("Current position is outside the map bounds.");
        return;
    }
    CCLOG("Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);

    Vec2 targetTileCoord = Vec2(tileCoord.x, tileCoord.y + 1); // 向下移动 y+1
    CCLOG("Target tile coordinate: (%f, %f)", targetTileCoord.x, targetTileCoord.y);

    TMXLayer* pathLayer = map->getLayer("path");
    if (!pathLayer) {
        CCLOG("Path layer not found!");
        return;
    }

    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    if (gid <= 0) {
        CCLOG("GID is invalid or no tile at (%f, %f). Moving anyway.", targetTileCoord.x, targetTileCoord.y);
        Character::Moving(sprite, 0, 0.5f);
        Endposition.y += movelength;
        npc_1_d = 'f';
        return;
    }

    Value properties = map->getPropertiesForGID(gid);
    if (properties.getType() == Value::Type::MAP) {
        ValueMap propertiesMap = properties.asValueMap();
        auto walkableIter = propertiesMap.find("walkable");

        if (walkableIter != propertiesMap.end()) {
            std::string walkableStr = walkableIter->second.asString();
            bool walkable = (walkableStr == "true");
            if (walkable) {
                Character::Moving(sprite, 0, 0.5f);
                Endposition.y += movelength;
                npc_1_d = 'f';
            }
            else {
                CCLOG("Cannot move: Target tile at (%f, %f) is not walkable.", targetTileCoord.x, targetTileCoord.y);
            }
        }
        else {
            CCLOG("No 'walkable' property. Moving anyway.");
            Character::Moving(sprite, 0, 0.5f);
            Endposition.y += movelength;
            npc_1_d = 'f';
        }
    }
    else {
        CCLOG("No properties for GID %d. Moving anyway.", gid);
        Character::Moving(sprite, 0, 0.5f);
        Endposition.y += movelength;
        npc_1_d = 'f';
    }
}
void NPC_1::moveLeft(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize) {
    Vec2 currentPosition = Endposition;
    CCLOG("NPC Current screen position: (%f, %f)", currentPosition.x, currentPosition.y);
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
    CCLOG("NPC Screen coordinate: (%f, %f)", screenCoord.x, screenCoord.y);
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, map);

    if (tileCoord == Vec2(-1, -1)) {
        CCLOG("Current position is outside the map bounds.");
        return;
    }
    CCLOG("Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);

    Vec2 targetTileCoord = Vec2(tileCoord.x - 1, tileCoord.y); // 向左移动 x-1
    CCLOG("Target tile coordinate: (%f, %f)", targetTileCoord.x, targetTileCoord.y);

    TMXLayer* pathLayer = map->getLayer("path");
    if (!pathLayer) {
        CCLOG("Path layer not found!");
        return;
    }

    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    if (gid <= 0) {
        CCLOG("GID is invalid or no tile at (%f, %f). Moving anyway.", targetTileCoord.x, targetTileCoord.y);
        Character::Moving(sprite, 2, 0.5f);
        Endposition.x -= movelength;
        npc_1_d = 'l';
        return;
    }

    Value properties = map->getPropertiesForGID(gid);
    if (properties.getType() == Value::Type::MAP) {
        ValueMap propertiesMap = properties.asValueMap();
        auto walkableIter = propertiesMap.find("walkable");

        if (walkableIter != propertiesMap.end()) {
            std::string walkableStr = walkableIter->second.asString();
            bool walkable = (walkableStr == "true");
            if (walkable) {
                Character::Moving(sprite, 2, 0.5f);
                Endposition.x -= movelength;
                npc_1_d = 'l';
            }
            else {
                CCLOG("Cannot move: Target tile at (%f, %f) is not walkable.", targetTileCoord.x, targetTileCoord.y);
            }
        }
        else {
            CCLOG("No 'walkable' property. Moving anyway.");
            Character::Moving(sprite, 2, 0.5f);
            Endposition.x -= movelength;
            npc_1_d = 'l';
        }
    }
    else {
        CCLOG("No properties for GID %d. Moving anyway.", gid);
        Character::Moving(sprite, 2, 0.5f);
        Endposition.x -= movelength;
        npc_1_d = 'l';
    }
}
void NPC_1::moveRight(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize) {
    Vec2 currentPosition = Endposition;
    CCLOG("NPC Current screen position: (%f, %f)", currentPosition.x, currentPosition.y);
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
    CCLOG("NPC Screen coordinate: (%f, %f)", screenCoord.x, screenCoord.y);
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, map);

    if (tileCoord == Vec2(-1, -1)) {
        CCLOG("Current position is outside the map bounds.");
        return;
    }
    CCLOG("Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);

    Vec2 targetTileCoord = Vec2(tileCoord.x + 1, tileCoord.y); // 向右移动 x+1
    CCLOG("Target tile coordinate: (%f, %f)", targetTileCoord.x, targetTileCoord.y);

    TMXLayer* pathLayer = map->getLayer("path");
    if (!pathLayer) {
        CCLOG("Path layer not found!");
        return;
    }

    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    if (gid <= 0) {
        CCLOG("GID is invalid or no tile at (%f, %f). Moving anyway.", targetTileCoord.x, targetTileCoord.y);
        Character::Moving(sprite, 3,0.5f);
        Endposition.x += movelength;
        npc_1_d = 'r';
        return;
    }

    Value properties = map->getPropertiesForGID(gid);
    if (properties.getType() == Value::Type::MAP) {
        ValueMap propertiesMap = properties.asValueMap();
        auto walkableIter = propertiesMap.find("walkable");

        if (walkableIter != propertiesMap.end()) {
            std::string walkableStr = walkableIter->second.asString();
            bool walkable = (walkableStr == "true");
            if (walkable) {
                Character::Moving(sprite, 3,0.5f);
                Endposition.x += movelength;
                npc_1_d = 'r';
            }
            else {
                CCLOG("Cannot move: Target tile at (%f, %f) is not walkable.", targetTileCoord.x, targetTileCoord.y);
            }
        }
        else {
            CCLOG("No 'walkable' property. Moving anyway.");
            Character::Moving(sprite, 3,0.5f);
            Endposition.x += movelength;
            npc_1_d = 'r';
        }
    }
    else {
        CCLOG("No properties for GID %d. Moving anyway.", gid);
        Character::Moving(sprite, 3,0.5f);
        Endposition.x += movelength;
        npc_1_d = 'r';
    }
}

NPC_1::NPC_1() {


    sprite = nullptr;

    keyboardListener = nullptr;
    scene = nullptr;
}

NPC_1::~NPC_1() {
    CC_SAFE_RELEASE_NULL(sprite);


    CC_SAFE_RELEASE_NULL(keyboardListener);
}

NPC_1* NPC_1::create() {
    NPC_1* npc = new NPC_1();
    if (npc && npc->init()) {
        npc->autorelease();
        return npc;
    }
    CC_SAFE_DELETE(npc);
    return nullptr;
}

void NPC_1::setup(const Size& visibleSize, Vec2 origin) {
    sprite = Sprite::create("resources/SYN/Abigailf1.png");
    sprite->setScale(Constants::kScale);
    if (sprite) {
        CCLOG("NPC_1 sprite loaded successfully");
    }
    else {
        CCLOG("Failed to load NPC_1 sprite image");
    }
    if (sprite) {
        Vec2 pos;
        pos.x = visibleSize.width / 2 - 8;
        pos.y = visibleSize.height / 2 - 8;
        position = pos;
        sprite->setPosition(position);
        this->addChild(sprite);
        CCLOG("Current screen position: (%f, %f)", pos.x, pos.y);
    }
}

bool isPlayerWithinScreen(const Vec2& position, const Vec2& direction, const Size& visibleSize, const TMXTiledMap* map, float scale) {
    // 计算缩放后的地图尺寸
    Size mapSize = map->getMapSize();
    Size tileSize = map->getTileSize();
    Size mapContentSize = Size(mapSize.width * tileSize.width, mapSize.height * tileSize.height) * scale;
    Vec2 currentPosition = position;
    Vec2 screenCoord = convertToScreenOrigin(currentPosition, visibleSize);
    // 计算人物移动后的目标位置
    Vec2 targetPosition = screenCoord + direction;

    // 检查目标位置是否仍在屏幕范围内
    if (targetPosition.x < 0 || targetPosition.x >= visibleSize.width ||
        targetPosition.y < 0 || targetPosition.y >= visibleSize.height) {
        CCLOG("Player will move out of the screen bounds. Movement blocked.");
        return false;
    }

    // 检查目标位置是否仍在地图范围内
    if (targetPosition.x < 0 || targetPosition.x >= mapContentSize.width ||
        targetPosition.y < 0 || targetPosition.y >= mapContentSize.height) {
        CCLOG("Player will move out of the map bounds. Movement blocked.");
        return false;
    }

    return true;
}



void NPC_1::checkAround(const Vec2& Endposition, TMXTiledMap* currentMap, MapControl* mapControl) {
    if (!currentMap) return;
    //Vec2 currentPosition = Endposition;
    Size visibleSize = Director::getInstance()->getVisibleSize(); 
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
   
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, currentMap);
    // 获取瓦片大小
    Size tileSize = currentMap->getTileSize();
    CCLOG("CkeckAr::Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);
    // 将人物坐标转换为瓦片坐标
    int playerTileX = tileCoord.x;
    int playerTileY = tileCoord.y;

    // 定义上下左右相邻瓦片的坐标
    Vec2 directions[] = {
        Vec2(0, 1),  // 上
        Vec2(0, -1), // 下
        Vec2(-1, 0), // 左
        Vec2(1, 0)   // 右
    };
   
    if (abs(playerTileX-3)<2 || abs(playerTileY - 5) < 2) {
        CCLOG("Switchto mine map");
        auto button = ui::Button::create("button_normal.png", "button_pressed.png");
        button->setTitleText("Switch mine  Map?");
        button->setTitleFontSize(24);
        button->setPosition(Vec2(600,400));
        button->retain();
        //this->addChild(button,2);
        //this->addChild(button, 2);
        g_sharedScene->addChild(button, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE+1);

        // 定时器移除按钮
        g_sharedScene->scheduleOnce([button](float) {
            if (button && button->getParent()) {
                CCLOG("Button removed after 3 seconds");
                button->removeFromParent();
            }
            button->release(); // 减少引用计数
            }, 1.0f, "removeButtonKey");

        // 按钮点击事件
        button->addClickEventListener([=](Ref* sender) {
            CCLOG("Press");

            TMXTiledMap* currentmap;
            TMXTiledMap* aimmap;
            if (g_sharedTMXcurrent == g_sharedTMXone) {
                aimmap= g_sharedTMXtwo;
            }
            else if (g_sharedTMXcurrent == g_sharedTMXtwo) {
                aimmap = g_sharedTMXone;
            }
            else {
                aimmap = g_sharedTMXone;
            }
            // 设置新地图的属性
            g_sharedTMXtwo ->setPosition(Vec2(0, 0)); // 设置地图起始位置为屏幕左下角
            g_sharedTMXtwo->setScale(currentMap->getScale()); // 保持和当前地图相同的缩放比例
           
            /*g_sharedTMXcurrent = g_sharedTMXtwo;*/
            // 添加到父节点中
            g_sharedTMXcurrent->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_BASIC);
            aimmap->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_SURFACE);
            g_sharedTMXcurrent = aimmap;
            button->removeFromParent();
            button->release(); // 减少引用计数
            g_sharedScene->unschedule("removeButtonKey"); // 取消定时器
            });
       
    }

    if (abs(playerTileX - 78) < 2 && abs(playerTileY - 9) < 2) {
        CCLOG("Switch map");
        auto button = ui::Button::create("button_normal.png", "button_pressed.png");
        button->setTitleText("Switch to forest Map?");
        button->setTitleFontSize(24);
        button->setPosition(Vec2(600, 400));
        button->retain();
        //this->addChild(button,2);
        //this->addChild(button, 2);
        g_sharedScene->addChild(button, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE + 1);

        // 定时器移除按钮
        g_sharedScene->scheduleOnce([button](float) {
            if (button && button->getParent()) {
                CCLOG("Button removed after 3 seconds");
                button->removeFromParent();
            }
            button->release(); // 减少引用计数
            }, 1.0f, "removeButtonKey");

        // 按钮点击事件
        button->addClickEventListener([=](Ref* sender) {
            CCLOG("Press");

            TMXTiledMap* currentmap;
            TMXTiledMap* aimmap;
            if (g_sharedTMXcurrent == g_sharedTMXone) {
                aimmap = g_sharedTMXthree;
            }
            else if (g_sharedTMXcurrent == g_sharedTMXthree) {
                aimmap = g_sharedTMXone;
            }
            else {
                aimmap = g_sharedTMXone;
            }
            // 设置新地图的属性
            g_sharedTMXtwo->setPosition(Vec2(0, 0)); // 设置地图起始位置为屏幕左下角
            g_sharedTMXtwo->setScale(currentMap->getScale()); // 保持和当前地图相同的缩放比例

            /*g_sharedTMXcurrent = g_sharedTMXtwo;*/
            // 添加到父节点中
            g_sharedTMXcurrent->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_BASIC);
            aimmap->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_SURFACE);
            g_sharedTMXcurrent = aimmap;
            button->removeFromParent();
            button->release(); // 减少引用计数
            g_sharedScene->unschedule("removeButtonKey"); // 取消定时器
            });

    }
    // 遍历上下左右的瓦片
    //for (const auto& direction : directions) {
    //    Vec2 targetTileCoord = Vec2(playerTileX, playerTileY) + direction;

    //    // 检查目标瓦片是否在地图范围内
    //    if (targetTileCoord.x < 0 || targetTileCoord.y < 0 ||
    //        targetTileCoord.x >= currentMap->getMapSize().width ||
    //        targetTileCoord.y >= currentMap->getMapSize().height) {
    //        continue;
    //    }

    //    // 获取目标瓦片的 GID
    //    TMXLayer* pathLayer = currentMap->getLayer("trigger"); // 替换为触发层名称
    //    if (!pathLayer) {
    //        CCLOG("Trigger layer not found!");
    //        continue;
    //    }

    //    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    //    if (gid <= 0) continue;

    //    // 获取目标瓦片的属性
    //    Value properties = currentMap->getPropertiesForGID(gid);
    //    if (properties.getType() == Value::Type::MAP) {
    //        ValueMap propertiesMap = properties.asValueMap();
    //        auto targetMapIter = propertiesMap.find("targetMap");
    //        auto spawnXIter = propertiesMap.find("spawnX");
    //        auto spawnYIter = propertiesMap.find("spawnY");

    //        if (targetMapIter != propertiesMap.end() &&
    //            spawnXIter != propertiesMap.end() &&
    //            spawnYIter != propertiesMap.end()) {
    //            // 显示按钮询问玩家是否切换地图
                //auto button = ui::Button::create("button_normal.png", "button_pressed.png");
                //button->setTitleText("Switch Map?");
                //button->setTitleFontSize(24);
                //button->setPosition(playerSprite->getPosition() + Vec2(0, 50)); // 按钮显示在人物上方
                //parent->addChild(button);

                //// 按钮点击事件
                //button->addClickEventListener([=](Ref* sender) {
                //    // 切换地图
                //    std::string targetMap = targetMapIter->second.asString();
                //    Vec2 spawnPoint(spawnXIter->second.asFloat(), spawnYIter->second.asFloat());
                //    mapControl->switchMap(targetMap, spawnPoint, playerSprite);

                //    // 移除按钮
                //    button->removeFromParent();
                //    });

    //            return; // 找到一个符合条件的瓦片，结束检查
    //        }
    //    }
    //}

    CCLOG("No valid tile found around the player.");
}

Point Endposition;
Vec2 WindowCoord_1= convertToScreenOrigin(Endposition, Director::getInstance()->getVisibleSize());
char npc_1_d = 'f';
void NPC_1::movebyfour(NPC_1* P, TMXTiledMap* map) {
    keyboardListener = EventListenerKeyboard::create();
    float movelength = 16 * (Constants::kScale);
   
    if (keyboardListener) {
        Size visibleSize = Director::getInstance()->getVisibleSize(); // 获取屏幕可见尺寸
        keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            Vec2 currentPosition;
            Vec2 screenCoord;
            Vec2 direction;
            switch (keyCode) {
                case EventKeyboard::KeyCode::KEY_UP_ARROW:
                    direction = Vec2(0, movelength); // 向上移动
                    if (isPlayerWithinScreen(Endposition, direction, visibleSize, g_sharedTMXcurrent, g_sharedTMXcurrent->getScale())) {
                        moveUp(Endposition, g_sharedTMXcurrent, movelength, sprite, npc_1_d, visibleSize);
                    } 
                    checkAround(Endposition, g_sharedTMXcurrent, mapControl);
                    break;

                case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
                    direction = Vec2(0, -movelength); // 向下移动
                    if (isPlayerWithinScreen(Endposition, direction, visibleSize, g_sharedTMXcurrent, g_sharedTMXcurrent->getScale())) {
                        moveDown(Endposition, g_sharedTMXcurrent, movelength, sprite, npc_1_d, visibleSize);
                    } 
                    checkAround(Endposition, g_sharedTMXcurrent, mapControl);
                    break;

                case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                    direction = Vec2(-movelength, 0); // 向左移动
                    if (isPlayerWithinScreen(Endposition, direction, visibleSize, g_sharedTMXcurrent, g_sharedTMXcurrent->getScale())) {
                        moveLeft(Endposition, g_sharedTMXcurrent, movelength, sprite, npc_1_d, visibleSize);
                    } 
                    checkAround(Endposition, g_sharedTMXcurrent, mapControl);
                    break;

                case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                    direction = Vec2(movelength, 0); // 向右移动
                    if (isPlayerWithinScreen(Endposition, direction, visibleSize, g_sharedTMXcurrent, g_sharedTMXcurrent->getScale())) {
                        moveRight(Endposition, g_sharedTMXcurrent, movelength, sprite, npc_1_d, visibleSize);
                    } 
                    checkAround(Endposition, g_sharedTMXcurrent, mapControl);
                    break;

                default:
                    break;
            }
            };


        Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keyboardListener, 1);


    }
   
   
}


void NPC_1::testAddNPC_1(const Size& visibleSize, Vec2 origin, TMXTiledMap* map, Scene* mainscene) {
    // 创建NPC_1对象实例
    auto myNpc = NPC_1::create();
    myNpc->setVisible(true);
    this->addChild(myNpc);
    myNpc->setup(visibleSize, origin);
    myNpc->movebyfour(myNpc,map);
    
    if (!mainscene) {
        CCLOG("MainScene pointer is null!");
        return;
    }

    this->scene = mainscene;

}

cocos2d::Vec2 NPC_1::getPosition() {
    return Endposition;
}

char NPC_1::getDirection() {
    return npc_1_d;
}


bool NPC_1::isNear3(std::string name) {
    
    Vec2 screenCoord = convertToScreenOrigin(Endposition, Director::getInstance()->getVisibleSize());
    Size visibleSize = Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 diff;
    if (name== "Harvey") {
        cocos2d::Vec2 Harveyinmap;
        Harveyinmap.x = Constants::Harveyinmap_X;
        Harveyinmap.y = Constants::Harveyinmap_Y;
         diff = screenCoord - Harveyinmap;
    }
    else if (name == "Haley") {
        cocos2d::Vec2 Haleyinmap;
        Haleyinmap.x = Constants::Haleyinmap_X;
        Haleyinmap.y = Constants::Haleyinmap_Y;
         diff = screenCoord - Haleyinmap;
    }
    else{
        CCLOG("wrong character");
    }
    float distance = diff.length();
    return distance <= Constants::InteractionDistance;
}