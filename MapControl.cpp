#include "MapControl.h"

MapControl::MapControl(Node* parent, float scale, const std::vector<std::string>& mapFiles)
    : parentNode(parent), mapScale(scale), currentMap(nullptr), currentMapIndex(0) {
    // 初始化地图
    for (const auto& mapFile : mapFiles) {
        TMXTiledMap* newMap = TMXTiledMap::create(mapFile);
        if (!newMap) {
            CCLOG("Failed to load map: %s", mapFile.c_str());
            continue;
        }
        //newMap->setScale(mapScale);
        newMap->setVisible(false); // 默认隐藏
        parentNode->addChild(newMap, 0);
        maps.push_back(newMap);
    }

    // 设置初始地图
    if (!maps.empty()) {
        currentMap = maps[0];
        currentMap->setVisible(true);
        currentMapIndex = 0;
        CCLOG("Initialized MapControl with %zu maps", maps.size());
    }
}

void MapControl::switchMap(size_t mapIndex, const Vec2& spawnPoint) {
    // 检查地图索引是否合法
    if (mapIndex >= maps.size()) {
        CCLOG("Invalid map index: %zu", mapIndex);
        return;
    }

    // 保存当前地图状态
    saveCurrentMapState();

    // 隐藏当前地图
    if (currentMap) {
        currentMap->setVisible(false);
    }

    // 切换到新地图
    currentMap = maps[mapIndex];
    currentMap->setVisible(true);
    currentMapIndex = mapIndex;

    // 恢复新地图状态
    restoreMapState(mapIndex);

    CCLOG("Switched to map index: %zu", mapIndex);
}

void MapControl::saveCurrentMapState() {
    if (!currentMap) return;

    // 此处可以扩展保存瓦片或其他状态的逻辑
    CCLOG("Saved current map state for map index: %zu", currentMapIndex);
}

void MapControl::restoreMapState(size_t mapIndex) {
    if (mapIndex >= maps.size()) {
        CCLOG("Invalid map index for restoring state: %zu", mapIndex);
        return;
    }

    // 此处可以扩展恢复瓦片或其他状态的逻辑
    CCLOG("Restored map state for map index: %zu", mapIndex);
}

bool MapControl::isPlayerWithinScreen(const Vec2& position, const Vec2& direction, const Size& visibleSize) {
    Vec2 targetPosition = position + direction;

    if (targetPosition.x < 0 || targetPosition.x > visibleSize.width ||
        targetPosition.y < 0 || targetPosition.y > visibleSize.height) {
        CCLOG("Player will move out of screen bounds.");
        return false;
    }

    return true;
}

TMXTiledMap* MapControl::getCurrentMap() const {
    return currentMap;
}