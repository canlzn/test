//#include "PlantingSystem.h"
//#include "Land.h"
//using namespace cocos2d;
//// 初始化
//bool PlantingSystem::init() {
//    if (!Node::init()) {//调用基类 Node 的 init 方法。如果基类的初始化失败（返回 false），则当前对象的初始化也被视为失败。
//        return false;
//    }
//
//    // 每帧更新
//    schedule([this](float delta) { update(delta); }, "update_key");//使用 Cocos2d-x 的调度机制每帧调用 update 方法。
//
//    return true;
//}
//// 种植作物
//bool PlantingSystem::plantCrop(const std::string& cropName, float growthTime, const std::string& spriteFile, const Vec2& position) {
//
//    Crop* crop = Crop::create(cropName, growthTime, spriteFile);
//    if (crop) {
//        crop->setPosition(position);
//        crops.push_back(crop);
//        this->addChild(crop);
//        return true; // 成功种植
//    }
//    return false; // 种植失败
//}
//
//void PlantingSystem::update(float deltaTime) {
//    // 更新所有作物状态
//    for (Crop* crop : crops) {
//        crop->update(deltaTime);
//    }
//}
//
