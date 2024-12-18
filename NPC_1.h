/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC_1.h
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.11
 * License:
 ****************************************************************/
#ifndef NPC_1_H
#define NPC_1_H

#include "SceneTouch.h"
#include "NPC.h"
#include "NPC_3.h"
#include "cocos2d.h"
#include "MapControl.h"

USING_NS_CC;
class NPC_2;
class NPC_3;
class NPC_1 : public NPC {
public:

    NPC_1();
    virtual ~NPC_1();

    void setup(const Size& visibleSize, Vec2 origin);
    static NPC_1* create();
    void movebyfour(NPC_1* P, TMXTiledMap* map);
    cocos2d::Vec2 getPosition();
    char getDirection();

    void moveUp(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize);
    void moveDown(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize);
    void moveLeft(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize);
    void moveRight(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize);
    void checkAround(const Vec2& Endposition, TMXTiledMap* currentMap, MapControl* mapControl);
    MapControl* mapControl;
    Sprite* sprite;
   
   static bool isNear3(std::string);  // ÅÐ¶ÏÊÇ·ñ¿¿½ü NPC3
    void testAddNPC_1(const Size& visibleSize, Vec2 origin, TMXTiledMap* map, Scene* scene);
    Vec2 mapposition;
private:
    Scene* scene;
    Vec2 position;
    EventListenerKeyboard* keyboardListener;
};

#endif // NPC_1_H