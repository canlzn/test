#ifndef MAPCONTROL_H
#define MAPCONTROL_H

#include "cocos2d.h"
#include <vector>
#include "SceneTouch.h"
#include "Constants.h"
#include "WalkingCharacter.h"


using namespace cocos2d;

// 地图控制类
class MapControl {
public:
    // 构造函数
    MapControl(Node* parent, float mapScale, const std::vector<std::string>& mapFiles);

    // 切换地图
    void switchMap(size_t mapIndex, const Vec2& spawnPoint);

    // 保存当前地图状态
    void saveCurrentMapState();

    // 恢复地图状态
    void restoreMapState(size_t mapIndex);

    // 检查人物是否在屏幕范围内
    bool isPlayerWithinScreen(const Vec2& position, const Vec2& direction, const Size& visibleSize);

    // 获取当前地图
    TMXTiledMap* getCurrentMap() const;

private:
    TMXTiledMap* currentMap; // 当前地图
    std::vector<TMXTiledMap*> maps; // 储存所有地图指针
    size_t currentMapIndex; // 当前地图索引
    Node* parentNode; // 父节点
    float mapScale; // 地图缩放比例
};

#endif // MAPCONTROL_H