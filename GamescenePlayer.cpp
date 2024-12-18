/****************************************************************
 * Project Name: xinglugu-project
 * File:GamescenePlayer.cpp
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#include "GameScenePlayer.h"

GameScene* GameScene::instance = nullptr;
// 获取游戏场景单例实例
GameScene* GameScene::getInstance() {
    if (instance == nullptr) {
        cocos2d::Scene* tempScene = GameScene::create();  
        instance = dynamic_cast<GameScene*>(tempScene);
        if (instance == nullptr) {
            CCLOG("创建游戏场景实例失败或者类型转换错误");
        }
    }
    return instance;
}


GameScene* GameScene::getCurrentGameScene() {
    return getInstance();
}

// 销毁游戏场景单例
void GameScene::destroyInstance() {
    CC_SAFE_DELETE(instance);
    instance = nullptr;
}


GameScene::GameScene() {}

GameScene::~GameScene() {}

// 添加玩家对象到游戏场景中的函数实现，添加检查逻辑
void GameScene::addPlayer(Player* player) {
    if (player != nullptr) {
        players.push_back(player);
    }
    else {
        CCLOG("尝试添加空指针玩家对象，添加操作无效");
    }
}

// 获取游戏场景中所有玩家对象的函数实现，返回const引用防止外部误修改
 std::vector<Player*>& GameScene::getAllPlayers() {
    return players;
}

 void GameScene::addNPC(NPC* npc) {
     npcs.push_back(npc);
 }

 // 获取游戏场景中所有NPC对象的函数实现
 std::vector<NPC*>& GameScene::getAllNPCs() {
     return npcs;
 }