/****************************************************************
 * Project Name: xinglugu-project
 * File SceneTouch.cpp
 * File Function: Handle touch events to access tile properties.
 * Author: Gao Wenhao
 * Update Date: 2024.12.9
 * License:
 ****************************************************************/

#include "SceneTouch.h"
#include "cocos2d.h"

using namespace cocos2d;

void replaceTileinMine(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName);

void replaceTileWithLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName);

void cultivateLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName);

void waterLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName);

Vec2 calculateTileCoordinate(const Vec2& touchLocation, TMXTiledMap* map) {
    // 获取地图的起始位置
    CCLOG(" calculateTileCoordinate::Current screen position: (%f, %f)", touchLocation.x, touchLocation.y);
    Vec2 mapStartPosition = map->getPosition();

    // 地图的缩放比例
    float mapScale = map->getScale();

    // 获取地图瓦片大小和地图尺寸
    Size tileSize = map->getTileSize();
    Size mapSize = map->getMapSize();

    // 计算瓦片大小的实际渲染尺寸（考虑缩放比例）
    float adjustedTileWidth = tileSize.width * mapScale;
    float adjustedTileHeight = tileSize.height * mapScale;

    // 将触摸点从屏幕坐标转换为相对于地图的坐标
    Vec2 mapLocation = touchLocation - mapStartPosition;

    // 确保触摸点在地图范围内
    if (mapLocation.x < 0 || mapLocation.y < 0 ||
        mapLocation.x >= mapSize.width * adjustedTileWidth ||
        mapLocation.y >= mapSize.height * adjustedTileHeight) {
        CCLOG("Touch location is outside the map.");
        return Vec2(-1, -1); // 返回非法坐标
    }

    // 计算触摸点所在的瓦片坐标
    int tileX = static_cast<int>(mapLocation.x / adjustedTileWidth);
    int tileY = static_cast<int>((mapSize.height * adjustedTileHeight - mapLocation.y) / adjustedTileHeight);

    CCLOG(" calculateTileCoordinate::Tile coordinates: (%d, %d)", tileX, tileY);
    return Vec2(tileX, tileY);
}

