//#include "Crop.h"
//
//using namespace cocos2d;
////构造函数
//Crop::Crop(const std::string& cropName, float growthTime, const std::string& spriteFile)
//    : name(cropName), growthTime(growthTime), currentTime(0.0f), state(State::SEED) {
//
//    sprite = Sprite::create(spriteFile);
//    if (sprite) {
//        this->addChild(sprite);
//    }
//}
//// 创建作物
//Crop* Crop::create(const std::string& cropName, float growthTime, const std::string& spriteFile) {
//    Crop* crop = new (std::nothrow) Crop(cropName, growthTime, spriteFile);
//    if (crop && crop->init()) {
//        crop->autorelease();//将 crop 的引用计数减少，将其添加到自动释放池中
//        return crop;
//    }
//    CC_SAFE_DELETE(crop);//如果 crop 创建失败或 init() 返回 false，安全地删除 crop 对象以释放内存
//    return nullptr;
//}
//
////更新作物生长时间，每秒调用一次
//void Crop::update(float deltaTime) {
//    if (state == State::GROWING) {//判断是否处于成长状态
//        currentTime += deltaTime;
//        if (currentTime >= growthTime) {
//            state = State::HARVESTABLE; // 成长完成
//        }
//    }
//}
//// 获取作物状态
//Crop::State Crop::getState() const {
//    return state;
//}
//// 获取作物名称
//const std::string& Crop::getName() const { 
//    return name; 
//}
//// 获取作物状态
//Crop::State Crop::getState() const {
//    return state;
//}
//// 获取作物名称
//const std::string& Crop::getName() const { 
//    return name; 
//}
