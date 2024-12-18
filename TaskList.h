#include "cocos2d.h"

// 任务结构体
struct Task {
    std::string taskDescription;  // 任务描述
    int targetItemCount;          // 目标收集物品数量
    std::string rewardDescription; // 任务奖励描述
    bool completed;               // 任务是否完成
};