//bool onTouchBegan(Touch* touch, Event* event, cocos2d::TMXTiledMap* map, backPack* pack) {
//  
//    Vec2 touchLocation = touch->getLocation();
//
//    // 使用封装的函数计算瓦片坐标
//    Vec2 tileCoord = calculateTileCoordinate(touchLocation, map);
//
//    // 检查是否返回了非法坐标
//    if (tileCoord == Vec2(-1, -1)) {
//        CCLOG("Touch is outside the map bounds.");
//        return false;
//    }
//
//    // 继续处理瓦片相关的逻辑
//    int tileX = tileCoord.x;
//    int tileY = tileCoord.y;
//
//    // 先检查点击事件是否发生在path层（场景交互对象层）
//    TMXLayer* layer = g_sharedTMXcurrent->getLayer("path"); // 替换为你的图层名
//    if (!layer) {
//        CCLOG("Layer not found!");
//        return false;
//    }
//    
//    int gid = layer->getTileGIDAt(Vec2(tileX, tileY));
//    if (gid <= 0) {
//        CCLOG("No tile at this location.");
//        return false;
//    }
//    CCLOG("GID %d",gid );
//    // 输出瓦片属性
//   
//    Value propertiesValue = g_sharedTMXcurrent->getPropertiesForGID(gid);
//  
//    if (propertiesValue.getType() == Value::Type::MAP) {
//        ValueMap properties = propertiesValue.asValueMap();
//
//        // 遍历属性并打印调试信息
//        for (const auto& property : properties) {
//            CCLOG("Property key: %s, value: %s", property.first.c_str(), property.second.asString().c_str());
//        }
//
//        // 获取 type 属性
//        auto typeIter = properties.find("type");
//        if (typeIter != properties.end() && typeIter->second.getType() == Value::Type::STRING) {
//            std::string type = typeIter->second.asString();
//
//            // 获取 walkable 属性 (如果需要可以添加额外逻辑，当前示例中未用到)
//            //auto walkableIter = properties.find("walkable");
//            //bool walkable = false; // 默认值
//            //if (walkableIter != properties.end() && walkableIter->second.getType() == Value::Type::BOOLEAN) {
//            //    walkable = walkableIter->second.asBool();
//            //}
//
//            // 判断工具和 type 类型
//            std::string currentTool = pack->handInItemOut(); // 获取当前工具
//            if (type == "stone" && currentTool == "pickaxe") {
//                CCLOG("Breaking stone with pickaxe");
//                replaceTileWithLand(tileCoord, map, "grb");
//
//                // 向背包添加物品
//                return true;
//            }
//            else if (type == "branch" && currentTool == "axe") {
//                CCLOG("Chopping branch with axe");
//                replaceTileWithLand(tileCoord, map, "grb");
//                // 向背包添加物品
//                return true;
//            }
//            else if (type == "grass" && currentTool == "sickle") {
//                CCLOG("Cutting grass with sickle");
//                replaceTileWithLand(tileCoord, map, "grb");
//                // 向背包添加物品
//                return true;
//            }
//            else if (type == "empty" && currentTool == "hoe") {
//                cultivateLand(tileCoord, map, "landmateri");
//                CCLOG("The object has been moved");
//                return true;
//               
//            }
//            else {
//                CCLOG("Tool does not match type or no valid type found");
//                if (type != "empty") {
//                    return true;
//                }
//            }
//        }
//        else {
//            CCLOG("No valid 'type' property found or type is not a string");
//        }
//    }
//    else {
//        CCLOG("Properties for GID %d are not of type MAP or do not exist", gid);
//    }
//   
//    // 在检查点击事件是否发生在土地层
//    layer = g_sharedTMXcurrent->getLayer("farmland");
//    if (!layer) {
//        CCLOG("Layer farm land not found!");
//        return false;
//    }
//    std::string currentTool = pack->handInItemOut(); // 获取当前工具
//    gid = layer->getTileGIDAt(Vec2(tileX, tileY));
//
//    if (gid <= 0) {
//        CCLOG("No tile at this location.");
//        if (currentTool == "hoe") {
//            cultivateLand(tileCoord, g_sharedTMXcurrent, "landmateri");
//            CCLOG("cultivate the Land");
//        }
//        return false;
//    }
//   
//    Value propertiesValuetwo = g_sharedTMXcurrent->getPropertiesForGID(gid);
//    // 确保属性存在并且是 ValueMap 类型
//    if (propertiesValuetwo.getType() == Value::Type::MAP) {
//        ValueMap properties = propertiesValuetwo.asValueMap();
//
//        // 遍历属性并打印调试信息
//        for (const auto& property : properties) {
//            CCLOG("Property key: %s, value: %s", property.first.c_str(), property.second.asString().c_str());
//        }
//
//        // 获取 type 属性
//        auto typeIter = properties.find("type");
//        if (typeIter != properties.end() && typeIter->second.getType() == Value::Type::STRING) {
//            std::string type = typeIter->second.asString();
//            // 判断工具和 type 类型
//            //std::string currentTool = pack->handInItemOut(); // 获取当前工具
//            if (type == "farm_land_unwater" && currentTool == "wateringcan") {
//                CCLOG("Watering land");
//                waterLand(tileCoord, g_sharedTMXcurrent, "landmateri");
//                return true;
//            }
//            else if (currentTool == "hoe") {
//                cultivateLand(tileCoord, g_sharedTMXcurrent, "landmateri");
//                return true;
//                CCLOG("cultivate the Land");
//            }
//            else {
//                CCLOG("Tool does not match type or no valid type found");
//            }
//        }
//
//    }
//    else {
//        CCLOG("Properties for GID %d are not of type MAP or do not exist", gid);      
//    }
//
//
//    return true;
//}

