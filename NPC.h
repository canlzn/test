/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC.h
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#ifndef NPC_H
#define NPC_H


#include "Character.h"

#include "GameScenePlayer.h"
#include "ui/CocosGUI.h"
#include <vector>



// NPC类，继承自角色类
class NPC : public Character {
public:
    NPC();
    virtual ~NPC();
   
    NPC(const std::string& name, int health);
   
    // NPC提供对话内容的方法
    std::string getDialogue();

private:
   
    bool isPlayerInRange;
   
    
    std::string dialogueText;  // 记录对话内容的字符串变量

    // 使用结构体来表示一个任务的各项属性
    struct QuestInfo {
        std::string name;  // 任务名称
        std::string description;  // 任务描述
        int difficulty;  // 任务难度等级
        bool completed;  // 任务是否已完成，可用于记录任务状态
    };
    std::vector<QuestInfo> quests;

};

#endif

