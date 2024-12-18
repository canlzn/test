/****************************************************************
 * Project Name: xinglugu-project
 * File:GamescenePlayer.h
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#ifndef GAMESCENEPLAYER_H
#define GAMESCENEPLAYER_H


#include "cocos2d.h"
#include "NPC.h"
class Player;
class NPC;


class GameScene : public cocos2d::Scene {
public:
    // 获取游戏场景单例实例
    static GameScene* getInstance();

    // 销毁游戏场景单例实例
    static void destroyInstance();
    static GameScene* getCurrentGameScene();

    // 添加玩家对象到游戏场景中的函数
    void addPlayer(Player* player);
    std::vector<Player*>& getAllPlayers();
    void addNPC(NPC* npc);
    std::vector<NPC*>& getAllNPCs();

private:
    // 存储单例实例的静态指针
    static GameScene* instance ;

    
    std::vector<Player*> players;
    std::vector<NPC*> npcs;
    
    GameScene();
    virtual ~GameScene();

    // 禁止拷贝构造和赋值操作，确保单例的唯一性
    GameScene(const GameScene&) = delete;
    GameScene& operator=(const GameScene&) = delete;
};

#endif