bool checkPathLayerInteraction(Vec2 tileCoord, cocos2d::TMXTiledMap* map, backPack* pack) {
    TMXLayer* pathLayer = map->getLayer("path");
    if (!pathLayer) {
        CCLOG("Path layer not found!");
        return false;
    }

    int gid = pathLayer->getTileGIDAt(tileCoord);
    if (gid <= 0) {
        CCLOG("No tile at this location in path layer.");
        return false;
    }

    Value propertiesValue = map->getPropertiesForGID(gid);
    if (propertiesValue.getType() == Value::Type::MAP) {
        ValueMap properties = propertiesValue.asValueMap();

        auto typeIter = properties.find("type");
        if (typeIter != properties.end() && typeIter->second.getType() == Value::Type::STRING) {
            std::string type = typeIter->second.asString();
            std::string currentTool = pack->handInItemOut();

            if (currentTool == "pickaxe") {
                if (type == "stone") {
                    CCLOG("Breaking %s with pickaxe", type.c_str());
                    replaceTileWithLand(tileCoord, map, "grb"); // 替换为石头地块
                    Item* newitem = terial::create("stone");
                    if (newitem) {
                        pack->itemAdd(newitem, 2);
                    }
                    else {
                        CCLOG("Fail to create the item");
                    }
                    return true;
                }
                else if (type == "iron") {
                    CCLOG("Breaking %s with pickaxe", type.c_str());
                    replaceTileinMine(tileCoord, map, "source");
                    Item* newitem = terial::create("ironore");
                    if (newitem) {
                        pack->itemAdd(newitem, 1);
                    }
                    else {
                        CCLOG("Fail to create the item");
                    }
                    return true;
                }
                else if (type == "copper") {
                    CCLOG("Breaking %s with pickaxe", type.c_str());
                    replaceTileinMine(tileCoord, map, "source");
                    Item* newitem = terial::create("copperbar");
                    if (newitem) {
                        pack->itemAdd(newitem, 1);
                    }
                    else {
                        CCLOG("Fail to create the item");
                    }
                    return true;
                }
                else if (type == "gold") {
                    CCLOG("Breaking %s with pickaxe", type.c_str());
                    replaceTileinMine(tileCoord, map, "source");
                    Item* newitem = terial::create("ironbar");
                    if (newitem) {
                        pack->itemAdd(newitem, 1);
                    }
                    else {
                        CCLOG("Fail to create the item");
                    }

                    return true;
                }
            }
            else if (type == "branch" && currentTool == "axe") {
                CCLOG("Chopping branch with axe");
                replaceTileWithLand(tileCoord, map, "grb");
                Item* newitem = terial::create("wood");
                if (newitem) {
                    pack->itemAdd(newitem, 1);
                }
                else {
                    CCLOG("Fail to create the item");
                }
                return true;
            }
            else if (type == "grass" && currentTool == "sickle") {
                CCLOG("Cutting grass with sickle");
                replaceTileWithLand(tileCoord, map, "grb");
                Item* newitem = Seed::create("parsnipseed");
                if (newitem) {
                    pack->itemAdd(newitem, 1);
                }
                else {
                    CCLOG("Fail to create the item");
                }
                return true;
            }
            else if (type == "empty" && currentTool == "hoe") {
                cultivateLand(tileCoord, map, "landmateri");
                CCLOG("The object has been moved");
                return true;
            }
            else {
                CCLOG("Tool does not match type or no valid type found");
                return false;
            }
        }
    }

    CCLOG("No valid 'type' property found or type is not a string in path layer.");
    return false;
}

bool checkFarmlandLayerInteraction(Vec2 tileCoord, cocos2d::TMXTiledMap* map, backPack* pack) {
    TMXLayer* farmlandLayer = map->getLayer("farmland");
    if (!farmlandLayer) {
        CCLOG("Farmland layer not found!");
        return false;
    }

    int gid = farmlandLayer->getTileGIDAt(tileCoord);
    if (gid <= 0) {
        std::string currentTool = pack->handInItemOut();
        if (currentTool == "hoe") {
            cultivateLand(tileCoord, map, "landmateri");
            CCLOG("Cultivating the land.");
        }
        return false;
    }

    Value propertiesValue = map->getPropertiesForGID(gid);
    if (propertiesValue.getType() == Value::Type::MAP) {
        ValueMap properties = propertiesValue.asValueMap();

        auto typeIter = properties.find("type");
        if (typeIter != properties.end() && typeIter->second.getType() == Value::Type::STRING) {
            std::string type = typeIter->second.asString();
            std::string currentTool = pack->handInItemOut();

            if (type == "farm_land_unwater" && currentTool == "wateringcan") {
                CCLOG("Watering land");
                waterLand(tileCoord, map, "landmateri");
                return true;
            }
            else if (currentTool == "hoe") {
                cultivateLand(tileCoord, map, "landmateri");
                CCLOG("Cultivating the land.");
                return true;
            }
            else {
                CCLOG("Tool does not match type or no valid type found in farmland layer.");
            }
        }
    }

    CCLOG("No valid 'type' property found or type is not a string in farmland layer.");
    return false;
}

bool onTouchBegan(Touch* touch, Event* event, cocos2d::TMXTiledMap* map, backPack* pack) {
    Vec2 touchLocation = touch->getLocation();

    // 使用封装的函数计算瓦片坐标
    Vec2 tileCoord = calculateTileCoordinate(touchLocation, g_sharedTMXcurrent);

    // 检查是否返回了非法坐标
    if (tileCoord == Vec2(-1, -1)) {
        CCLOG("Touch is outside the map bounds.");
        return false;
    }

    // 依次检查 Path 和 Farmland 层
    if (checkPathLayerInteraction(tileCoord, g_sharedTMXcurrent, pack)) {
        return true;
    }

    if (checkFarmlandLayerInteraction(tileCoord, g_sharedTMXcurrent, pack)) {
        return true;
    }

    CCLOG("No valid interaction found for the touched tile.");
    return false;
}

void replaceTileWithLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName) {
    // 获取要被替换的图层（固定为 "path"）
    Vec2 materialTileCoord(5, 0);
    auto targetLayer = map->getLayer("path");
    if (!targetLayer) {
        CCLOG("Layer 'path' not found!");
        return;
    }

    // 获取替换素材所在的图层
    auto materialLayer = map->getLayer(layerName);
    if (!materialLayer) {
        CCLOG("Layer '%s' not found!", layerName.c_str());
        return;
    }

    // 从素材图层中获取替换素材的 GID
    int materialGID = materialLayer->getTileGIDAt(materialTileCoord);
    if (materialGID == 0) {
        CCLOG("No tile found at (%d, %d) in layer '%s'",
            static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), layerName.c_str());
        return;
    }

    // 在目标图层中设置新的 GID
    targetLayer->setTileGID(materialGID, tileCoord);

    CCLOG("Replaced tile at (%d, %d) in 'path' layer with tile from '%s' layer at (%d, %d), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), materialGID);

    targetLayer->setTileGID(materialGID, tileCoord);

    // 获取目标图层中对应位置的 Sprite
    auto tileSprite = targetLayer->getTileAt(tileCoord);
    if (tileSprite) {
        // 设置透明度为 0
        tileSprite->setOpacity(0);
        CCLOG("Set opacity of tile at (%d, %d) to 0.",
            static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
    }
    else {
        CCLOG("No sprite found at (%d, %d) in 'path' layer.",
            static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
    }

    CCLOG("Replaced tile at (%d, %d) in 'path' layer with tile from '%s' layer at (%d, %d), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), materialGID);
}

void replaceTileinMine(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName) {
    // 获取要被替换的图层（固定为 "path"）
    Vec2 materialTileCoord(4, 0);
    auto targetLayer = map->getLayer("path");
    if (!targetLayer) {
        CCLOG("Layer 'path' not found!");
        return;
    }

    // 获取替换素材所在的图层
    auto materialLayer = map->getLayer(layerName);
    if (!materialLayer) {
        CCLOG("Layer '%s' not found!", layerName.c_str());
        return;
    }

    // 从素材图层中获取替换素材的 GID
    int materialGID = materialLayer->getTileGIDAt(materialTileCoord);
    if (materialGID == 0) {
        CCLOG("No tile found at (%d, %d) in layer '%s'",
            static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), layerName.c_str());
        return;
    }

    // 在目标图层中设置新的 GID
    targetLayer->setTileGID(materialGID, tileCoord);

    CCLOG("Replaced tile at (%d, %d) in 'path' layer with tile from '%s' layer at (%d, %d), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), materialGID);

    targetLayer->setTileGID(materialGID, tileCoord);

    // 获取目标图层中对应位置的 Sprite
    auto tileSprite = targetLayer->getTileAt(tileCoord);
    if (tileSprite) {
        // 设置透明度为 0
        tileSprite->setOpacity(0);
        CCLOG("Set opacity of tile at (%d, %d) to 0.",
            static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
    }
    else {
        CCLOG("No sprite found at (%d, %d) in 'path' layer.",
            static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
    }

    CCLOG("Replaced tile at (%d, %d) in 'path' layer with tile from '%s' layer at (%d, %d), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), materialGID);
}


void cultivateLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName) {

    auto targetLayer = map->getLayer("farmland");
    if (!targetLayer) {
        CCLOG("Layer 'farmland' not found!");
        return;
    }

    // 获取素材图层
    auto materialLayer = map->getLayer(layerName);
    if (!materialLayer) {
        CCLOG("Layer '%s' not found!", layerName.c_str());
        return;
    }

    // 从素材图层中获取 (0, 0) 的 GID
    Vec2 materialTileCoord(0, 0);
    int materialGID = materialLayer->getTileGIDAt(materialTileCoord);
    if (materialGID == 0) {
        CCLOG("No tile found at (%d, %d) in layer '%s'",
            static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), layerName.c_str());
        return;
    }

    // 在目标图层中设置新的 GID
    targetLayer->setTileGID(materialGID, tileCoord);

    CCLOG("Cultivated land at (%d, %d) in 'path' layer with tile from '%s' layer at (0, 0), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), materialGID);
}

void waterLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName) {

    auto targetLayer = map->getLayer("farmland");
    if (!targetLayer) {
        CCLOG("Layer 'farmland' not found!");
        return;
    }

    // 获取素材图层
    auto materialLayer = map->getLayer(layerName);
    if (!materialLayer) {
        CCLOG("Layer '%s' not found!", layerName.c_str());
        return;
    }

    // 从素材图层中获取 (0, 0) 的 GID
    Vec2 materialTileCoord(1, 0);
    int materialGID = materialLayer->getTileGIDAt(materialTileCoord);
    if (materialGID == 0) {
        CCLOG("No tile found at (%d, %d) in layer '%s'",
            static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), layerName.c_str());
        return;
    }

    // 在目标图层中设置新的 GID
    targetLayer->setTileGID(materialGID, tileCoord);

    CCLOG("Water land at (%d, %d) in 'path' layer with tile from '%s' layer at (0, 0), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), materialGID);
}
