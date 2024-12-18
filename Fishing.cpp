#include "Fishing.h"
#include "MainScene.h"  // 引用MainScene，以便调用MainScene中的方法
#include "back.h"
#include"backPhoto.h"

extern backPack* pack1;
// 构造函数
FishingLayer::FishingLayer()
    : m_progressBar(nullptr), m_infoLabel(nullptr), m_startButton(nullptr),
    m_isFishingInProgress(false), m_fishingProgress(0) {}

// 析构函数
FishingLayer::~FishingLayer() {}

// 创建 FishingLayer 实例
FishingLayer* FishingLayer::createLayer()
{
    FishingLayer* layer = new FishingLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

// 初始化 FishingLayer
bool FishingLayer::init()
{
    if (!Layer::init()) {
        return false;
    }


    // 初始化进度条
    m_progressBar = ProgressTimer::create(Sprite::create("fishingloading.png"));
    m_progressBar->setType(ProgressTimer::Type::BAR);
    m_progressBar->setBarChangeRate(Vec2(1, 0));  // 水平条
    m_progressBar->setMidpoint(Vec2(0, 0));
    m_progressBar->setPosition(Vec2(32,
                                    64));
    m_progressBar->setPercentage(0);
    this->addChild(m_progressBar);

    // 创建钓鱼按钮
    m_startButton = MenuItemImage::create("fishing.png", "fishing.png",
                                          CC_CALLBACK_1(FishingLayer::onFishingButtonClicked, this));
    m_startButton->setPosition(Vec2(32,
                                    32));

    // 创建菜单
    Menu* menu = Menu::create(m_startButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    return true;
}

// 按钮点击事件：开始钓鱼
void FishingLayer::onFishingButtonClicked(Ref* sender)
{
    if (!m_isFishingInProgress) {
        startFishing();
    }
}

// 启动钓鱼过程
void FishingLayer::startFishing()
{
    m_isFishingInProgress = true;
    m_fishingProgress = 0;
    m_progressBar->setPercentage(m_fishingProgress);

    // 启动一个定时器，定期更新进度条
    schedule([this](float dt) {
        updateProgressBar(dt);
    }, 0.1f, "fishing_update_key");
}

// 更新进度条
void FishingLayer::updateProgressBar(float dt)
{
    if (m_isFishingInProgress)
    {
        m_fishingProgress += 2.0f;  // 每次更新进度条
        m_progressBar->setPercentage(m_fishingProgress);

        if (m_fishingProgress >= 100.0f)
        {
            unschedule("fishing_update_key");
            onFishCaught();
        }
    }
}

// 钓鱼成功后的处理
void FishingLayer::onFishCaught()
{
    m_isFishingInProgress = false;
    Item* item0 = Fish::create("sunfish");
    pack1->itemAdd(item0, 1);
    // 删除进度条和按钮
    this->removeChild(m_progressBar);
    this->removeChild(m_startButton);
}

// 钓鱼失败后的处理
void FishingLayer::onFishMissed()
{
    m_isFishingInProgress = false;
    // 删除进度条和按钮
    this->removeChild(m_progressBar);
    this->removeChild(m_startButton);
}

