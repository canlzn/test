#include "Land.h"
USING_NS_CC;

// 创建土地对象
Land* Land::create(const std::string& filename) {
    Land* land = new (std::nothrow) Land();
    if (land && land->initWithFile(filename)) {
        land->autorelease();
        return land;
    }
    CC_SAFE_DELETE(land);
    return nullptr;
}

// 土地的交互逻辑
void Land::interact() {
    switch (state) {
        case State::Empty:
            state = State::Planted;
            this->setTexture("land_planted.png");
            //adjustScale();  // 调整缩放比例
            break;
        case State::Planted:
            state = State::Watered;
            this->setTexture("land_watered.png");
            //adjustScale();  // 调整缩放比例
            break;
        case State::Watered:
            state = State::Harvested;
            this->setTexture("land_empty.png");
            //adjustScale();  // 调整缩放比例
            break;
        case State::Harvested:
            state = State::Empty;
            // 不需要更改纹理时不调用 adjustScale
            break;
    }
}
//void Land::adjustScale() {
//    auto textureSize = this->getContentSize();
//    float scaleX = tileSize / textureSize.width;
//    float scaleY = tileSize / textureSize.height;
//    this->setScaleX(scaleX);
//    this->setScaleY(scaleY);
//}