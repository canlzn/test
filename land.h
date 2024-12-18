#ifndef __LAND_H__
#define __LAND_H__

#include "cocos2d.h"

class Land:public cocos2d::Sprite {
public:
    static float tileSize; //用于动态调整大小
    // 土地的状态
    enum class State {
        Empty,     // 空地
        Planted,   // 已种植
        Watered,   // 已浇水
        Harvested  // 可收获
    };

    State state = State::Empty; // 默认状态为空地

    // 创建方法
    static Land* create(const std::string& filename);

    // 土地交互逻辑
    void interact();
    //void adjustScale();
};

#endif // __LAND_H__
